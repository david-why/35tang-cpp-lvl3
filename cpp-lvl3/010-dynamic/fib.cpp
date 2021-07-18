#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long long x = 0, y = 1;
    for (int i = 0; i < n; i++)
    {
        // Method 1:
        long long now = x + y;
        x = y;
        y = now;

        // Method 2:
        // x += (2 * y - (y = x + y));
    }

    cout << x << endl;

    return 0;
}
