/*
USACO 2021 January Contest, Silver
Problem 3. Spaced Out
*/
#include <bits/stdc++.h>

using namespace std;

int a[1001][1001];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", a[i] + j);

    int b = 0;
    for (int c = 1; c <= n; c++)
    {
        int o = 0, e = 0;
        for (int r = 1; r <= n; r += 2)
            o += a[r][c];
        for (int r = 2; r <= n; r += 2)
            e += a[r][c];
        b += max(o, e);
    }
    int x = 0;
    for (int r = 1; r <= n; r++)
    {
        int o = 0, e = 0;
        for (int c = 1; c <= n; c += 2)
            o += a[r][c];
        for (int c = 2; c <= n; c += 2)
            e += a[r][c];
        x += max(o, e);
    }

    printf("%d\n", max(b, x));
    return 0;
}
