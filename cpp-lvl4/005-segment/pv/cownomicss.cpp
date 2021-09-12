#include <bits/stdc++.h>

using namespace std;

ifstream fin("cownomics.in");
ofstream fout("cownomics.out");

char spots[500][51], nospots[500][51];

constexpr int c2i(char &c)
{
    return (c == 'A') ? 0 : ((c == 'T') ? 1 : (c == 'C') ? 2 : 3);
}

int main()
{
    int n, m;
    fin >> n >> m;
    for (int i = 0; i < n; i++)
        fin >> spots[i];
    for (int i = 0; i < n; i++)
        fin >> nospots[i];

    int ans = 0;
    for (int i1 = 0; i1 < m; i1++)
    {
        for (int i2 = i1 + 1; i2 < m; i2++)
        {
            for (int i3 = i2 + 1; i3 < m; i3++)
            {
                unsigned long long used = 0;
                bool isans = true;
                for (int i = 0; i < n; i++)
                {
                    char *s = spots[i];
                    used |= 1ULL << (c2i(s[i1]) + (c2i(s[i2]) << 2) + (c2i(s[i3]) << 4));
                }
                for (int i = 0; i < n; i++)
                {
                    char *s = nospots[i];
                    if (used & (1ULL << (c2i(s[i1]) + (c2i(s[i2]) << 2) + (c2i(s[i3]) << 4))))
                    {
                        isans = false;
                        break;
                    }
                }
                if (isans)
                    ans++;
            }
        }
    }

    fout << ans << endl;

    return 0;
}
