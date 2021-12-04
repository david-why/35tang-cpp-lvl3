#include <bits/stdc++.h>

using namespace std;

bool bought[100000];

#define noans       \
    {               \
        puts("NO"); \
        return 0;   \
    }

int pos[100001], ans[100001];

struct
{
    int prev, next, val;
} lst[200001];
int pluses;

char buf[10];

int main()
{
    int n;
    scanf("%d\n", &n);

    for (int i = 0; i < 2 * n; i++)
    {
        lst[i].prev = i - 1;
        lst[i].next = i + 1;

        fgets(buf, sizeof(buf), stdin);
        if (*buf == '-')
        {
            int x = atoi(buf + 2);
            lst[i].val = x;
            pos[x] = i;
        }
        else
        {
            lst[i].val = --pluses;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int now = pos[i], prev = lst[now].prev;
        if (prev < 0 || lst[prev].val >= 0)
            noans;
        lst[lst[now].next].prev = lst[prev].prev;
        lst[lst[prev].prev].next = lst[now].next;
        ans[-lst[prev].val - 1] = i;
    }

    puts("YES");
    for (int i = 0; i < n; i++)
    {
        printf("%d", ans[i]);
        printf(i == n - 1 ? "\n" : " ");
    }

    return 0;
}
