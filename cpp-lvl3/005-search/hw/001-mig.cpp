#include <bits/stdc++.h>

using namespace std;

int n, m, t;
int sx, sy, fx, fy;
int ans;
bool block[6][6];
bool visited[6][6];
const int mx[] = {+0, -0, +1, -1},
          my[] = {+1, -1, +0, -0};

// Take in current x and y, return how many ways to finish point from
// here.
int dfs(int x, int y)
{
    if (x == fx && y == fy)
    {
        ans++;
        return 1;
    }

    visited[x][y] = true;
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + mx[i], ny = y + my[i];
        if (nx <= 0 || ny <= 0 ||
            nx > n || ny > m ||
            visited[nx][ny] || block[nx][ny])
        {
            continue;
        }
        int now = dfs(nx, ny);
        if (now > ans)
        {
            ans = now;
        }
    }
    visited[x][y] = false;

    return ans;
}

int main()
{
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    for (int i = 0; i < t; i++)
    {
        int x, y;

        cin >> x >> y;

        block[x][y] = true;
    }

    dfs(sx, sy);

    cout << ans << endl;

    return 0;
}
