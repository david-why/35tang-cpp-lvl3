#include <fstream> // ifstream, ofstream
#include <map>     // map
#include <vector>  // vector
#include <utility> // pair, make_pair

using namespace std;

int heights[202][202];
pair<bool, bool> reach[202][202];
map<int, vector<pair<int, int>>> h2p;
const int mr[] = {0, 0, 1, -1}, mc[] = {1, -1, 0, 0};

int main()
{
    ifstream fin("water.in");
    int m, n;
    fin >> m >> n;
    for (int row = 1; row <= m; row++)
    {
        for (int col = 1; col <= n; col++)
        {
            int h;
            fin >> h;
            heights[row][col] = h;
            h2p[h].push_back(make_pair(row, col));
        }
    }
    fin.close();

    for (int col = 0; col <= n + 1; col++)
    {
        reach[0][col].first = true;
        reach[m + 1][col].second = true;
    }
    for (int row = 1; row <= m; row++)
    {
        reach[row][0].first = true;
        reach[row][n + 1].second = true;
    }

    for (const pair<int, vector<pair<int, int>>> &hl : h2p)
    {
        int h = hl.first;
        for (const pair<int, int> &pos : hl.second)
        {
            int r = pos.first, c = pos.second;
            for (int i = 0; i < 4; i++)
            {
                if (reach[r + mr[i]][c + mc[i]].first && !reach[r][c].first && heights[r + mr[i]][c + mc[i]] <= h)
                    reach[r][c].first = true;
                if (reach[r + mr[i]][c + mc[i]].second && !reach[r][c].second && heights[r + mr[i]][c + mc[i]] <= h)
                    reach[r][c].second = true;
            }
        }
    }

    ofstream fout("water.out");
    for (int row = 1; row <= m; row++)
        for (int col = 1; col <= n; col++)
            if (reach[row][col].first && reach[row][col].second)
                fout << row - 1 << " " << col - 1 << endl;
    fout.close();
}
