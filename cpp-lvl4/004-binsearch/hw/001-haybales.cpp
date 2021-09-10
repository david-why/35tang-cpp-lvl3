#include <bits/stdc++.h>

using namespace std;

int haybales[100000];

int main()
{
    // freopen("haybales.in", "r", stdin);
    // freopen("haybales.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> haybales[i];

    sort(haybales, haybales + n);

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << upper_bound(haybales, haybales + n, b) - lower_bound(haybales, haybales + n, a) << '\n';
    }

    return 0;
}
