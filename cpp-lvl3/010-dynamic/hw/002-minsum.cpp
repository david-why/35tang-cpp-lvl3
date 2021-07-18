#include <bits/stdc++.h>

using namespace std;

int maze[100][100], way[100][100];

int main()
{
    int m, n;
    cin >> m >> n;
    for (int row = 0; row < m; row++)
        for (int col = 0; col < n; col++)
            cin >> maze[row][col];

    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            way[row][col] = maze[row][col];
            if (row || col)
                way[row][col] += min(
                    row ? way[row - 1][col] : INT_MAX,
                    col ? way[row][col - 1] : INT_MAX);
        }
    }

    cout << way[m - 1][n - 1] << endl;

    return 0;
}
