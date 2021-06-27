#include <bits/stdc++.h>

using namespace std;

int n, m, p, q;


struct node
{
    set<int> connections;
    bool visited = false;
} nodes[1000];

int ans;

void dfs(int now)
{
    if (now == q)
    {
        ans++;
        return;
    }

    node *n = nodes + now;
    n->visited = true;
    for (set<int>::iterator it = n->connections.begin(); it != n->connections.end(); it++)
    {
        int next = *it;
        if (!nodes[next].visited)
            dfs(next);
    }
    n->visited = false;
}

int main()
{

    cin >> n >> m >> p >> q;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        nodes[a].connections.insert(b);
        nodes[b].connections.insert(a);
    }

    dfs(p);

    cout << ans << endl;

    return 0;
}
