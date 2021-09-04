#include <bits/stdc++.h>

using namespace std;

struct node
{
    int left, right, val;
} nodes[10001];

bool dfs(int i, int min, int max)
{
    if (!i)
        return true;
    node &n = nodes[i];
    if (n.val < min || n.val > max)
        return false;
    if ((n.left && n.val <= nodes[n.left].val) || (n.right && n.val >= nodes[n.right].val))
        return false;
    return dfs(n.left, min, n.val) && dfs(n.right, n.val, max);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> nodes[i].val >> nodes[i].left >> nodes[i].right;

    cout << dfs(1, INT_MIN, INT_MAX) << endl;

    return 0;
}
