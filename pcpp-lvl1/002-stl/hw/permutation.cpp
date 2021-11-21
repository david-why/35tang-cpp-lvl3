#include <bits/stdc++.h>

using namespace std;

vector<int> a, b;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
        b.push_back(x);
    }
    if (prev_permutation(a.begin(), a.end()))
        for (int i = 0; i < n; i++)
            cout << a[i] << (i == n - 1 ? '\n' : ' ');
    for (int i = 0; i < n; i++)
        cout << b[i] << (i == n - 1 ? '\n' : ' ');
    if (next_permutation(b.begin(), b.end()))
        for (int i = 0; i < n; i++)
            cout << b[i] << (i == n - 1 ? '\n' : ' ');
    return 0;
}
