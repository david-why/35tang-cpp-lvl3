#include <bits/stdc++.h>

using namespace std;

/**
 * Index: Length of substring starting at beginning
 * Value: Number of possible decoded strings
 */
int dp[101];

int main()
{
    char s[101];
    s[0] = '3';
    cin >> (s + 1);
    int len = strlen(s);

    dp[0] = 1;
    for (int i = 1; i < len; i++)
    {
        if (s[i] != '0')
            dp[i] = dp[i - 1];
        if (s[i - 1] > '0' && (s[i - 1] - '0') * 10 + s[i] - '0' <= 26)
            dp[i] += dp[i - 2];
    }

    cout << dp[len - 1] << endl;

    return 0;
}
