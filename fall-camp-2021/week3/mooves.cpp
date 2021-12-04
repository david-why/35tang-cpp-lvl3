#include <bits/stdc++.h>

using namespace std;

struct cow_t
{
    unordered_set<int> visited;
    int pos;
} cows[100001];
int pos2cow[100001];

int mooves[200000][2];
int visited[100001];
unordered_set<int> components[100001];
int comps;
// bool visited[100001], got[100001];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++)
        scanf("%d %d", mooves[i], mooves[i] + 1);

    for (int i = 1; i <= n; i++)
        cows[i].visited.insert(pos2cow[i] = cows[i].pos = i);

    for (int i = 0; i < k; i++)
    {
        int apos = mooves[i][0], bpos = mooves[i][1];
        cow_t &a = cows[pos2cow[apos]], &b = cows[pos2cow[bpos]];
        swap(a.pos, b.pos);
        swap(pos2cow[apos], pos2cow[bpos]);
        a.visited.insert(a.pos);
        b.visited.insert(b.pos);
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        unordered_set<int> &used = components[comps++];
        queue<int> pending;
        pending.push(i);
        while (!pending.empty())
        {
            int now = pending.front();
            pending.pop();
            visited[now] = comps;
            used.insert(cows[now].visited.begin(), cows[now].visited.end());
            cows[now].visited.clear();
            if (!visited[cows[now].pos])
                pending.push(cows[now].pos);
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%lu\n", components[visited[i] - 1].size());

    return 0;
}
