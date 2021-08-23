#include <bits/stdc++.h>

using namespace std;

string s;
int ans = INT_MAX;

void dfs(size_t i, int times, string buf)
{
    // cout << "dfs " << i << " " << times << " \"" << buf << "\"" << endl;
    if (i == s.length())
    {
        ans = min(ans, times);
        return;
    }
    char color = s[i];
    if (buf[i] == color)
        return dfs(i + 1, times, buf);
    times++;
    for (size_t k = i; k < s.length(); k++)
    {
        buf[k] = color;
        dfs(i + 1, times, buf);
    }
}

int main()
{
    cin >> s;

    string buf(s.length(), ' ');
    dfs(0, 0, buf);
    cout << ans << endl;

    return 0;
}
