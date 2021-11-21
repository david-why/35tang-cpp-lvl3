#include <bits/stdc++.h>

using namespace std;

#define maxn 2500

pair<int, int> cows[maxn + 1];
int presum[maxn + 1][maxn + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> cows[i].first >> cows[i].second;

    sort(cows + 1, cows + 1 + n, [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.first < b.first; });
    for (int i = 1; i <= n; i++)
        cows[i].first = i;

    sort(cows + 1, cows + 1 + n, [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second < b.second; });
    for (int i = 1; i <= n; i++)
    {
        cows[i].second = i;
        presum[cows[i].first][i]++;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            presum[i][j] += presum[i][j - 1] + presum[i - 1][j] - presum[i - 1][j - 1];

    long long ans = n + 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            const pair<int, int> &a = cows[i], &b = cows[j];
            int x1 = min(a.first, b.first), x2 = (x1 == a.first ? b.first : a.first);
            ans += (presum[x1][j] - presum[x1][i - 1]) * (presum[n][j] - presum[n][i - 1] - presum[x2 - 1][j] + presum[x2 - 1][i - 1]);
        }
    }

    cout << ans << endl;
    return 0;
}
