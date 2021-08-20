#include <fstream> // ifstream, ofstream

using namespace std;

ifstream fin("dicnum.in");
ofstream fout("dicnum.out");

string s;
int n;
bool printed;

void dfs(int now)
{
    if (now > n)
        return;

    if (printed)
        fout << " ";
    else
        printed = true;
    fout << now;

    int next = now * 10;
    for (int i = 0; i < 10; i++)
        dfs(next + i);
}

int main()
{
    fin >> n;

    for (int i = 1; i < 10; i++)
        dfs(i);
    fout << endl;

    return 0;
}
