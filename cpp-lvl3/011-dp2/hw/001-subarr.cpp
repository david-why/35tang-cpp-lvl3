#include <bits/stdc++.h>

using namespace std;

/**
 * Index1: Index of arr1
 * Index2: Index of arr2
 * Value:  Number of elements in a subarray ending at Index1 and
 *         Index2, respectively
 */
int dp[1001][1001];
int arr1[1001], arr2[1001];

int main()
{
    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        cin >> arr1[i];
    for (int i = 1; i <= n; i++)
        cin >> arr2[i];

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (arr1[i] == arr2[j])
                dp[i][j]++;
        }
    }

    cout << dp[m][n] << endl;

    return 0;
}
