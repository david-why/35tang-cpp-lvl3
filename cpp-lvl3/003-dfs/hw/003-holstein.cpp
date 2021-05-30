#include <bits/stdc++.h>

using namespace std;

int v, g;
unsigned short used = 0;
int needed[25], feeds[15][25];
int minfeeds = 16;
unsigned short minused = 65535;

void dfs(int canuse, int depth)
{
    if (depth > minfeeds)
    {
        return;
    }

    for (int i = canuse; i < g; i++)
    {
        used |= (1 << i);
        bool need = false;
        for (int vit = 0; vit < v; vit++)
        {
            needed[vit] -= feeds[i][vit];
            if (needed[vit] > 0)
            {
                need = true;
            }
        }
        if (!need)
        {
            if (depth + 1 < minfeeds)
            {
                minused = used;
                minfeeds = depth + 1;
            }
        }
        else
        {
            dfs(i + 1, depth + 1);
        }
        for (int vit = 0; vit < v; vit++)
        {
            needed[vit] += feeds[i][vit];
        }
        used ^= (1 << i);
        if (!need)
        {
            return;
        }
    }
}

int main()
{
    cin >> v;
    for (int i = 0; i < v; i++)
    {
        cin >> needed[i];
    }
    cin >> g;
    for (int feed = 0; feed < g; feed++)
    {
        for (int vit = 0; vit < v; vit++)
        {
            cin >> feeds[feed][vit];
        }
    }

    dfs(0, 0);

    cout << minfeeds;
    for (int i = 0; i < g; i++)
    {
        if (minused & (1 << i))
        {
            cout << " " << i + 1;
        }
    }
    cout << endl;

    return 0;
}
