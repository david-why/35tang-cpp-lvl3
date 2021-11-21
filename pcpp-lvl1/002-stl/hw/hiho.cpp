#include <bits/stdc++.h>

using namespace std;

#define maxn 30000

struct student
{
    int a, b, c, d, e;

    bool operator<(const student &x)
    {
        return a < x.a && b < x.b && c < x.c && d < x.d && e < x.e;
    }
} students[maxn];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> students[i].a >> students[i].b >> students[i].c >> students[i].d >> students[i].e;

    for (int i = 0; i < n; i++)
    {
        int ans = 0;
        for (int j = 0; j < n; j++)
            if (students[j] < students[i])
                ans++;
        cout << ans << "\n";
    }

    return 0;
}
