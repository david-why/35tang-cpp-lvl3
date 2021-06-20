#include <bits/stdc++.h>

using namespace std;

#define MAXN 30

int n, ans;
int chosen[MAXN];

void dfs(int row)
{
    if (row == n)
    {
        ans++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        bool ok = true;
        for (int j = 0; j < row; j++)
        {
            if (chosen[j] == i || row - j == i - chosen[j] || row - j == chosen[j] - i)
            {
                ok = false;
                break;
            }
        }
        if (!ok)
        {
            continue;
        }
        chosen[row] = i;
        dfs(row + 1);
    }
}

int main()
{
    cin >> n;

    dfs(0);

    cout << ans << endl;

    return 0;
}
