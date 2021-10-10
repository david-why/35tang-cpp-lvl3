#include <bits/stdc++.h>

using namespace std;

int findtime(map<int, int>& f, int si)
{
    int m = 0;
    for (const pair<int, int>& p : f)
    {
        int t = 0;
        int num = p.first;
        while (si % num == 0)
        {
            t++;
            si /= num;
        }
        if (t == 0)
            return -1;
        int time = (p.second + t - 1) / t;
        if (time > m)
            m = time;
    }
    return m;
}

int main()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    map<int, int> f;

    int b = m1;
    for (int i = 2; i * i <= b; i++)
    {
        while (m1 % i == 0)
        {
            f[i]++;
            m1 /= i;
        }
    }
    if (m1 != 1)
        f[m1]++;
    for (pair<const int, int>& p : f)
        p.second *= m2;

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int val;
        if ((val = findtime(f, x)) == -1)
            continue;
        if (val < ans)
            ans = val;
    }

    cout << (ans == INT_MAX ? -1 : ans) << endl;
    return 0;
}

