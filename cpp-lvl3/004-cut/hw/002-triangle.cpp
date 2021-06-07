/*
等边三角形
输入一个整数n(<10),后面一行n个空格隔开的数字，表示n个木棒长度。
输出：如果这些木棒全部用上可以拼成一个等边三角形，输出 “OK” 否则输出“NO”
示例输入：
5
1 2 3 4 5
示例输出
OK
说明：这个例子种，5个木棒可以组成边长5的等边三角形，用长度5的单独一个边，
长度2和3的合起来做成一个边，长度1和4的合起来组成另外一个边。
*/

#include <bits/stdc++.h>

using namespace std;

int n, sticks[10], total = 0, side;
bool used[10] = {false};

/* @param sides: # of sides already done */
/* @param now: # of units already have in this side */
bool dfs(int sides, int now)
{
    if (sides == 2)
    {
        return true;
    }

    for (int i = 0; i < n; i++)
    {
        if (used[i] || (now + sticks[i]) > side)
        {
            continue;
        }
        used[i] = true;
        if (now + sticks[i] == side)
        {
            if (dfs(sides + 1, 0))
            {
                return true;
            }
        }
        else
        {
            if (dfs(sides, now + sticks[i]))
            {
                return true;
            }
        }
        used[i] = false;
    }

    return false;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> sticks[i];
        total += sticks[i];
    }

    side = total / 3;
    if (!(total % 3) && dfs(0, 0))
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
