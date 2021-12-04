#include <bits/stdc++.h>

using namespace std;

int angleof(char c)
{
    if (c == 'N')
        return 0;
    if (c == 'E')
        return 1;
    if (c == 'S')
        return 2;
    return 3;
}
int diff(int a, int b)
{
    if ((a + 1) % 4 == b)
        return 1;
    if ((a + 3) % 4 == b)
        return -1;
    return 0;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        size_t x = s.size();
        int ang = 0;
        for (int i = 0; i < x; i++)
        {
            char c = s[i], p = s[i == 0 ? (x - 1) : (i - 1)];
            ang += diff(angleof(p), angleof(c));
        }
        if (ang > 0)
            cout << "CW";
        else
            cout << "CCW";
        cout << "\n";
    }
    return 0;
}
