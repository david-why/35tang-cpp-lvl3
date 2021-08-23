#include <bits/stdc++.h>

using namespace std;

int nums[101];
int sums[101];
int dp[101][101];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        sums[i] = sums[i - 1] + nums[i];
    }

    for (int i = n; i >= 1; i--)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int m = INT_MAX;
            for (int k = i; k < j; k++)
                m = min(m, dp[i][k] + dp[k + 1][j]);

            dp[i][j] = m + sums[j] - sums[i - 1];
        }
    }

    cout << dp[1][n] << endl;

    return 0;
}
