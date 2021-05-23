#include <bits/stdc++.h>

using namespace std;

short flag[1001] = {0};

int main()
{
    short n;

    cin >> n;
    for (short i = 0; i < n; i++)
    {
        short s, t, b;
        cin >> s >> t >> b;
        flag[s] += b;
        flag[t] -= b;
    }

    short buckets = 0, max = 0;
    for (short t = 0; t <= 1000; t++)
    {
        buckets += flag[t];
        if (buckets > max)
            max = buckets;
    }

    cout << max << endl;

    return 0;
}
