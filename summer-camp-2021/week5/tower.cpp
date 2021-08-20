#include <fstream>   // ifstream, ofstream
#include <set>       // set
#include <algorithm> // min

using namespace std;

ifstream fin("tower.in");
ofstream fout("tower.out");

int n, a, b;
int positions[2000];

double price[2000][2000];
double dfs(int i, int j)
{
    if (!price[i][j])
    {
        if (i >= j)
            price[i][j] = a;
        else
            price[i][j] = min(a + b * (positions[j] - positions[i]) / 2.0, a + min(dfs(i + 1, j), dfs(i, j - 1)));
    }

    return price[i][j];
}

int main()
{
    fin >> n >> a >> b;
    for (int i = 0; i < n; i++)
        fin >> positions[i];

    sort(positions, positions + n);

    double price = dfs(0, n - 1);
    fout << price << endl;

    return 0;
}
