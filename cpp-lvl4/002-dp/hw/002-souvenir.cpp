#include <bits/stdc++.h>

using namespace std;

struct price
{
    int increase;
    int price;
} souvenirs[101][101];
int dp[101][10001];

bool cmp(const price &a, const price &b)
{
    return a.increase > b.increase;
}

int main()
{
    int t, n, m;
    cin >> t >> n >> m;
    for (int day = 1; day <= t; day++)
    {
        for (int item = 1; item <= n; item++)
        {
            cin >> souvenirs[day][item].price;
            souvenirs[day - 1][item].increase = souvenirs[day][item].price - souvenirs[day - 1][item].price;
        }
    }

    int hascoin = m;
    for (int day = 1; day <= t; day++)
    {
        memset(dp, 0, sizeof(dp));
        sort(souvenirs[day] + 1, souvenirs[day] + n + 1, cmp);
        int i;
        for (i = 1; i <= n && souvenirs[day][i].increase > 0; i++)
        {
            for (int j = 1; j <= hascoin; j++)
            {
                dp[i][j] = dp[i - 1][j];
                int other;
                if (j >= souvenirs[day][i].price &&
                    (other = dp[i][j - souvenirs[day][i].price] + souvenirs[day][i].increase) > dp[i][j])
                {
                    dp[i][j] = other;
                }
            }
        }
        hascoin += dp[i - 1][hascoin];
    }

    cout << hascoin << endl;

    return 0;
}
