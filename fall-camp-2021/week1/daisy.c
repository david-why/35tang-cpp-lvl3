#include <stdio.h>
#include <string.h>

#define maxn 100
#define maxp 1000

int nums[maxn + 1];
unsigned char visited[maxp + 1];

int main()
{
    int n, i, j, k, ans, m = 0;

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", nums + i);
        if (nums[i] > m)
            m = nums[i];
    }

    ans = n;
    for (i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        visited[nums[i]] = 1;
        int sum = nums[i];
        for (j = i + 1; j <= n; j++)
        {
            int diff = j - i + 1;
            sum += nums[j];
            visited[nums[j]] = 1;
            if (sum % diff)
                continue;
            if (visited[sum / diff])
                ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}
