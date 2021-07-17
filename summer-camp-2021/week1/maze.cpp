#include <fstream> // ifstream, ofstream
#include <vector>  // vector
#include <queue>   // queue
#include <utility> // pair, make_pair

using namespace std;

char maze[101][101];
#define U &0b000001
#define D &0b000010
#define L &0b000100
#define R &0b001000
#define P &0b010000
#define V &0b100000
#define SU |= 0b000001
#define SD |= 0b000010
#define SL |= 0b000100
#define SR |= 0b001000
#define SP |= 0b010000
#define SV |= 0b100000

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
            maze[r1][c1] SU;
            maze[r2][c2] SD;
        }
        else if (r1 < r2)
        {
            maze[r1][c1] SD;
            maze[r2][c2] SU;
        }
        else if (c1 > c2)
        {
            maze[r1][c1] SL;
            maze[r2][c2] SR;
        }
        else
        {
            maze[r1][c1] SR;
            maze[r2][c2] SL;
        }
    }
    for (int p = 0; p < k; p++)
    {
        int r, c;
        fin >> r >> c;
        maze[r][c] SP;
        people.push_back(make_pair(r, c));
    }

    for (vector<pair<int, int>>::iterator it = people.begin(); it != people.end(); it++)
    {
        int r = (*it).first, c = (*it).second;
        if (component[r][c])
            continue;
        // fout << r << " " << c << endl;
        int cid = ++next_component;
        queue<pair<int, int>> pending;
        pending.push(make_pair(r, c));
        while (!pending.empty())
        {
            pair<int, int> pos = pending.front();
            pending.pop();
            int nowr = pos.first, nowc = pos.second;
            if (maze[nowr][nowc] V)
                continue;
            maze[nowr][nowc] SV;
            component[nowr][nowc] = cid;
            if (maze[nowr][nowc] P)
                components[cid]++;
            if (nowr > 1 && !(maze[nowr][nowc] U) && !(maze[nowr - 1][nowc] V))
                pending.push(make_pair(nowr - 1, nowc));
            if (nowc > 1 && !(maze[nowr][nowc] L) && !(maze[nowr][nowc - 1] V))
                pending.push(make_pair(nowr, nowc - 1));
            if (nowr < n && !(maze[nowr][nowc] D) && !(maze[nowr + 1][nowc] V))
                pending.push(make_pair(nowr + 1, nowc));
            if (nowc < n && !(maze[nowr][nowc] R) && !(maze[nowr][nowc + 1] V))
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
