/*
n    := 1 - 1000000
k    := 1 - 1000000
A[i] := 1 - 1000
*/
#include <stdio.h>

int presum[1000001];

int main()
{
    int ans = 0, n, k, i, x;

    scanf("%d %d", &n, &k);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        presum[i] = presum[i - 1] + x;
    }

    for (int i = 1; i <= n - k; i++)
    {
        if (presum[i + k] - presum[i - 1] > ans)
            ans = presum[i + k] - presum[i - 1];
    }

    printf("%d\n", ans);
    return 0;
}
