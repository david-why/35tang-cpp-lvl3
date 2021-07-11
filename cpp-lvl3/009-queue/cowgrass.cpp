#include <bits/stdc++.h>

using namespace std;

bool visited[10001];

int main()
{
    int n, k;
    cin >> n >> k;

    queue<pair<int, int>> got;
    got.push(make_pair(n, 0));
    while (true)
    {
        pair<int, int> now = got.front();
        got.pop();
        visited[now.first] = true;
        if (now.first == k)
        {
            cout << now.second << endl;
            return 0;
        }
        if (!visited[now.first + 1])
        {
            got.push(make_pair(now.first + 1, now.second + 1));
        }
        if (now.first && !visited[now.first - 1])
        {
            got.push(make_pair(now.first - 1, now.second + 1));
        }
        if (now.first * 2 <= k + 1 && !visited[now.first * 2])
        {
            got.push(make_pair(now.first * 2, now.second + 1));
        }
    }

    return 0;
}
