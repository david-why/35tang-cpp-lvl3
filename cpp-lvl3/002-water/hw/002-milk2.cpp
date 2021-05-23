#include <bits/stdc++.h>

using namespace std;

#define in(m, x) m.find(x) != m.end()
#define time first
#define mod second

int main()
{
    short n;
    map<int, short> changes;

    cin >> n;
    for (short i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        if (in(changes, l))
        {
            changes[l]++;
        }
        else
        {
            changes[l] = 1;
        }
        if (in(changes, r))
        {
            changes[r]--;
        }
        else
        {
            changes[r] = -1;
        }
    }

    int prev = -1, farmers = 0, maxy = 0, maxn = 0;
    for (map<int, short>::iterator it = changes.begin(); it != changes.end(); it++)
    {
        short m = (*it).mod;
        int t = (*it).time;
        bool hasfarmers = farmers != 0;
        if (hasfarmers)
        {
            if (t - prev > maxy)
            {
                maxy = t - prev;
            }
        }
        else
        {
            if (prev != -1 && t - prev > maxn)
            {
                maxn = t - prev;
            }
        }
        farmers += m;
        if (hasfarmers != (farmers != 0))
        {
            prev = t;
        }
    }

    cout << maxy << " " << maxn << endl;

    return 0;
}
