#include <bits/stdc++.h>
using namespace std;
int nums[10000];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    for (int i = 0; i < m; i++)
        next_permutation(nums, nums + n);
    for (int i = 0; i < n; i++)
        cout << (double)nums[i] << (i == n - 1 ? '\n' : ' ');
    return 0;
}
