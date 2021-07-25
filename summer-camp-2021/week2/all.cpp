#include <fstream> // ifstream, ofstream
#include <cstdlib> // calloc

using namespace std;

ofstream fout("all.out");
int n;
int *nums = (int *)calloc(21, sizeof(int)) + 10;
int out[8];

void dfs(int depth)
{
    if (depth == n)
    {
        for (int i = 0; i < n; i++)
            fout << out[i] << (i == n - 1 ? '\n' : ' ');
        return;
    }

    for (int i = -10; i < 11; i++)
    {
        if (nums[i])
        {
            nums[i]--;
            out[depth] = i;
            dfs(depth + 1);
            nums[i]++;
        }
    }
}

int main()
{
    ifstream fin("all.in");
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        fin >> a;
        nums[a]++;
    }
    fin.close();

    dfs(0);

    return 0;
}
