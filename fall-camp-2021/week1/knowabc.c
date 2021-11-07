#include <stdio.h>
#include <stdlib.h>

int compar(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

int main(void)
{
    int nums[7];
    scanf("%d %d %d %d %d %d %d", nums, nums + 1, nums + 2, nums + 3, nums + 4, nums + 5, nums + 6);
    qsort(nums, 7, sizeof(int), compar);
    printf("%d %d %d\n", nums[0], nums[1], nums[6] - nums[0] - nums[1]);
    return 0;
}
