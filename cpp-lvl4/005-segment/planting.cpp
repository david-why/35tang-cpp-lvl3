#include <bits/stdc++.h>

using namespace std;

// #pragma region
#define p pair<int, int>
// #define rect pair<p, p>
// #define x1(i) rects[i].first.first
// #define y1(i) rects[i].first.second
// #define x2(i) rects[i].second.first
// #define y2(i) rects[i].second.second
// #pragma endregion

struct rect
{
    int x1, y1, x2, y2;
};

typedef long long ll;

rect rects[1000];
set<int> xlines;

int &x1(int i) { return rects[i].x1; }
int &y1(int i) { return rects[i].y1; }
int &x2(int i) { return rects[i].x2; }
int &y2(int i) { return rects[i].y2; }

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x1(i) >> y1(i) >> x2(i) >> y2(i);
        xlines.insert(x1(i));
        xlines.insert(x2(i));
    }

    int prev = INT_MIN;
    ll ans = 0;
    for (int x : xlines)
    {
        if (prev != INT_MIN)
        {
            ll w = x - prev;
            priority_queue<p, vector<p>, greater<p>> hs;
            for (int i = 0; i < n; i++)
            {
                if (x1(i) <= prev && x2(i) >= x)
                {
                    hs.push(make_pair(y1(i), -1));
                    hs.push(make_pair(y2(i), 1));
                }
            }
            ll h = 0;
            int ctr = 0, yp;
            while (!hs.empty())
            {
                p c = hs.top();
                hs.pop();
                if (ctr == 0)
                    yp = c.first;
                ctr -= c.second;
                if (ctr == 0)
                    h += c.first - yp;
            }
            ans += w * h;
        }
        prev = x;
    }

    cout << ans << endl;
    return 0;
}
