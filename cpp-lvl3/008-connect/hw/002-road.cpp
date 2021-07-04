#include <bits/stdc++.h>

using namespace std;

int components[1001], nextcomponent, incomponent[1001];
vector<vector<int>> connected(1001);

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        connected[a].push_back(b);
        connected[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!components[i])
        {
            nextcomponent++;

            queue<int> waiting;
            waiting.push(i);

            while (!waiting.empty())
            {
                int now = waiting.front();
                waiting.pop();
                if (components[now])
                    continue;
                components[now] = nextcomponent;
                incomponent[nextcomponent]++;
                for (unsigned long i = 0; i < connected[now].size(); i++)
                {
                    waiting.push(connected[now][i]);
                }
            }
        }
    }

    int ans = 0;
    for (int c = 1; c <= nextcomponent; c++)
    {
        if (incomponent[c] > ans)
            ans = incomponent[c];
    }

    cout << ans << endl;

    return 0;
}
