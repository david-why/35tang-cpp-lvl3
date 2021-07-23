#include <fstream> // ifstream, ofstream

using namespace std;

int letters[26];

int main()
{
    ifstream fin("word.in");
    int n;
    fin >> n;

    for (int c = 0; c < n; c++)
    {
        char s[11];

        fin >> s;
        int need[26] = {0};
        for (char *it = s; *it; it++)
        {
            int c = *it - 'a';
            need[c]++;
            letters[c]++;
        }

        fin >> s;
        for (char *it = s; *it; it++)
        {
            int c = *it - 'a';
            if (need[c])
                need[c]--;
            else
                letters[c]++;
        }
    }

    fin.close();

    ofstream fout("word.out");
    for (int i = 0; i < 26; i++)
        fout << letters[i] << endl;
    fout.close();

    return 0;
}
