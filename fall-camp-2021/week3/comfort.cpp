#include <bits/stdc++.h>

using namespace std;

const int mx[] = {0, 0, 1, -1}, my[] = {1, -1, 0, 0};

char cows[1002][1002];

int main()
{
    int n;
    scanf("%d", &n);
    // unordered_map<int, int> cows;
    memset(cows, -1, sizeof(cows));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        char &num = cows[x][y];
        num = 0;
        for (int j = 0; j < 4; j++)
        {
            int nx = x + mx[j], ny = y + my[j];
            if (nx >= 0 && ny >= 0 && cows[nx][ny] != -1)
            {
                num++;
                cows[nx][ny]++;
                if (cows[nx][ny] == 3)
                    ans++;
                else if (cows[nx][ny] == 4)
                    ans--;
            }
        }
        if (num == 3)
            ans++;
        printf("%d\n", ans);
    }
    return 0;
}
