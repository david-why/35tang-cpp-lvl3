#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> p;

priority_queue<p, vector<p>, greater<p>> changes;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int begin, end;
        cin >> begin >> end;
        changes.push(make_pair(begin, -1));
        changes.push(make_pair(end, 1));
    }

    int counter = 0, ans = 0, start;
    while (!changes.empty())
    {
        p c = changes.top();
        changes.pop();
        if (counter == 0)
        {
            counter++;
            start = c.first;
        }
        else 
        {
            counter -= c.second;
            if (counter == 0)
                ans += c.first - start;
        }
    }

    cout << ans << endl;

    return 0;
}

