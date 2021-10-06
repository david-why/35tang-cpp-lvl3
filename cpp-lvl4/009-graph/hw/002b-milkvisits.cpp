/*
N :=    1 - 100000
M :=    1 - 100000
X :=    1 - N
Y :=    1 - N
A[i] := 1 - N
B[i] := 1 - N
C[i] := [ 'H' | 'G' ]
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> connections[100001];
int component[100001], components;
string types;

int main()
{
    int n, m;
    cin >> n >> m;
    cin >> types;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (component[i])
            continue;

        int cid = ++components;
        queue<int> pending;
        pending.push(i);
        char c = types[i - 1];
        while (!pending.empty())
        {
            int now = pending.front();
            pending.pop();

            if (component[now])
                continue;
            component[now] = cid;
            for (int nxt : connections[now])
                if (types[nxt - 1] == c)
                    pending.push(nxt);
        }
    }

    for (int _ = 0; _ < m; _++)
    {
        int a, b;
        char c;
        cin >> a >> b >> c;
        cout << (types[a - 1] == c || types[b - 1] == c || component[a] != component[b]);
    }

    cout << endl;
    return 0;
}
