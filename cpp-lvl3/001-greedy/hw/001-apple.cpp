#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int n1, n2, n3, ans = 0;

        cin >> n1 >> n2 >> n3;

        if (n2 < 2 || n3 < 3)
        {
            cout << -1 << endl;
            continue;
        }
        int tmp = n2 - (n3 - 1);
        if (tmp > 0)
        {
            n2 -= tmp;
            ans += tmp;
        }
        tmp = n1 - (n2 - 1);
        if (tmp > 0)
        {
            n1 -= tmp;
            ans += tmp;
        }
        cout << ans << endl;
    }
}
