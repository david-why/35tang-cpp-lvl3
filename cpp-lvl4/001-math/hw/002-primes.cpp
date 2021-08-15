#include <bits/stdc++.h>

using namespace std;

int notprime[5000001];
vector<int> primes;

int main()
{
    int n;
    cin >> n;

    for (int i = 2; i < n; i++)
    {
        int end = notprime[i] ? notprime[i] : i;
        if (!notprime[i])
            primes.push_back(i);

        int p, t;
        for (size_t j = 0; (p = primes[j]) <= end && j < primes.size() && (t = p * i) <= n; j++)
            notprime[t] = p;
    }

    cout << primes.size() << endl;

    return 0;
}
