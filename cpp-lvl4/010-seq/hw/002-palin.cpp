#include <bits/stdc++.h>
using namespace std;

char s[10002];
char ans[10001];
int n;

bool dp[10001][10001];
int main() {
    cin >> n >> (s + 1);
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < n; i++)
    {
        dp[i][i] = true;
        dp[i][i + 1] = s[i] == s[i + 1];
    }
    dp[n][n] = true;
    int begin = 0, size = INT_MIN;
    for (int i = n; i > 0; i--)
    {
        for (int j = i; j <= n; j++)
        {
            dp[i][j] = dp[i][j] || (dp[i + 1][j - 1] && s[i] == s[j]);
            if (dp[i][j] && j - i >= size)
            {
                begin = i;
                size = j - i;
            }
        }
    }
    strncpy(ans, s + begin, size + 1);
    cout << size + 1 << endl << ans << endl;
}

