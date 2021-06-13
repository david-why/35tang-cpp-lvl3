#include <bits/stdc++.h>

using namespace std;

int n, m, t;
int sx, sy, fx, fy;
bool block[6][6];
int nxt[6][6], ans;
bool visited[6][6];
const int mx[] = {+0, -0, +1, -1},
          my[] = {+1, -1, +0, -0};

// Take in current x and y, return how many ways to finish point from
// here.
int dfs(int x, int y)
{
    cout << "(" << x << "," << y << ")" << endl;
    if (nxt[x][y] >= 0)
    {
        cout << "NXT " << nxt[x][y] << endl;
        ans += nxt[x][y];
        return nxt[x][y];
    }
    if (x == fx && y == fy)
    {
        cout << "YES" << endl;
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
    nxt[x][y] = ans;
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

    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= m; y++)
        {
            nxt[x][y] = -1;
        }
    }

    dfs(sx, sy);

    cout << ans << endl;

    return 0;
}
