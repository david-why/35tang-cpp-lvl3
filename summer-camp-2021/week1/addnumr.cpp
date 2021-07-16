#include <fstream> // ifstream, ofstream
#include <cstring> // strlen

using namespace std;

int main()
{
    char a[5001], b[5001];
    ifstream fin("addnum.in");
    fin >> a >> b;
    fin.close();

    char *ptr_a = a + strlen(a) - 1;
    char *ptr_b = b + strlen(b) - 1;

    char out[5002];
    out[5001] = '\0';
    char *ptr_out = out + 5001;

    int carry = 0;
    while (ptr_a >= a || ptr_b >= b || carry)
    {
        char digit_a, digit_b, addsum;
        if (ptr_a < a)
            digit_a = '0';
        else
            digit_a = *(ptr_a--);
        if (ptr_b < b)
            digit_b = '0';
        else
            digit_b = *(ptr_b--);
        addsum = digit_a - '0' + digit_b + carry;
        if (addsum > '9')
        {
            addsum -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        *(--ptr_out) = addsum;
    }

    ofstream fout("addnum.out");
    fout << ptr_out << endl;
    fout.close();

    return 0;
}
