/*
n    := 1 - 200000
m    := 1 - 999999999
A[i] := 1 - 999999999
*/

#include <bits/stdc++.h>

using namespace std;

int nums[200001];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    sort(nums + 1, nums + n + 1);

    int left = 1, right = n;
    while (left < right)
    {
        int a = nums[left], b = nums[right];
        if (a + b == m)
        {
            cout << left << " " << right << endl;
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
