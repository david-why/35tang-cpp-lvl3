#include <bits/stdc++.h>

using namespace std;

ifstream fin("invite.in");
ofstream fout("invite.out");

vector<set<int>> groups;

int main()
{
    int n, g;
    fin >> n >> g;
    for (int i = 0; i < g; i++)
    {
        int num;
        fin >> num;
        set<int> group;
        for (int j = 0; j < num; j++)
        {
            int cow;
            fin >> cow;
            if (cow != 1)
                group.insert(cow);
        }
        groups.push_back(group);
    }

    bool changed = true;
    int invited = 1;
    while (changed)
    {
        changed = false;
        for (set<int> &group : groups)
        {
            if (group.size() == 1)
            {
                invited++;
                changed = true;
                int cow = *group.begin();
                for (set<int> &g2 : groups)
                    if (g2.find(cow) != g2.end())
                        g2.erase(cow);
            }
        }
    }

    fout << invited << endl;

    return 0;
}
