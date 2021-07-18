#include <fstream> // ifstream, ofstream
#include <cstring> // strlen

#define maxn 100001

using namespace std;

int main()
{
    int n;
    char str[maxn];
    ifstream fin("substr.in");
    fin >> n >> str;
    fin.close();

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (str[i + k] != str[j + k])
                {
                    if (k > max)
                        max = k;
                    break;
                }
            }
        }
    }

    ofstream fout("substr.out");
    fout << max + 1 << endl;
    fout.close();

    return 0;
}
