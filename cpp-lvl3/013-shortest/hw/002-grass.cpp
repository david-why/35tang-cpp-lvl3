#include <bits/stdc++.h>

using namespace std;

typedef struct
{
    int weight;
    int pos;
    int visited;
} search_t;

struct cmp
{
    bool operator()(const search_t &a, const search_t &b)
    {
        return a.weight > b.weight;
    }
};

int weights[12][12];
bool visited[12][1<<12];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> weights[i][j];

    priority_queue<search_t, vector<search_t>, cmp> pending;
    pending.push({0, 0, (1 << n) - 2});
    while (!pending.empty())
    {
        search_t now = pending.top();
        pending.pop();
        if (visited[now.pos][now.visited])
            continue;
        visited[now.pos][now.visited] = true;
        // now.visited |= (1 << now.pos);
        // cout << "@" << now.pos << " v" << bitset<12>(now.visited) << " w" << now.weight << endl;
        if (!now.visited)
        {
            cout << now.weight << endl;
            return 0;
        }
        for (int i = 0; i < n; i++)
            if (weights[now.pos][i] && (now.visited & (1 << i)))
                pending.push({now.weight + weights[now.pos][i], i, now.visited ^ (1 << i)});
    }

    cout << "Emmm..." << endl;
    return 0;
}
