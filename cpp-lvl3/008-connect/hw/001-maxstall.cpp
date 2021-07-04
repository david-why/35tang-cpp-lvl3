#include <bits/stdc++.h>

using namespace std;

int components[1001], nextcomponent, incomponent[1001];
vector<vector<int>> connected(1001);

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            if (c == '1')
                connected[i].push_back(j);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!components[i])
        {
            nextcomponent++;

            queue<int> waiting;
            waiting.push(i);

            while (!waiting.empty())
            {
                int now = waiting.front();
                waiting.pop();
                if (components[now])
                    continue;
                components[now] = nextcomponent;
                incomponent[nextcomponent]++;
                for (unsigned long i = 0; i < connected[now].size(); i++)
                {
                    waiting.push(connected[now][i]);
                }
            }
        }
    }

    int m = 0;
    for (int c = 1; c <= nextcomponent; c++)
    {
        if (incomponent[c] > m)
            m = incomponent[c];
    }

    cout << m << endl;

    return 0;
}
