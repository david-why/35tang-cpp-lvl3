#include <bits/stdc++.h>

using namespace std;

vector<int> conn[100001];
bool visited[100001];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        conn[a].push_back(b);
        conn[b].push_back(a);
    }

    int ans = 0;
    queue<int> pending;
    pending.push(1);
    while (!pending.empty())
    {
        int now = pending.front();
        pending.pop();
        visited[now] = true;
        int need = 1;
        for (int farm : conn[now])
        {
            if (!visited[farm])
            {
                need++;
                pending.push(farm);
                ans++;
            }
        }
        ans += ceil(log2(need));
    }

    cout << ans << endl;
    return 0;
}

/*
from math import ceil, log2

n_farms = int(input())
from_to = {_: set() for _ in range(n_farms)}
for path in range(n_farms - 1):
    t = tuple(map((-1).__add__, map(int, input().split())))
    from_to[t[0]].add(t[1])
    from_to[t[1]].add(t[0])

days = 0
pool = {0}
got = set()
while pool:
    now = pool.pop()
    got.add(now)
    need = 1
    for farm in from_to[now]:
        if farm not in got:
            need += 1
            pool.add(farm)
            days += 1
    days += ceil(log2(need))

print(days)
*/