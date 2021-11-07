#include <stdio.h>

#define maxn 100

int presum[maxn + 1], nums[maxn + 1];

int main()
{
    int n, i, j, k, ans;

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", nums + i);
        presum[i] = presum[i - 1] + nums[i];
    }

    ans = n;
    for (i = 1; i <= n; i++)
    {
        for (j = i + 1; j <= n; j++)
        {
            int sum = presum[j] - presum[i - 1], diff = j - i + 1, avg, isans = 0;
            if (sum % diff)
                continue;
            avg = sum / diff;
            for (int k = i; k <= j; k++)
                if (nums[k] == avg)
                    isans = 1;
            if (isans)
                ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}
