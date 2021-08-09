#include <bits/stdc++.h>

using namespace std;

int weights[12][12];
short visited;
#define isvisited(pos) (visited & (1 << (pos)))
#define togvisited(pos) visited ^= (1 << (pos))
int ans = INT_MAX;
int n;
int minweight[65536];

void dfs(int now, int weight, int times)
{
    if (minweight[visited + (now << 12)] < weight)
        return;
    minweight[visited + (now << 12)] = weight;
    if (times == n)
    {
        if (weight < ans)
            ans = weight;
        return;
    }

    togvisited(now);
    times++;
    for (int i = 0; i < n; i++)
    {
        if (!isvisited(i) && weights[now][i])
        {
            dfs(i, weight + weights[now][i], times);
        }
    }
    togvisited(now);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> weights[i][j];

    for (int i = 0; i < 65536; i++)
        minweight[i] = INT_MAX;

    dfs(0, 0, 1);

    cout << ans << endl;

    return 0;
}
