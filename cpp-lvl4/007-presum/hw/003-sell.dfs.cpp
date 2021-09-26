/*
n    := 1 - 100000
S[i] := 0 - 99999999  * ASC
A[i] := 0 - 999
*/
#include <bits/stdc++.h>

using namespace std;

int n;
int S[100001];
short A[100001];
map<pair<int, int>, int> dp;

int dfs(int i, int x)
{
    if (i > n || x == 0)
        return 0;
    pair<int, int> p = make_pair(i, x);
    if (dp.find(p) != dp.end())
        return dp[p];

    int ans = 0;
    for (int j = i; j <= n; j++)
    {
        int e = dfs(j + 1, x - 1);
        e += A[j] + 2 * (S[j] - S[i - 1]);
        ans = max(e, ans);
    }

    return dp[p] = ans;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> S[i];
    for (int i = 1; i <= n; i++)
        cin >> A[i];

    for (int i = 1; i <= n; i++)
        cout << dfs(1, i) << endl;

    return 0;
}
