#include <bits/stdc++.h>

using namespace std;

long long dp[26][10001];

int main()
{
    int v, n;
    cin >> v >> n;
    for (int i = 1; i <= v; i++)
    {
        int coin;
        cin >> coin;

        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= coin)
                dp[i][j] += dp[i][j - coin];
            if (j == coin)
                dp[i][j]++;
        }
    }

    cout << dp[v][n] << endl;

    return 0;
}
