#include <bits/stdc++.h>

using namespace std;

int parent[1001];

int findRoot(int node)
{
    int ret = node;
    while (parent[ret] != ret)
        ret = parent[ret];
    return ret;
}

int main()
{
    int n, /* MAX 1000 */ m /* MAX 100000 */;
    int ans;

    cin >> n >> m;
    ans = n - 1;

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, ar, br;
        cin >> a >> b;
        ar = findRoot(a);
        br = findRoot(b);
        parent[br] = ar;
        ans -= (ar != br);
    }

    cout << ans << endl;

    return 0;
}
