#include <bits/stdc++.h>

using namespace std;

char maze[200][200];
int m, n;
char word[1000];
int wordlen;
int mrow[] = {+0, +0, +1, -1},
    mcol[] = {+1, -1, +0, +0};

bool dfs(int row, int col, int nextindex)
{
    if (nextindex > wordlen)
    {
        return true;
    }

    char now = maze[row][col];
    maze[row][col] = '.';
    for (int i = 0; i < 4; i++)
    {
        int nrow = mrow[i] + row,
            ncol = mcol[i] + col;
        if (nrow < 0 || nrow >= m || ncol < 0 || ncol >= n)
        {
            continue;
        }
        if (dfs(nrow, ncol, nextindex + 1))
        {
            return true;
        }
    }
    maze[row][col] = now;

    return false;
}

int main()
{
    cin >> m >> n;
    for (int row = 0; row < m; row++)
    {
        cin >> maze[row];
    }
    cin >> word;
    wordlen = strlen(word);

    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (dfs(row, col, 1))
            {
                cout << "true" << endl;
                return 0;
            }
        }
    }
    cout << "false" << endl;

    return 0;
}
