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
    short a;

    bool operator<(const p &x)
    {
        return a > x.a;
    }
} vals[100001];

int n;
// int S[100001];
// short A[100001];
bool prevused[100001], used[100001];
char out[1024 * 1024], *ptr = out;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        // cin >> S[i];
        cin >> vals[i].s;
    for (int i = 1; i <= n; i++)
        // cin >> A[i];
        cin >> vals[i].a;

    const int maxS = vals[n].s * 2;

    sort(vals + 1, vals + n + 1);

    int prev = 0, prevfar = 0, ans = 0, far = 0;
    for (int x = 1; x <= n; x++)
    {
        int tmp = ans + far * 2;
        for (int i = 1; i <= n; i++)
        {
            if (used[i])
                continue;
            // int use = prev + A[i];
            // int mfar = farther ? S[i] : (S[i] > prevfar ? ((farther = true) && S[i]) : prevfar);
            int use = prev + vals[i].a;
            if (use + maxS <= tmp)
                break;
            int mfar = max(vals[i].s, prevfar);
            if (use + mfar * 2 > tmp)
            {
                ans = use;
                // far = max(S[i], prevfar);
                far = mfar;
                memcpy(used, prevused, n);
                used[i] = true;
                tmp = ans + far * 2;
            }
        }

        ptr += sprintf(ptr, "%d\n", tmp);
        prev = ans;
        prevfar = far;
        memcpy(prevused, used, n);
    }

    cout << out;

    return 0;
}
