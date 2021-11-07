from functools import reduce

n = int(input())
nums = list(map(int, input().split()))
print(
    reduce(
        list.__add__,
        (
            [
                (
                    sum(nums[i : j + 1]) % (j - i + 1) == 0
                    and sum(nums[i : j + 1]) // (j - i + 1) in nums[i : j + 1]
                )
                for j in range(i, n)
            ]
            for i in range(n)
        ),
    ).count(True)
)
