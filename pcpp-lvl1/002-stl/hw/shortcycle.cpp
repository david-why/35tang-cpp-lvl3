#include <bits/stdc++.h>

using namespace std;

vector<int> sets[64];
long long nums[133];
int parent[133];
unsigned int dist[133];

int main()
{
    int n;
    cin >> n;
    int diff = 0;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        if (x)
        {
            nums[diff] = x;
            for (int j = 0; j < 64; j++)
                if (x & (1LL << j))
                    sets[j].push_back(diff);
            diff++;
            if (diff > 130)
            {
                cout << 3 << endl;
                return 0;
            }
        }
    }

    unsigned int ans = UINT_MAX;
    for (int i = 0; i < diff; i++)
    {
        queue<int> pending;
        pending.push(i);
        memset(parent, -1, diff * sizeof(int));
        memset(dist, -1, diff * sizeof(unsigned int));
        dist[i] = 0;
        while (!pending.empty())
        {
            int x = pending.front();
            pending.pop();
            for (int j = 0; j < 64; j++)
            {
                if (nums[x] & (1LL << j))
                {
                    for (int k : sets[j])
                    {
                        if (k == x)
                            continue;
                        if (dist[k] == UINT_MAX)
                        {
                            dist[k] = dist[x] + 1;
                            parent[k] = x;
                            pending.push(k);
                        }
                        else if (parent[k] != x && parent[x] != k)
                        {
                            ans = min(ans, dist[k] + dist[x] + 1);
                            if (ans == 3)
                                goto end;
                        }
                    }
                }
            }
        }
    }

end:
    cout << (int)ans << endl;
    return 0;
}
