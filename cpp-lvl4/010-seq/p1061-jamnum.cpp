#include <bits/stdc++.h>

using namespace std;

char n[26];

int main()
{
    char s, t;
    int w;
    cin >> (int&)s >> (int&)t >> w;
    s += 'a'-1; t += 'a'-1;
    cin >> n;
    for (int i = 0; i < 5; i++)
    {
        int now = w - 1;
        n[now]++;
        while (now >= 0 && n[now] > (t - (w - now - 1)))
        {
            n[now] = s;
            now--;
            n[now]++;
        }
        //cout << "--" << n << "--" << endl;
        if (now < 0) break;
        while (now < w - 1 && n[now] <= t)
        {
            now++;
            n[now] = n[now-1]+1;
        }
        //cout << "--" << n << "--" << endl;
        if (n[now] > t) break;
        cout << n << endl;
    }
    return 0;
}

