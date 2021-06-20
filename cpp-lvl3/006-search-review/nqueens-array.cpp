#include <bits/stdc++.h>

using namespace std;

#define MAXN 30

int n, ans;
int chosen[MAXN];
bool col[MAXN], ldiag[MAXN+MAXN], rdiag[MAXN+MAXN];

void dfs(int row)
{
    if (row == n)
    {
        ans++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (col[i] || ldiag[i - row + MAXN] || rdiag[i + row])
        {
            continue;
        }
        chosen[row] = i;
        col[i] = ldiag[i - row + MAXN] = rdiag[i + row] = true;
        dfs(row + 1);
        col[i] = ldiag[i - row + MAXN] = rdiag[i + row] = false;
    }
}

int main()
{
    cin >> n;

    dfs(0);

    cout << ans << endl;

    return 0;
}
