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
            cout << "-1" << endl;
            continue;
        }
        if (n2 > n3 - 1)
        {
            int tmp = n2 - (n3 - 1);
            n2 -= tmp;
            ans += tmp;
        }
        if (n1 > n2 - 1)
        {
            int tmp = n1 - (n2 - 1);
            n1 -= tmp;
            ans += tmp;
        }
        cout << ans << endl;
    }
}
