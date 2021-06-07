#include <bits/stdc++.h>

using namespace std;

#define NOW a][b][c
#define min(a, b) (((a) < (b)) ? (a) : (b))

bool visited[21][21][21];
vector<int> ans;
int am, bm, cm;

void dfs(int a, int b, int c)
{
    if (visited[NOW])
    {
        return;
    }
    if (!a)
    {
        ans.push_back(c);
    }
    visited[NOW] = true;

    int ab = min(a, bm - b), ba = min(b, am - a),
        ac = min(a, cm - c), ca = min(c, am - a),
        bc = min(b, cm - c), cb = min(c, bm - b);
    dfs(a - ab, b + ab, c);
    dfs(a + ba, b - ba, c);
    dfs(a - ac, b, c + ac);
    dfs(a + ca, b, c - ca);
    dfs(a, b - bc, c + bc);
    dfs(a, b + cb, c - cb);
}

int main()
{
    cin >> am >> bm >> cm;

    dfs(0, 0, cm);
    sort(ans.begin(), ans.end());

    for (unsigned int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
    }

    return 0;
}
