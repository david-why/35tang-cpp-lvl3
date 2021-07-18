#include <bits/stdc++.h>

using namespace std;

int maxend[100000] = {-1};

int main()
{
    int n;
    cin >> n;

    int out = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        maxend[i] = x;
        if (maxend[i - 1] > 0)
            maxend[i] += maxend[i - 1];
        if (maxend[i] > out)
            out = maxend[i];
    }

    cout << out << endl;

    return 0;
}
