#include <bits/stdc++.h>

using namespace std;

int n, m;
/**
 * Wall:                   -1
 * Haven't been here yet:  0
 * Has group:              positive groupid
 */
int grid[1000][1000];

int nextid = 1;
const int mrow[] = {+1, -1, +0, +0},
          mcol[] = {+0, +0, +1, -1};

void dfs(int row, int col, int groupid)
{
    grid[row][col] = groupid;

    for (int i = 0; i < 4; i++)
    {
        int newrow = row + mrow[i],
            newcol = col + mcol[i];
        if (newrow >= 0 && newrow < n &&
            newcol >= 0 && newcol < m &&
            !grid[newrow][newcol])
        {
            dfs(newrow, newcol, groupid);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            char c;
            cin >> c;
            grid[row][col] = (c == '#' ? -1 : 0);
        }
    }

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (!grid[row][col])
            {
                dfs(row, col, nextid++);
            }
        }
    }

    cout << nextid - 1 << endl;

    return 0;
}
