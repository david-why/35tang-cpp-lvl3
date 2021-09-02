#include <bits/stdc++.h>

using namespace std;

string rootfirst, rootmid, rootlast;

void dfs(string rootmid, string rootlast)
{
    size_t len = rootmid.length();
    if (len == 0)
        return;
    char root = rootlast[len - 1];
    size_t offset = rootmid.find(root);
    rootfirst += root;
    dfs(rootmid.substr(0, offset), rootlast.substr(0, offset));
    dfs(rootmid.substr(offset + 1), rootlast.substr(offset, len - offset - 1));
}

int main()
{
    cin >> rootmid >> rootlast;

    dfs(rootmid, rootlast);

    cout << rootfirst << endl;

    return 0;
}
