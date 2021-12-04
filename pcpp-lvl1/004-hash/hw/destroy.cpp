#include <bits/stdc++.h>

using namespace std;

int nums[100001], orders[100001];
long long sums[100001];
map<int, pair<int, long long>> seqs;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    for (int i = 1; i <= n; i++)
        cin >> orders[i];

    sums[n] = 0LL;
    for (int i = n; i >= 1; i--)
    {
        int order = orders[i];
        auto it = seqs.lower_bound(order);
        if (it == seqs.end())
        {
            it = seqs.emplace(order + 1, make_pair(order, 0LL)).first;
        }
        else if (it->first == order)
        {
            pair<int, long long> p = it->second;
            seqs.erase(it);
            it = seqs.emplace(order + 1, p).first;
            auto jt = it;
            jt++;
            if (jt != seqs.end() && jt->second.first == it->first)
            {
                jt->second.first = it->second.first;
                jt->second.second += it->second.second;
                seqs.erase(it);
                it = jt;
            }
        }
        else if (it->second.first == order + 1)
        {
            it->second.first = order;
        }
        else
        {
            it = seqs.emplace(order + 1, make_pair(order, 0LL)).first;
        }
        it->second.second += nums[order];
        if (it->second.second > sums[i])
            sums[i - 1] = it->second.second;
        else
            sums[i - 1] = sums[i];
    }

    for (int i = 1; i <= n; i++)
        cout << sums[i] << "\n";
    return 0;
}
