#include <bits/stdc++.h>

using namespace std;

using change = pair<int, int>;
#define time first
#define mod second

int main()
{
    int n;
    priority_queue<change, vector<change>, greater<change>> changes;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        changes.push({a, 1});
        changes.push({b, -1});
    }

    int customers = 0, max = 0;
    while (!changes.empty())
    {
        change c = changes.top();
        changes.pop();
        customers += c.mod;
        if (customers > max)
            max = customers;
    }

    cout << max << endl;

    return 0;
}
