#include <bits/stdc++.h>

using namespace std;

int components[1000], n, m, component_id = 0, combined = 0;
set<int> connects[1000];
map<int, set<int>> component_list;
bool visited[1000];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        connects[a].insert(b);
        connects[b].insert(a);
    }

    for (int begin = 0; begin < n; begin++)
    {
        if (components[begin])
            continue;

        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }
        queue<int> pending;
        int now, component;
        pending.push(begin);
        components[begin] = component_id;
        component_list[component_id].insert(begin);
        component = component_id;
        component_id++;

        while (!pending.empty())
        {
            now = pending.front();
            pending.pop();
            visited[now] = true;
            if (components[now] && components[now] != component)
            {
                set<int> cities = component_list[now];
                for (set<int>::iterator it = cities.begin(); it != cities.end(); it++)
                {
                    int city = *it;
                    components[city] = component;
                    component_list[component].insert(city);
                }
                cities.clear();
                combined++;
            }
            else
            {
                components[now] = component;
                component_list[component].insert(now);
            }
            set<int> connect = connects[now];
            for (set<int>::iterator it = connect.begin(); it != connect.end(); it++)
            {
                int city = *it;
                if (!visited[city])
                {
                    pending.push(city);
                }
            }
        }
    }

    cout << component_id - combined << endl;

    return 0;
}
