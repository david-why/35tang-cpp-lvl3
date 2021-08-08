#include <fstream>   // ifstream, ofstream
#include <algorithm> // sort
#include <iostream>
using namespace std;

/**
 * Index 0: Maximum item ID
 * Index 1: Amount of money
 * Value:   Maximum sum of importance * price
 */
int dp[26][30001];
int importance[26], prices[26];

int main()
{
    ifstream fin("buy.in");
    int n, m;
    fin >> n >> m;
    for (int i = 1; i <= m; i++)
        fin >> prices[i] >> importance[i];
    fin.close();

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j >= prices[i] && dp[i - 1][j - prices[i]] + importance[i] * prices[i] > dp[i - 1][j])
                dp[i][j] = dp[i - 1][j - prices[i]] + importance[i] * prices[i];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    ofstream fout("buy.out");
    fout << dp[m][n] << endl;
    fout.close();

    return 0;
}
