#include <fstream> // ifstream, ofstream

using namespace std;

int r, s;
int ans;
bool visited[26];
char maze[20][20];

void dfs(int row, int col, int been)
{
    been++;
    if (been > ans)
        ans = been;

    visited[maze[row][col] - 'A'] = true;
    if (row + 1 < r && !visited[maze[row + 1][col] - 'A'])
        dfs(row + 1, col, been);
    if (col + 1 < s && !visited[maze[row][col + 1] - 'A'])
        dfs(row, col + 1, been);
    if (row > 0 && !visited[maze[row - 1][col] - 'A'])
        dfs(row - 1, col, been);
    if (col > 0 && !visited[maze[row][col - 1] - 'A'])
        dfs(row, col - 1, been);
    visited[maze[row][col] - 'A'] = false;
}

int main()
{
    ifstream fin("letter.in");
    fin >> r >> s;
    for (int row = 0; row < r; row++)
        for (int col = 0; col < s; col++)
            fin >> maze[row][col];
    fin.close();

    dfs(0, 0, 0);

    ofstream fout("letter.out");
    fout << ans << endl;
    fout.close();

    return 0;
}
