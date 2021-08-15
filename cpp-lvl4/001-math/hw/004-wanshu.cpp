#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    bool printed = false;
    for (int i = 1; i < n; i++)
    {
        int s = 0;
        for (int j = 1; j < i; j++)
            if (i % j == 0)
                s += j;
        if (s == i)
        {
            cout << (printed ? " " : "") << i;
            printed = true;
        }
    }
    cout << endl;

    return 0;
}
