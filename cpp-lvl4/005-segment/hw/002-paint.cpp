#include <bits/stdc++.h>

using namespace std;

ifstream fin("paint.in");
ofstream fout("paint.out");

map<int, int> changes;

int main()
{
    int n, k;
    fin >> n >> k;
    int curpos = 0;
    for (int i = 0; i < n; i++)
    {
        int len;
        char dir;
        fin >> len >> dir;
        if (dir == 'R')
        {
            changes[curpos]++;
            curpos += len;
            changes[curpos]--;
        }
        else
        {
            changes[curpos]--;
            curpos -= len;
            changes[curpos]++;
        }
    }

    int ans = 0;
    int levels = 0;
    int prev;
    for (pair<const int, int> &p : changes)
    {
        if (levels >= k)
            ans += p.first - prev;
        prev = p.first;
        levels += p.second;
    }

    fout << ans << endl;

    return 0;
}
