#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> output;

void dfs(int canuse, int rest)
{
    if (!rest)
    {
        for (unsigned int i = 0; i < output.size(); i++)
        {
            cout << output[i];
            (i < output.size() - 1) && cout << '+';
        }
        cout << endl;
    }

    for (int i = canuse; i < n && i <= rest; i++)
    {
        output.push_back(i);
        dfs(i, rest - i);
        output.pop_back();
    }

    return;
}

int main()
{
    cin >> n;

    dfs(1, n);

    return 0;
}
