/*
n := 1 - 1000
m := 1 - 100000
*/

#include <bits/stdc++.h>

using namespace std;
char maze[1001][1001];
int component[1001][1001], components;
int ccount[1000001];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> maze[i][j];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (component[i][j])
                continue;

            int cid = ++components;
            // cout << "-- Component " << cid << endl;
            queue<pair<int, int>> pending;
            pending.push({i, j});

            while (!pending.empty())
            {
                int row = pending.front().first, col = pending.front().second;
                pending.pop();
                if (component[row][col])
                    continue;
                // cout << "(" << row << ", " << col << ")" << endl;

                component[row][col] = cid;
                ccount[cid]++;
                if (row != 1 && maze[row - 1][col] != maze[row][col])
                    pending.push(make_pair(row - 1, col));
                if (col != 1 && maze[row][col - 1] != maze[row][col])
                    pending.push(make_pair(row, col - 1));
                if (col != n && maze[row][col + 1] != maze[row][col])
                    pending.push(make_pair(row, col + 1));
                if (row != n && maze[row + 1][col] != maze[row][col])
                    pending.push(make_pair(row + 1, col));
            }
        }
    }

    for (int _ = 0; _ < m; _++)
    {
        int i, j;
        cin >> i >> j;
        cout << ccount[component[i][j]] << endl;
    }

    return 0;
}
