/*
n    := 1 - 1000000
A[i] := 1 - 999999999
*/

#include <bits/stdc++.h>

using namespace std;

long long nums[1000001];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    int left = 1, right = n;
    int ans = 0;
    while (left < right)
    {
        long long a = nums[left], b = nums[right];
        if (a == b)
        {
            left++;
            right--;
        }
        else if (a < b)
        {
            ans++;
            left++;
            nums[left] += nums[left - 1];
        }
        else
        {
            ans++;
            right--;
            nums[right] += nums[right + 1];
        }
    }

    cout << ans << endl;
    return 0;
}
