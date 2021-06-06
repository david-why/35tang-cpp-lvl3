#include <bits/stdc++.h>

using namespace std;

using coord = short;
using money = short;
// 2=Y
// 1=R
// 0=N
using color = short;

const coord movex[] = {0, 0, 1, -1},
            movey[] = {1, -1, 0, 0};

color colors[101][101] = {{0}};
coord m, n;
money ans = -1;
bool visited[101][101] = {{false}};

void dfs(coord x, coord y, money cost, bool canmagic)
{
    if (x == m && y == m)
    {
        if (cost < ans || ans == -1)
        {
            ans = cost;
        }
        return;
    }
    if (cost > ans && ans != -1)
    {
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        coord nx = x + movex[i], ny = y + movey[i];
        if (nx == 0 || ny == 0 || visited[nx][ny])
        {
            continue;
        }

        visited[nx][ny] = true;
        if (colors[x][y] == colors[nx][ny])
        {
            // same color, money+=0
            dfs(nx, ny, cost + 0, true);
        }
        else if (colors[nx][ny])
        {
            // different color, money+=1
            dfs(nx, ny, cost + 1, true);
        }
        else
        {
            // no color, money+=2, magic
            if (canmagic)
            {
                colors[nx][ny] = colors[x][y];
                dfs(nx, ny, cost + 2, false);
                colors[nx][ny] = 0;
            }
        }
        visited[nx][ny] = false;
    }
}

int main()
{
    cin >> m >> n;
    for (coord i = 0; i < n; i++)
    {
        coord x, y;
        cin >> x >> y >> colors[x][y];
        colors[x][y]++;
    }

    dfs(1, 1, 0, true);

    cout << ans << endl;

    return 0;
}
