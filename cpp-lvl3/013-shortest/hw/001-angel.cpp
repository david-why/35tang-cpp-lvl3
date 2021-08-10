#include <bits/stdc++.h>

using namespace std;

char maze[200][200];

typedef struct
{
    int row;
    int col;
    int moves = 0;
} search_t;

struct cmp
{
    bool operator()(const search_t &a, const search_t &b)
    {
        return a.moves > b.moves;
    }
};

const int mr[] = {0, 0, 1, -1}, mc[] = {1, -1, 0, 0};
bool visited[200][200];

int main()
{
    int n, m;
    cin >> n >> m;
    search_t begin;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            cin >> maze[r][c];
            if (maze[r][c] == 'r')
            {
                begin.row = r;
                begin.col = c;
                begin.moves = 0;
            }
        }
    }

    priority_queue<search_t, vector<search_t>, cmp> pending;
    pending.push(begin);
    while (!pending.empty())
    {
        search_t now = pending.top();
        pending.pop();
        if (visited[now.row][now.col])
            continue;
        visited[now.row][now.col] = true;
        if (maze[now.row][now.col] == 'a')
        {
            cout << now.moves << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int newrow = now.row + mr[i], newcol = now.col + mc[i];
            if (newrow < 0 || newrow >= n || newcol < 0 || newcol >= m || maze[newrow][newcol] == '#')
                continue;
            int newmoves = now.moves + 1;
            if (maze[newrow][newcol] == 'x')
                newmoves++;
            pending.push({newrow, newcol, newmoves});
        }
    }

    cout << "NO ANSWER" << endl;

    return 0;
}
