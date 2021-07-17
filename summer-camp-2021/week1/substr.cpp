#include <fstream> // ifstream, ofstream
#include <string>  // string
#include <cstring> // strlen
#include <map>     // map

using namespace std;

int main()
{
    int n;
    string str;
    ifstream fin("substr.in");
    fin >> n >> str;
    fin.close();

    size_t k;
    for (k = 1; k <= str.length(); k++)
    {
        bool isans = true;
        map<string, bool> used;
        for (size_t i = 0; i <= str.length() - k; i++)
        {
            string s = str.substr(i, k);
            if (used[s])
            {
                isans = false;
                break;
            }
            used[s] = true;
        }
        if (isans)
        {
            break;
        }
    }

    ofstream fout("substr.out");
    fout << k << endl;
    fout.close();

    return 0;
}
