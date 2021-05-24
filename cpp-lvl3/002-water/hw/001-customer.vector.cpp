#include <bits/stdc++.h>

using namespace std;

using change = pair<int, int>;
#define time first
#define mod second

int main()
{
    int n;
    vector<change> changes;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        changes.push_back({a, 1});
        changes.push_back({b, -1});
    }

    sort(changes.rbegin(), changes.rend());
    int customers = 0, max = 0;
    while (!changes.empty())
    {
        change c = changes.back();
        changes.pop_back();
        customers += c.mod;
        if (customers > max)
            max = customers;
    }

    cout << max << endl;

    return 0;
}
