#include <fstream>   // ifstream, ofstream
#include <algorithm> // min

using namespace std;

ifstream fin("tower.in");
ofstream fout("tower.out");

int n, a, b;
int positions[2000];

int dp[2000];

int main()
{
    fin >> n >> a >> b;
    a *= 2;
    for (int i = 0; i < n; i++)
        fin >> positions[i];

    sort(positions, positions + n);

    for (int j = 0; j < n; j++)
    {
        dp[j] = a + b * (positions[j] - positions[0]);
        for (int k = 0; k < j; k++)
            dp[j] = min(dp[j], dp[k] + a + b * (positions[j] - positions[k + 1]));
    }

    fout << dp[n - 1] / 2 << endl;

    return 0;
}
