#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, n;
    cin >> a >> n;

    set<unsigned long long> b;
    b.insert(a);
    while (--n)
    {
        unsigned long long i = *b.begin();
        b.erase(i);
        b.insert(i * 2 + 1);
        b.insert(i * 3 + 1);
    }

    cout << *b.begin() << endl;

    return 0;
}
