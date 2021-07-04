#include <bits/stdc++.h>

using namespace std;

int parent[100001];
int n, m, k;

int findroot(int node)
{
    int ret = node;
    while (parent[ret] != ret)
    {
        ret = parent[ret];
    }
    return ret;
}

int main()
{
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        int ra = findroot(a),
            rb = findroot(b);
        parent[rb] = ra;
    }

    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << (findroot(a) == findroot(b) ? "Yes" : "No") << endl;
    }

    return 0;
}
