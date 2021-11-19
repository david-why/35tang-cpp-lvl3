#include <bits/stdc++.h>

using namespace std;

int a[20], b[20], n;
unordered_map<long long, long long> c;

long long dfs(int i, int vis)
{
    if (i == n)
        return 1LL;
    auto it = c.find((i << 20) + vis);
    if (it != c.end())
        return it->second;
    long long ans = 0;
    for (int j = 0; j < n; j++)
    {
        if ((vis & (1 << j)))
            continue;
        if (a[i] > b[j])
            break;
        ans += dfs(i + 1, vis | (1 << j));
    }
    return (c[(i << 20) + vis] = ans);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    sort(a, a + n, [](int a, int b)
         { return a < b; });
    sort(b, b + n);
    cout << dfs(0, 0) << endl;
    return 0;
}
