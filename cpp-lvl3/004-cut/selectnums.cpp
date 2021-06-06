#include <bits/stdc++.h>

using namespace std;

bool visited[100] = {false};
vector<int> output;
int nums[100], n, k;

void dfs(int left)
{
    if (!left)
    {
        for (int i = 0; i < output.size(); i++)
        {
            cout << output[i] << (i < output.size() - 1 ? " " : "\n");
        }

        return;
    }

    left--;
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
        {
            continue;
        }
        visited[i] = true;
        output.push_back(nums[i]);
        dfs(left);
        output.pop_back();
        visited[i] = false;
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    dfs(k);

    return 0;
}
