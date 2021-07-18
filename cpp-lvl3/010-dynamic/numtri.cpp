#include <bits/stdc++.h>

using namespace std;

int tri[1000][1000];
int maxway[1000][1000];

int main()
{
    int r;
    cin >> r;
    for (int i = 0; i < r; i++)
        for (int j = 0; j <= i; j++)
            cin >> tri[i][j];

    maxway[0][0] = tri[0][0];
    for (int row = 1; row < r; row++)
    {
        for (int col = 0; col <= row; col++)
        {
            if (col != row)
                maxway[row][col] = maxway[row - 1][col];
            if (col != 0 && maxway[row - 1][col - 1] > maxway[row][col])
                maxway[row][col] = maxway[row - 1][col - 1];
            maxway[row][col] += tri[row][col];
        }
    }

    int ans = -1;
    for (int c = 0; c < r; c++)
    {
        if (maxway[r - 1][c] > ans)
            ans = maxway[r - 1][c];
    }
    cout << ans << endl;

    return 0;
}
