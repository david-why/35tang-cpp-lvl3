#include <bits/stdc++.h>

using namespace std;

int scores[100001], scoreslen;

void insertval(int *list, int len, int val)
{
    int left = 0, right = len;
    int mid = left;
    while (left < right)
    {
        mid = (right + left) / 2;
        if (list[mid] < val)
            left = mid + 1;
        else
            right = mid;
    }
    if (len - mid > 0)
        memmove(list + mid + 1, list + mid + 0, sizeof(int)*(len - mid - 0));
    list[left + 0] = val;
}

int main()
{
    int n, w;
    cin >> n >> w;

    for (int i = 1; i <= n; i++)
    {
        int score;
        cin >> score;
        insertval(scores, scoreslen, score);
        scoreslen++;
        cout << scores[scoreslen - max(1, i * w / 100)] << (i == n ? '\n' : ' ');
    }

    return 0;
}
