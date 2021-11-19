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
