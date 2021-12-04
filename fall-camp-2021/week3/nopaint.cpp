/*
USACO 2021 January Contest, Silver
Problem 2. No Time to Paint
*/
/* Answer's algorithm, AC */
#include <bits/stdc++.h>

using namespace std;

string s;
int n, q, pref[100001], suff[100001];

template <typename Iter>
void make_lst(Iter begin, int *lst)
{
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        char c = *begin;
        lst[i + 1] = lst[i];
        while (!st.empty() && st.top() > c)
            st.pop();
        if (st.empty() || st.top() < c)
        {
            st.push(c);
            lst[i + 1]++;
        }
        begin++;
    }
}

int main()
{
    cin >> n >> q >> s;
    make_lst(s.begin(), pref);
    make_lst(s.rbegin(), suff);

    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << pref[x - 1] + suff[n - y] << endl;
    }

    return 0;
}
