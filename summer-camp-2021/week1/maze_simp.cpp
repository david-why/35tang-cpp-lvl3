#include <fstream> // ifstream, ofstream
#include <vector>  // vector
#include <queue>   // queue
#include <utility> // pair, make_pair

using namespace std;

struct mazenode
{
    bool up, down, left, right, people, visited;
} maze[101][101];

vector<pair<int, int>> people;
int components[10001], next_component, component[101][101];

int main()
{
    ofstream fout("maze.out");
    ifstream fin("maze.in");
    int n, k, walls;
    fin >> n >> k >> walls;
    for (int w = 0; w < walls; w++)
    {
        int r1, c1, r2, c2;
        fin >> r1 >> c1 >> r2 >> c2;
        if (r1 > r2)
        {
            maze[r1][c1].up = true;
            maze[r2][c2].down = true;
        }
        else if (r1 < r2)
        {
            maze[r1][c1].down = true;
            maze[r2][c2].up = true;
        }
        else if (c1 > c2)
        {
            maze[r1][c1].left = true;
            maze[r2][c2].right = true;
        }
        else
        {
            maze[r1][c1].right = true;
            maze[r2][c2].left = true;
        }
    }
    for (int p = 0; p < k; p++)
    {
        int r, c;
        fin >> r >> c;
        maze[r][c].people = true;
        people.push_back(make_pair(r, c));
    }

    for (vector<pair<int, int>>::iterator it = people.begin(); it != people.end(); it++)
    {
        int r = (*it).first, c = (*it).second;
        if (component[r][c])
            continue;
        int cid = ++next_component;
        queue<pair<int, int>> pending;
        pending.push(make_pair(r, c));
        while (!pending.empty())
        {
            pair<int, int> pos = pending.front();
            pending.pop();
            int nowr = pos.first, nowc = pos.second;
            if (maze[nowr][nowc].visited)
                continue;
            maze[nowr][nowc].visited = true;
            component[nowr][nowc] = cid;
            if (maze[nowr][nowc].people)
                components[cid]++;
            if (nowr > 1 && !(maze[nowr][nowc].up) && !(maze[nowr - 1][nowc].visited))
                pending.push(make_pair(nowr - 1, nowc));
            if (nowc > 1 && !(maze[nowr][nowc].left) && !(maze[nowr][nowc - 1].visited))
                pending.push(make_pair(nowr, nowc - 1));
            if (nowr < n && !(maze[nowr][nowc].down) && !(maze[nowr + 1][nowc].visited))
                pending.push(make_pair(nowr + 1, nowc));
            if (nowc < n && !(maze[nowr][nowc].right) && !(maze[nowr][nowc + 1].visited))
                pending.push(make_pair(nowr, nowc + 1));
        }
    }

    int ans = 0;
    for (int c = 1; c <= next_component; c++)
    {
        ans += components[c] * (k - components[c]);
    }

    fout << ans / 2 << endl;
    fout.close();

    return 0;
}
