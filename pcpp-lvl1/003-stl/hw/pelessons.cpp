#include <bits/stdc++.h>

using namespace std;

#define left second
#define right first

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    set<pair<int, int>> holidays;
    int ans = n;
    for (int i = 0; i < q; i++)
    {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        r++;
        set<pair<int, int>>::iterator it = holidays.upper_bound(make_pair(l, INT_MAX));
        while (it != holidays.end() && it->left < r)
        {
            int il = it->left, ir = it->right;
            if (il < l)
            {
                ans -= l - il;
                holidays.insert(make_pair(l, il));
                if (ir > r)
                {
                    ans -= ir - r;
                    holidays.insert(make_pair(ir, r));
                }
            }
            else if (ir > r)
            {
                ans -= ir - r;
                holidays.insert(make_pair(ir, r));
            }
            ans += ir - il;
            holidays.erase(it++);
        }
        if (k == 1)
        {
            holidays.insert(make_pair(r, l));
            ans -= r - l;
        }
        printf("%d\n", ans);
    }

    return 0;
}
