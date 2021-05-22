#include <bits/stdc++.h>

using namespace std;

#define P(x) prices[x]

short prices[30000];

int main()
{
    short n, w, ans = 0, left = 0, right;

    cin >> w >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    sort(prices, prices + n);
    right = n - 1;
    while (left < right)
    {
        while (P(left) + P(right) > w && left < right)
        {
            right--;
            ans++;
        }
        if (P(left) + P(right) <= w)
        {
            left++;
            right--;
            ans++;
            if (left == right)
                ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
