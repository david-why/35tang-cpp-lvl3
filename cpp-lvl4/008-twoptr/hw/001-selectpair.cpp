/*
n    := 1 - 200000
m    := 1 - 999999999
A[i] := 1 - 999999999
*/

#include <bits/stdc++.h>

using namespace std;

pair<int, int> nums[200001];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i].first;
        nums[i].second = i;
    }

    sort(nums + 1, nums + n + 1);

    int left = 1, right = n;
    while (left < right)
    {
        int a = nums[left].first, b = nums[right].first;
        if (a + b == m)
        {
            int l = nums[left].second, r = nums[right].second;
            if (l <= r)
                cout << l << " " << r << endl;
            else
                cout << r << " " << l << endl;
            return 0;
        }
        if (a + b > m)
            right--;
        else
            left++;
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
