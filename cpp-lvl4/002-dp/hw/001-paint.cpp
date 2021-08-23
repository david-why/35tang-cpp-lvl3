#include <bits/stdc++.h>

using namespace std;

string s;
int dp[51][51];

int main()
{
    cin >> s;
    int n = s.length();

    for (int i = 1; i <= n; i++)
        dp[i][i] = 1;

    for (int i = n; i >= 1; i--)
    {
        for (int j = i + 1; j <= n; j++)
        {
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] - (s[i - 1] == s[j - 1]));
            }
        }
    }

    cout << dp[1][n] << endl;

    return 0;
}
