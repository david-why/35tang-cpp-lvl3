#include <bits/stdc++.h>

using namespace std;

int pots[101];
int dp[101][101];

#define MOD 1000007

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> pots[i];

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 0; k <= pots[i] && j >= k; k++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
            }
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }

    cout << dp[n][m] << endl;

    return 0;
}
