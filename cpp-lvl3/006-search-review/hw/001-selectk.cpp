#include <bits/stdc++.h>

using namespace std;

int n, k;
int nums[100];
bool used[100];
int output[80];
int len;

void dfs(int prev)
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
        if (!used[i])
        {
            used[i] = true;
            output[len] = nums[i];
            len++;
            dfs(i);
            len--;
            used[i] = false;
        }
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
    dfs(-1);

    return 0;
}
