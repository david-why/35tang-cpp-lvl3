#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    size_t pt = s.find('.'), e = s.find('e');
    string x = s.substr(0, e);
    int b = atoi(s.substr(e + 1).c_str());

    x = x + string(b, '0');
    x.erase(x.begin() + pt);
    x.insert(x.begin() + pt + b, '.');
    while (*x.rbegin() == '0')
        x.erase(x.begin() + x.size() - 1);
    if (*x.rbegin() == '.')
        x.erase(x.begin() + x.size() - 1);
    while (x.size() >= 2 && *x.begin() == '0' && x[1] != '.')
        x.erase(x.begin());

    cout << x << endl;
    return 0;
}
