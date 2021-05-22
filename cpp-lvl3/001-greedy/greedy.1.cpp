#include <iostream>
#include <algorithm>

using namespace std;

struct numbers
{
    short pos;
    short val;
} row[1001], col[1001];

bool mycmp(numbers a, numbers b)
{
    return a.val > b.val;
}

int main()
{
    short M, N, K, L, D;
    for (int i = 0; i < 1001; i++)
    {
        row[i].pos = i;
        row[i].val = 0;
        col[i].pos = i;
        col[i].val = 0;
    }

    cin >> M >> N >> K >> L >> D;
    for (int p = 0; p < D; p++)
    {
        short i1, j1, i2, j2;

        cin >> i1 >> j1 >> i2 >> j2;

        if (i1 == i2)
        {
            col[j1 < j2 ? j1 : j2].val++;
        }
        else
        {
            row[i1 < i2 ? i1 : i2].val++;
        }
    }

    sort(row + 1, row + N + 1, mycmp);
    sort(col + 1, col + M + 1, mycmp);

    for (int r = 1; r <= K; r++)
    {
        cout << row[r].pos << (r == K ? "" : " ");
    }
    cout << "\n";
    for (int c = 1; c <= L; c++)
    {
        cout << col[c].pos << (c == L ? "" : " ");
    }
    cout << "\n";

    return 0;
}
