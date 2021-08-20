#include <fstream>   // ifstream, ofstream
#include <set>       // set
#include <algorithm> // min

using namespace std;

ifstream fin("tower.in");
ofstream fout("tower.out");

int n, a, b;
int positions[2000];

double dp[2000][2000];

int main()
{
    fin >> n >> a >> b;
    for (int i = 0; i < n; i++)
        fin >> positions[i];

    sort(positions, positions + n);

    for (int i = n - 1; i >= 0; i--)
        for (int j = i; j < n; j++)
            if (i == j)
                dp[i][j] = a;
            else
                dp[i][j] = min(a + b * (positions[j] - positions[i]) / 2.0, a + min(dp[i + 1][j], dp[i][j - 1]));

    fout << dp[0][n - 1] << endl;

    return 0;
}
