#include <bits/stdc++.h>

using namespace std;

// vector<pair<int, int>> uneq;
int uneq[100001][2], uneqlen;
unordered_map<int, int> parent;

int find_root(int i)
{
    auto it = parent.find(i);
    return it == parent.end() ? (parent[i] = i) : (it->second == i ? i : (it->second = find_root(it->second)));
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int q = 0; q < t; q++)
    {
        uneqlen = 0;
        parent.clear();
        int n;
        scanf("%d", &n);
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            int x, j, e;
            scanf("%d %d %d", &x, &j, &e);
            // if (parent.find(x) == parent.end())
            //     parent[x] = x;
            // if (parent.find(j) == parent.end())
            //     parent[j] = j;
            if (!ok)
                continue;
            if (e)
                parent[find_root(x)] = find_root(j);
            else
            {
                uneq[uneqlen][0] = x, uneq[uneqlen++][1] = j;
                if (find_root(x) == find_root(j))
                    ok = false;
                // uneq.push_back(make_pair(x, j));
            }
        }
        for (int i = 0; i < uneqlen && ok; i++)
            if (find_root(uneq[i][0]) == find_root(uneq[i][1]))
                ok = false;
        if (ok)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
