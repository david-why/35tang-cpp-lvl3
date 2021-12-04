#include <bits/stdc++.h>

using namespace std;

int nums[200000];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    long double ans = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x = nums[i];
        m[x]++;
        ans += (long long)x * (i * 2 + 1 - n) - m[x - 1] + m[x + 1];
    }

    cout << fixed << setprecision(0) << ans << endl;
    return 0;
}
