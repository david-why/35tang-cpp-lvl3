/*
USACO 2021 January Contest, Silver
Problem 2. No Time to Paint
*/
/* My own algorithm, TLE on last 5 testcases */
#include <bits/stdc++.h>

using namespace std;

char s[100001];
set<pair<int, int>> sets[26];
#define left second
#define right first

int dfs(char c, size_t l, size_t r)
{
    // cout << c << " " << l << " " << r << endl;
    if (c > 'Z' || l >= r)
        return 0;
    char *ptr = (char *)memchr(s + l, c, r - l);
    if (ptr == NULL)
        return dfs(c + 1, l, r);
    size_t first = ptr - s, prev = first;
    int ans = 1 + dfs(c + 1, l, first);
    for (size_t i = (char *)memchr(s + prev + 1, c, r - prev - 1) - s; i < r; prev = i, i = (char *)memchr(s + i + 1, c, r - i - 1) - s)
    {
        ans += dfs(c + 1, prev + 1, i);
    }
    sets[c - 'A'].insert(make_pair((char *)memrchr(s + l, c, r - l) - s + 1, first));
    ans += dfs(c + 1, prev + 1, r);
    return ans;
}

int main()
{
    int n, q;
    scanf("%d %d\n%s\n", &n, &q, s);
    int num = dfs('A', 0, n);

    for (int i = 0; i < q; i++)
    {
        int l, r;
        scanf("%d %d\n", &l, &r);
        l--;
        int ans = num;
        for (int i = 0; i < 26; i++)
        {
            set<pair<int, int>>::iterator it = sets[i].upper_bound(make_pair(l, INT_MAX));
            while (it != sets[i].end() && it->left < r)
            {
                int il = it->left, ir = it->right;
                if (il < l && ir > r)
                    ans++;
                else if (il >= l && ir <= r)
                    ans--;
                it++;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
