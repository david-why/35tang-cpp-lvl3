#include <bits/stdc++.h>

using namespace std;

using ll = long long;

map<ll, ll> cache;
ll a, b, c, d;

ll dfs(ll n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return d;
    auto it = cache.find(n);
    if (it != cache.end())
        return it->second;

    ll ans = LLONG_MAX;
    if (ans / n > d)
        ans = n * d;

    ll l = (n) / 2 * 2, r = (n + 1) / 2 * 2;
    ans = min(ans, dfs(l / 2) + d * llabs(l - n) + a);
    ans = min(ans, dfs(r / 2) + d * llabs(r - n) + a);

    l = (n) / 3 * 3, r = (n + 2) / 3 * 3;
    ans = min(ans, dfs(l / 3) + d * llabs(l - n) + b);
    ans = min(ans, dfs(r / 3) + d * llabs(r - n) + b);

    l = (n) / 5 * 5, r = (n + 4) / 5 * 5;
    ans = min(ans, dfs(l / 5) + d * llabs(l - n) + c);
    ans = min(ans, dfs(r / 5) + d * llabs(r - n) + c);

    return cache[n] = ans;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        ll n;
        cin >> n >> a >> b >> c >> d;
        cache.clear();
        cout << dfs(n) << endl;
    }
}
