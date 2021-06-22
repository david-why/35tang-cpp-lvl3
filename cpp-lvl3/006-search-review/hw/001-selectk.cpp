#include <bits/stdc++.h>

using namespace std;

int n, k;
int nums[100];
int output[80];

void dfs(int prev, int len)
{
    if (len == k)
    {
        for (int i = 0; i < k; i++)
        {
            cout << output[i] << ((i == k - 1) ? "\n" : " ");
        }
        return;
    }

    for (int i = prev + 1; i < n; i++)
    {
        output[len] = nums[i];
        dfs(i, len + 1);
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
    dfs(-1, 0);

    return 0;
}
