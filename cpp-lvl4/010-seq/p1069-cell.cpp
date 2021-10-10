#include <bits/stdc++.h>

using namespace std;

struct factors
{
    unordered_map<int, int> f;
    factors(int n)
    {
        int b = n;
        for (int i = 2; i*i <= b; i++)
        {
            while (n % i == 0)
            {
                f[i]++;
                n /= i;
            }
        }
        if (n != 1) f[n]++;
    }
    unordered_map<int, int>::const_iterator begin() const
    {
        return f.begin();
    }
    unordered_map<int, int>::const_iterator end() const
    {
        return f.end();
    }
    int hasall(factors& x) const
    {
        int m = 0;
        for (const pair<int, int>& p : f)
        {
            int i = x.f[p.first];
            if (!i)
                return -1;
            m = max(m, (p.second + i-1) / i);
        }
        return m;
    }
    void operator*=(const factors& x)
    {
        for (const pair<int, int>& p : x.f)
            f[p.first] += p.second;
    }
    void operator<<=(int x)
    {
        for (pair<const int, int>& p : f)
            p.second *= x;
    }
    bool operator>(const factors& x)
    {
        for (const pair<int, int>& p : x.f)
        {
            if (p.second > f[p.first])
                return false;
        }
        return true;
    }
};

ostream& operator<<(ostream& out, factors& f)
{
    bool done = false;
    for (const pair<int, int>& p : f.f)
    {
        if (done) out << "*";
        out << p.first << "^" << p.second;
        done = true;
    }
    return out;
}

int main()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    factors f(m1);
    f <<= m2;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        factors t(1);
        factors si(x);
        int val;
        if ((val=f.hasall(si)) == -1)
            continue;
        if (val < ans) ans = val;
    }
    cout << (ans == INT_MAX ? -1 : ans) << endl;
    return 0;
}

