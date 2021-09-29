/*
n    := 1 - 100000
S[i] := 0 - 99999999  * ASC
A[i] := 0 - 999
*/
#include <bits/stdc++.h>

using namespace std;

struct p
{
    int s;
    int a;

    bool operator<(const p &x)
    {
        return a > x.a;
    }
} vals[100001];
int maxA2S[100002]; // max{i=x..n}(Ai + 2Si)
int maxS[100001]; // max{i=1..x}(Si)
int sumA[100001]; // sum{i=1..x}(Ai)

int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> vals[i].s;
    for (int i = 1; i <= n; i++)
        cin >> vals[i].a;

    sort(vals + 1, vals + n + 1);

    for (int i = 1; i <= n; i++)
    {
        maxS[i] = max(maxS[i - 1], vals[i].s);
        sumA[i] = sumA[i - 1] + vals[i].a;
    }
    for (int i = n; i >= 1; i--)
    {
        maxA2S[i] = max(maxA2S[i + 1], vals[i].a + 2 * vals[i].s);
    }

    for (int x = 1; x <= n; x++)
    {
        cout << max(sumA[x] + 2 * maxS[x], sumA[x - 1] + maxA2S[x]) << "\n";
    }

    return 0;
}
