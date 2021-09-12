#include <bits/stdc++.h>

using namespace std;

ifstream fin("cownomics.in");
ofstream fout("cownomics.out");

string spots[100], nospots[100];

int main()
{
    int n, m;
    fin >> n >> m;
    for (int i = 0; i < n; i++)
        fin >> spots[i];
    for (int i = 0; i < n; i++)
        fin >> nospots[i];

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        bool used['t' + 1] = {false};
        bool isans = true;
        for (int j = 0; j < n; j++)
            used[spots[j][i]] = true;
        for (int j = 0; j < n; j++)
        {
            if (used[nospots[j][i]])
            {
                isans = false;
                break;
            }
        }
        ans += isans;
    }

    fout << ans << endl;

    return 0;
}
