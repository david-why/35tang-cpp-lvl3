#include <fstream> // ifstream, ofstream
#include <string>  // string

using namespace std;

ifstream fin("brackets.in");
ofstream fout("brackets.out");

int counter, ans;

int main()
{
    string s;
    fin >> s;

    for (size_t i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (c == '(')
            counter++;
        else
            counter--;
        if (counter == -1)
        {
            ans++;
            counter = 1;
        }
    }

    fout << ans + counter / 2 << endl;

    return 0;
}
