#include <bits/stdc++.h>

using namespace std;

using change = pair<int, short>;
#define time first
#define mod second

int main()
{
    short n;
    priority_queue<change, vector<change>, greater<change>> changes;

    cin >> n;
    for (short i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        changes.push({l, 1});
        changes.push({r, -1});
    }

    int prev = -1, farmers = 0, maxy = 0, maxn = 0;
    while (!changes.empty())
    {
        short m = changes.top().mod;
        int t = changes.top().time;
        bool hasfarmers = farmers != 0;
        changes.pop();
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
        if (hasfarmers ^ (farmers != 0))
        {
            prev = t;
        }
    }

    cout << maxy << " " << maxn << endl;

    return 0;
}
