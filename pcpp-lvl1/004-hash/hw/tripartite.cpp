#include <bits/stdc++.h>

using namespace std;

pair<basic_string<int>, int> vertices[100001];
int components[100001], comp;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        vertices[x].first += y;
        vertices[y].first += x;
    }

    for (int i = 1; i <= n; i++)
    {
        vertices[i].second = i;
        sort(vertices[i].first.begin(), vertices[i].first.end());
    }
    sort(vertices + 1, vertices + n + 1);

    if (vertices[1].first.length() == 0)
    {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        if (vertices[i].first != vertices[i - 1].first)
            components[vertices[i].second] = ++comp;
        else
            components[vertices[i].second] = comp;
    }

    if (comp != 3)
    {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++)
        cout << components[i] << (i == n ? '\n' : ' ');

    return 0;
}
