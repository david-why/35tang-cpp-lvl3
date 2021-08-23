#include <fstream>   // ifstream, ofstream
#include <algorithm> // min

using namespace std;

ifstream fin("tower.in");
ofstream fout("tower.out");

int n, a, b;
int positions[2000];

int dp[2000][2000];

int main()
{
    fin >> n >> a >> b;
    a *= 2;
    for (int i = 0; i < n; i++)
    {
        fin >> positions[i];
        dp[i][i] = a;
    }

    sort(positions, positions + n);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            dp[i][j] = a + b * (positions[j] - positions[i]);
            for (int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
        }
    }

    fout << dp[0][n - 1] / 2 << endl;

    return 0;
}
