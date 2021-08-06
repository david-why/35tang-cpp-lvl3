#include <fstream> // ifstream, ofstream

using namespace std;

int n;
ofstream fout("subzero.out");
char ops[11];

void dfs(int now, int prevnum, int nowsum)
{
    // for (int i = 1; i < now; i++)
    //     fout << ops[i] << i; fout << "=" << nowsum << endl;
    if (now > n)
    {
        if (!nowsum)
        {
            fout << 1;
            for (int i = 2; i <= n; i++)
                fout << ops[i] << i;
            fout << endl;
        }
        return;
    }

    ops[now] = ' ';
    if (ops[now - 1] == '-')
        dfs(now + 1, prevnum * 10 + now, nowsum - prevnum * 9 - now);
    else
        dfs(now + 1, prevnum * 10 + now, nowsum + prevnum * 9 + now);
    ops[now] = '+';
    dfs(now + 1, now, nowsum + now);
    ops[now] = '-';
    dfs(now + 1, now, nowsum - now);
}

int main()
{
    ifstream fin("subzero.in");
    fin >> n;
    fin.close();

    ops[1] = '+';
    dfs(2, 1, 1);

    fout.close();
    return 0;
}