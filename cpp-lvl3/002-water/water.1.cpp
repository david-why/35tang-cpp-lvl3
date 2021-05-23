#include <bits/stdc++.h>

using namespace std;

int main()
{
    short m, n;
    queue<short> students;
    priority_queue<int, vector<int>, greater<int>> pumps;

    cin >> n >> m;
    for (short i = 0; i < n; i++)
    {
        short w;
        cin >> w;
        students.push(w);
    }
    for (short i = 0; i < m; i++)
    {
        pumps.push(0);
    }

    for (short i = 0; i < n; i++)
    {
        short w = students.front();
        students.pop();
        int pump = pumps.top();
        pumps.pop();
        pumps.push(w + pump);
    }

    for (short i = 1; i < m; i++)
    {
        pumps.pop();
    }
    cout << pumps.top() << endl;

    return 0;
}
