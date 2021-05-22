#include <bits/stdc++.h>

using namespace std;

#define P(x) (farmers[x].price)
#define A(x) (farmers[x].amount)

struct farmer
{
    short price;
    int amount;
    static bool cmp(const farmer &a, const farmer &b)
    {
        return a.price < b.price;
    }
} farmers[5000];

int main()
{
    int n, price = 0;
    short m;

    cin >> n >> m;
    for (short i = 0; i < m; i++)
    {
        cin >> P(i) >> A(i);
    }

    sort(farmers, farmers + m, farmer::cmp);
    for (short f = 0; f < m && n; f++)
    {
        int tmp = A(f) < n ? A(f) : n;
        n -= tmp;
        price += tmp * P(f);
    }

    cout << price << endl;

    return 0;
}
