/*
n    := 1 - 10000
k    := ???
A[i] := ???
*/

#include <bits/stdc++.h>

using namespace std;

deque<pair<int, int>> nums;

int main()
{
    int n, k;
    cin >> n >> k;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        while (!nums.empty() && nums.back().second < x)
            nums.pop_back();
        nums.push_back(make_pair(i, x));
        while (!nums.empty() && nums.front().first <= i - k)
            nums.pop_front();
        if (nums.front().second == x)
            ans++;
    }

    cout << ans << endl;
    return 0;
}
