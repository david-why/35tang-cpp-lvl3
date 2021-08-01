#include <bits/stdc++.h>

using namespace std;

int times[101], vals[101];
int dp[101][1001];

int main()
{
    int t, m;
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
        cin >> times[i] >> vals[i];

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            if (j >= times[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - times[i]] + vals[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[m][t] << endl;

    return 0;
}
