#include <bits/stdc++.h>

using namespace std;

int n;
bool used[10];
vector<int> output;

void dfs(int rest)
{
    if (rest == 0)
    {
        for (int i : output)
        {
            cout << setw(5) << i;
        }
        cout << endl;
        return;
    }

    rest--;
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            output.push_back(i);
            dfs(rest);
            output.pop_back();
            used[i] = false;
        }
    }

    return;
}

int main()
{
    cin >> n;

    dfs(n);

    return 0;
}
