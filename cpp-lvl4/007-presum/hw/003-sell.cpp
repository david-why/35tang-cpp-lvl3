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
bool prevused[100001], used[100001];
char out[1024 * 1024], *ptr = out;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> S[i];
    for (int i = 1; i <= n; i++)
        cin >> A[i];

    int prev = 0, prevfar = 0, ans = 0, far = 0;
    for (int x = 1; x <= n; x++)
    {
        bool farther = false;

        for (int i = 1; i <= n; i++)
        {
            if (used[i])
                continue;
            int use = prev + A[i];
            int mfar = farther ? S[i] : (S[i] > prevfar ? ((farther = true) && S[i]) : prevfar);
            if (use + mfar * 2 > ans + far * 2)
            {
                ans = use;
                far = max(S[i], prevfar);
                memcpy(used, prevused, 100001);
                used[i] = true;
            }
        }

        ptr += sprintf(ptr, "%d\n", ans + far * 2);
        prev = ans;
        prevfar = far;
        memcpy(prevused, used, 100001);
    }

    cout << out;

    return 0;
}
