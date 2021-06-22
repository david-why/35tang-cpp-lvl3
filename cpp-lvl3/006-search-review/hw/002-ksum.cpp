#include <bits/stdc++.h>

using namespace std;

int n, k;
int nums[100];
set<int> ans;

void dfs(int prev, int sum, int need)
{
    if (need == 0)
    {
        ans.insert(sum);
        return;
    }

    need--;
    for (int i = prev + 1; i < n; i++)
    {
        if (i > prev + 1 && nums[i] == nums[i - 1])
        {
            continue;
        }
        dfs(i, sum + nums[i], need);
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums, nums + n);
    dfs(-1, 0, k);

    cout << ans.size() << "\n";
    int s = ans.size();
    for (set<int>::iterator it = ans.begin(); it != ans.end(); it++)
    {
        s--;
        cout << *it << (s ? " " : "\n");
    }

    return 0;
}
