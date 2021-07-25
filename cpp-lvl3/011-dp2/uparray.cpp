#include <bits/stdc++.h>

using namespace std;

map<int, int> nums;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int maxi = 0;
        for (map<int, int>::iterator it = nums.begin(); it != nums.end(); it++)
            if (it->first < x && it->second > maxi)
                maxi = it->second;
        maxi++;
        nums[x] = maxi;
        if (maxi > ans)
            ans = maxi;
    }

    cout << ans << endl;

    return 0;
}
