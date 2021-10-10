#include <iostream>
using namespace std;
int main()
{
    freopen("power.in", "r", stdin);
    freopen("power.out", "w", stdout);
    int n;
    cin >> n;
    if (n % 2)
    {
        cout << -1;
        return 0;
    }
    for (int i = 31; i; i--)
    {
        if (n & (1 << i))
            cout << (1 << i) << " ";
    }
    cout << endl;
    return 0;
}
