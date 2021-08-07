#include <fstream>   // ifstream, ofstream
#include <algorithm> // sort
#include <iostream>
using namespace std;

/**
 * Index 0: Maximum item ID
 * Index 1: Amount of money
 * Value:   Maximum 'importance'
 */
int dp[26][30001];
int answers[26][30001];
// {importance, price}
pair<int, int> items[25];

int main()
{
    ifstream fin("buy.in");
    int n, m;
    fin >> n >> m;
    for (int i = 1; i <= m; i++)
        fin >> items[i].second >> items[i].first;
    fin.close();

    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j >= items[i].second && (j == items[i].second || dp[i][j - items[i].second] != dp[i][j - items[i].second - 1]) && dp[i - 1][j] < dp[i - 1][j - items[i].second] + items[i].first)
            {
                dp[i][j] = dp[i - 1][j - items[i].second] + items[i].first;
                answers[i][j] = answers[i - 1][j - items[i].second] + items[i].first * items[i].second;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
                answers[i][j] = answers[i - 1][j];
            }
            if (answers[i][j] > ans)
                ans = answers[i][j];
        }
    }

    ofstream fout("buy.out");
    fout << ans << endl;
    fout.close();

    return 0;
}
