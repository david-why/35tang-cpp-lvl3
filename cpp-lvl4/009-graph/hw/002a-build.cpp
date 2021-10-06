/*
n := 1 - 100000
m := 1 - 100000
q := 1 - 100000
L := 1 - 1000000000
*/

#include <bits/stdc++.h>

using namespace std;

#define oe(x, y) (x % 2 ? odd : even)[y]

vector<int> connections[100001];
int odd[100001], even[100001];

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    queue<pair<int, int>> pending;
    pending.push(make_pair(1, 1));
    while (!pending.empty())
    {
        int now = pending.front().first, depth = pending.front().second;
        pending.pop();

        if (oe(depth, now))
            continue;
        oe(depth, now) = depth;
        depth++;
        for (int nxt : connections[now])
            pending.push(make_pair(nxt, depth));
    }

    for (int i = 0; i < q; i++)
    {
        int a, L;
        cin >> a >> L;
        L++;
        cout << ((oe(L, a) && oe(L, a) <= L) ? "Yes" : "No") << endl;
    }

    return 0;
}
