#include <bits/stdc++.h>

using namespace std;

#define in(m, k) ((m).find(k) != (m).end())

map<short, short> flag;

int main()
{
    short n;

    cin >> n;
    for (short i = 0; i < n; i++)
    {
        short s, t, b;
        cin >> s >> t >> b;
        if (in(flag, s))
        {
            flag.at(s) += b;
        }
        else
        {
            flag[s] = b;
        }
        if (in(flag, t))
        {
            flag.at(t) -= b;
        }
        else
        {
            flag[t] = -b;
        }
    }

    short buckets = 0, max = 0;
    for (auto it = flag.begin(); it != flag.end(); it++)
    {
        buckets += it->second;
        if (buckets > max)
            max = buckets;
    }

    cout << max << endl;

    return 0;
}
