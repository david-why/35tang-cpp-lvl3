#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> pairs;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.first + a.second < b.first + b.second) ||
           (a.first + a.second == b.first + b.second && a.first < b.first);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p;
        cin >> p.first >> p.second;
        pairs.push_back(p);
    }

    sort(pairs.begin(), pairs.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        cout << pairs[i].first << " " << pairs[i].second << endl;
    }
    return 0;
}
