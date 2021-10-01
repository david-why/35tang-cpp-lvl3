/*
n    := 1 - 1000000
A[i] := 1 - 1000
*/
#include <stdio.h>
#include <limits.h>

int n;
int A[1000001];
int presum[1000001];

int checkok(int s)
{
    int i, tm = 0;

    for (i = 1; i <= n; i++)
    {
        if (presum[i] - tm > s)
            return 0;
        if (presum[i] - tm == s)
            tm = presum[i];
    }

    return presum[n] == tm;
}

int main()
{
    int i;

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", A + i);
        presum[i] = presum[i - 1] + A[i];
    }

    for (i = 1;; i++)
    {
        if (presum[n] % i == 0 && checkok(i))
        {
            printf("%d\n", i);
            return 0;
        }
    }

    return 0;
}
