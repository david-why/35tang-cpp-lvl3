#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        unordered_set<int> us;
        bool printed = false;
        for (int j = 0; j < n; j++)
        {
            int x;
            scanf("%d", &x);
            if (!us.count(x))
            {
                us.insert(x);
                if (printed)
                    printf(" ");
                else
                    printed = true;
                printf("%d", x);
            }
        }
        printf("\n");
    }

    return 0;
}
