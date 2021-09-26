/*
n    := 1 - 1000000
A[i] := 1 - 1000
*/
#include <stdio.h>
#include <limits.h>

int n;
int A[1000001];

int checkok(int s)
{
    int i, cursum = 0;

    for (i = 1; i <= n; i++)
    {
        cursum += A[i];
        if (cursum > s)
            return 0;
        if (cursum == s)
            cursum = 0;
    }
    return 1;
}

int main()
{
    int i;

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", A + i);

    for (i = 1;; i++)
    {
        if (checkok(i))
        {
            printf("%d\n", i);
            return 0;
        }
    }

    return 0;
}
