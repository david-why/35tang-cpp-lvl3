#include <bits/stdc++.h>

using namespace std;

int n;
bitset<1024> s;

char type(int left, int right)
{
    bool z = false, o = false;
    for (int i = left; i < right; i++)
    {
        if (s[n - i - 1] == 0)
            z = true;
        else
            o = true;
        if (z && o)
            return 'F';
    }
    return z ? 'B' : 'I';
}

string dfs(int left, int right)
{
    if (left == right - 1)
        return string(1, s[n - left - 1] ? 'I' : 'B');
    int mid = left + (right - left) / 2;
    return dfs(left, mid) + dfs(mid, right) + type(left, right);
}

int main()
{
    cin >> n >> s;
    n = 1 << n;

    cout << dfs(0, n) << endl;

    return 0;
}
