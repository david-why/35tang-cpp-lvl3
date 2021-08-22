#include <fstream> // ifstream, ofstream
#include <vector>  // vector
#include <iostream>

using namespace std;

ifstream fin("workstation.in");
ofstream fout("workstation.out");

int whichcycle[1001];
vector<int> visited;

pair<int, int> workstations[1001];
#define left first
#define right second

bool moves[500];

int main()
{
    int n, m, k;
    fin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        fin >> workstations[i].left >> workstations[i].right;
    for (int i = 0; i < m; i++)
    {
        char c;
        fin >> c;
        moves[i] = c == 'R';
    }

    int now = 1;
    for (int i = 1; i <= k; i++)
    {
        if (whichcycle[now])
        {
            int cyclelen = i - whichcycle[now];
            int offset = (k - whichcycle[now] + 1) % cyclelen + whichcycle[now];
            cout << "Cycled!" << endl
                 << "Cycle len: " << cyclelen << endl
                 << "Offset is: " << offset << endl;
            fout << visited[offset - 1] << endl;
            return 0;
        }
        whichcycle[now] = i;
        visited.push_back(now);

        for (int j = 0; j < m; j++)
        {
            if (moves[j])
                now = workstations[now].right;
            else
                now = workstations[now].left;
        }
    }

    fout << now << endl;
    return 0;
}
