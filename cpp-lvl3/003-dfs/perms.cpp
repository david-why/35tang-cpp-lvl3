#include <bits/stdc++.h>

using namespace std;

int nums[101], output[101], n, k;

void dfs(int i, int j)
{
    if (j == k)
    {
        for (int l = 0; l < k; l++)
        {
            cout << output[l] << ' ';
        }
        cout << endl;
        return;
    }
    for (int l = i; l < n; l++)
    {
        output[j] = nums[l];
        dfs(l + 1, j + 1);
    }
    return;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums, nums + n);
    dfs(0, 0);

    return 0;
}
