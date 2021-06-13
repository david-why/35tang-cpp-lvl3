#include <bits/stdc++.h>

using namespace std;

bool nums[125001];
vector<pair<int, int>> ans;

int sumsquare(int p, int q)
{
    return p * p + q * q;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int p = 0; p <= m; p++)
    {
        for (int q = p; q <= m; q++)
        {
            nums[sumsquare(p, q)] = true;
        }
    }
    int maxn = sumsquare(m, m);

    for (int n1 = 0; n1 < maxn; n1++)
    {
        if (!nums[n1])
        {
            continue;
        }
        for (int n2 = n1 + 1; n2 < maxn; n2++)
        {
            if (!nums[n2])
            {
                continue;
            }
            if (n1 + (n2 - n1) * (n - 1) > maxn)
            {
                break;
            }
            bool ok = true;
            for (int i = n1, x = 0; x < n; i += n2 - n1, x++)
            {
                if (!nums[i])
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                ans.push_back({n2 - n1, n1});
            }
        }
    }

    sort(ans.begin(), ans.end());
    if (!ans.size())
    {
        cout << "NONE" << endl;
    }
    for (pair<int, int> now : ans)
    {
        cout << now.second << " " << now.first << "\n";
    }

    return 0;
}
