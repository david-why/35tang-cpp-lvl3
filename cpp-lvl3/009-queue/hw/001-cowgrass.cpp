#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p, q;
    cin >> p >> q;

    int now = q;
    int ans = 0;
    while (p * 2 <= now && p + 2 < now)
    {
        if (now % 2)
            ans++;
        now /= 2;
        ans++;
    }
    ans += (now - p + 1) / 2;

    cout << ans << endl;

    return 0;
}
