#include <bits/stdc++.h>

using namespace std;

int countries[100001];

int main()
{
    int n;
    cin >> n;

    // {time, country}
    queue<pair<int, int>> people;
    int out = 0;
    for (int i = 0; i < n; i++)
    {
        int t, k;
        cin >> t >> k;
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            countries[x]++;
            if (countries[x] == 1)
                out++;
            people.push(make_pair(t + 86400, x));
        }
        while (!people.empty())
        {
            pair<int, int> p = people.front();
            if (p.first <= t)
            {
                countries[p.second]--;
                if (!countries[p.second])
                    out--;
                people.pop();
            }
            else
                break;
        }
        cout << out << endl;
    }

    return 0;
}
