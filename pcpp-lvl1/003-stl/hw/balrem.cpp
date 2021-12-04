#include <bits/stdc++.h>

using namespace std;

#define maxn 50000

struct
{
    int x, y, z;
} points[maxn];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y >> points[i].z;

    map<int, vector<int>> orderx;
    for (int i = 0; i < n; i++)
        orderx[points[i].x].push_back(i);

    for (auto it = orderx.begin(); it != orderx.end();)
    {
        if (it->second.size() == 1)
        {
            it++;
            continue;
        }
        map<int, vector<int>> ordery;
        for (int i : it->second)
            ordery[points[i].y].push_back(i);
        for (auto jt = ordery.begin(); jt != ordery.end();)
        {
            if (jt->second.size() == 1)
            {
                jt++;
                continue;
            }
            map<int, int> orderz;
            for (int i : jt->second)
                orderz[points[i].z] = i;
            int ozl = orderz.size();
            for (auto kt = orderz.begin(); ozl >= 2; ozl -= 2)
                cout << (kt++)->second + 1 << " " << (kt++)->second + 1 << "\n";
            jt->second.clear();
            if (ozl)
                (jt++)->second.push_back(orderz.rbegin()->second);
            else
                ordery.erase(jt++);
        }
        int oyl = ordery.size();
        for (auto jt = ordery.begin(); oyl >= 2; oyl -= 2)
            cout << (jt++)->second[0] + 1 << " " << (jt++)->second[0] + 1 << "\n";
        it->second.clear();
        if (oyl)
            (it++)->second.push_back(ordery.rbegin()->second[0]);
        else
            orderx.erase(it++);
    }
    for (auto it = orderx.begin(); it != orderx.end();)
        cout << (it++)->second[0] + 1 << " " << (it++)->second[0] + 1 << "\n";

    return 0;
}
