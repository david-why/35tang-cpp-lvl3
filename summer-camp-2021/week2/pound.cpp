#include <fstream> // ifstream, ofstream
#include <vector>  // vector
#include <queue>   // queue
#include <utility> // pair, make_pair
#include <iostream>

using namespace std;

char maze[1002][1002];
const int rowmod[] = {1, -1, 0, 0}, colmod[] = {0, 0, 1, -1};

int main()
{
    ifstream fin("pound.in");
    int n;
    fin >> n;
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n; col++)
        {
            char c;
            fin >> c;
            if (c == '#')
                maze[row][col] = 1;
        }
    }
    fin.close();

    int maxa = -1, maxp = -1;
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n; col++)
        {
            if (maze[row][col] != 1)
                continue;
            int area = 0;
            int perimeter = 0;
            queue<pair<int, int>> pending;
            pending.push(make_pair(row, col));
            while (!pending.empty())
            {
                int nowr = pending.front().first, nowc = pending.front().second;
                pending.pop();
                if (maze[nowr][nowc] & 2)
                    continue;
                maze[nowr][nowc] |= 2;
                area++;
                for (int i = 0; i < 4; i++)
                {
                    if (maze[nowr + rowmod[i]][nowc + colmod[i]] & 1)
                        pending.push(make_pair(nowr + rowmod[i], nowc + colmod[i]));
                    else
                        perimeter++;
                }
            }
            if (area > maxa || (perimeter < maxp && area == maxa))
            {
                maxa = area;
                maxp = perimeter;
            }
        }
    }

    ofstream fout("pound.out");
    fout << maxa << " " << maxp << endl;
    fout.close();

    return 0;
}
