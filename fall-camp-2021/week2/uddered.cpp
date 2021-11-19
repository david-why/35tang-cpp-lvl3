#include <bits/stdc++.h>

using namespace std;

int char2index[26];

int main()
{
    string a, s;
    cin >> a >> s;

    int i = 1;
    for (char c : a)
        char2index[c - 'a'] = i++;

    int ans = 1, curindex = 0;
    for (char c : s)
    {
        if (char2index[c - 'a'] <= curindex)
            ans++;
        curindex = char2index[c - 'a'];
    }

    cout << ans << endl;
    return 0;
}
