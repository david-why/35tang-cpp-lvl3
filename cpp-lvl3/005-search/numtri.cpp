#include <bits/stdc++.h>

using namespace std;

int r; // 1 <= r <= 1000
int nums[1001][1001], nxt[1001][1001];

int dfs(int i, int j)
{
    if (nxt[i][j] >= 0)
    {
        return nxt[i][j];
    }
    if (i == r)
    {
        return nxt[i][j] = nums[i][j];
    }

    int m = dfs(i + 1, j),
        n = dfs(i + 1, j + 1);
    return nxt[i][j] = nums[i][j] + ((m > n) ? m : n);
}

int main()
{
    cin >> r;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> nums[i][j];
            nxt[i][j] = -1;
        }
    }

    cout << dfs(0, 0) << endl;

    return 0;
}
