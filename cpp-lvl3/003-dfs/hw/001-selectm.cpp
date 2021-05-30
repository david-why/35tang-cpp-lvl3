#include <bits/stdc++.h>

using namespace std;

int n, m, nums[100];
vector<int> output;

void dfs(int nowsum, int canuse)
{
    if (nowsum == m)
    {
        for (unsigned int i = 0; i < output.size(); i++)
        {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int next = canuse; next < n; next++)
    {
        output.push_back(nums[next]);
        dfs(nowsum + nums[next], next + 1);
        output.pop_back();
    }

    return;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums, nums + n);
    dfs(0, 0);

    return 0;
}
