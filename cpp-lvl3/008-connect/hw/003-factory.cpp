#include <bits/stdc++.h>

using namespace std;

int out[101];

int main()
{
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        out[a]++;
    }

    int noout = -1;
    for (int i = 1; i <= n; i++)
    {
        if (!out[i])
        {
            if (noout > 0)
            {
                cout << -1 << endl;
                return 0;
            }
            noout = i;
        }
    }

    cout << noout << endl;
    return 0;
}
