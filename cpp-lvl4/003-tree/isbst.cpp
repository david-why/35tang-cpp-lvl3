#include <bits/stdc++.h>

using namespace std;

struct node
{
    int left, right, val;
} nodes[10001];

bool dfs(int i)
{
    if (!i)
        return true;
    node &n = nodes[i];
    if ((n.left && n.val <= nodes[n.left].val) || (n.right && n.val >= nodes[n.right].val))
        return false;
    return dfs(n.left) && dfs(n.right);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> nodes[i].val >> nodes[i].left >> nodes[i].right;

    cout << dfs(1) << endl;

    return 0;
}
