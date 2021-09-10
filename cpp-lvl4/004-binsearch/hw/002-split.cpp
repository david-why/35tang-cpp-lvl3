#include <bits/stdc++.h>

using namespace std;

int sums[1001];
int n, m;

bool isok(int maxsum)
{
    int tobound = 0, prevnum = 1;
    for (int i = 0; i < m; i++)
    {
        int *pos = upper_bound(sums + prevnum, sums + n + 1, tobound + maxsum);
        if (pos == sums + n + 1)
            return true;
        prevnum = pos - sums;
        tobound = pos[-1];
    }
    return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        sums[i] = sums[i - 1] + num;
    }

    int left = sums[n] / m, right = sums[n];
    int ans = left;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (isok(mid))
        {
            right = mid;
            ans = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
