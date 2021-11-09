#include <bits/stdc++.h>

using namespace std;

#define maxn 1000

#define x first
#define y second
pair<int, int> horizcows[maxn], vertcows[maxn];
int horizate[maxn], vertate[maxn];
int horizblame[maxn], vertblame[maxn];
int horizblames[maxn], vertblames[maxn];
int horizcnt, vertcnt;
bool isvert[maxn];

struct intersect
{
    int time, vert, horiz;
    bool killvert;

    bool operator>(const intersect &other) const
    {
        return time > other.time;
    }
};

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c;
        int x, y;
        cin >> c >> x >> y;
        pair<int, int> &cow = c == 'N' ? vertcows[vertcnt++] : horizcows[horizcnt++];
        cow.first = x;
        cow.second = y;
        isvert[i] = c == 'N';
    }

    priority_queue<intersect, vector<intersect>, greater<intersect>> pq;

    for (int h = 0; h < horizcnt; h++)
    {
        for (int v = 0; v < vertcnt; v++)
        {
            pair<int, int> &horiz = horizcows[h], &vert = vertcows[v];
            if (horiz.y < vert.y || vert.x < horiz.x)
                continue;
            int ydiff = horiz.y - vert.y, xdiff = vert.x - horiz.x;
            intersect inter{0, v, h};
            if (ydiff > xdiff)
            {
                inter.killvert = true;
                inter.time = ydiff;
            }
            else if (xdiff > ydiff)
            {
                inter.killvert = false;
                inter.time = xdiff;
            }
            else
                continue;
            pq.push(inter);
        }
    }

    while (!pq.empty())
    {
        const intersect &inter = pq.top();
        int t = inter.time, h = inter.horiz, v = inter.vert;
        bool killvert = inter.killvert;
        pq.pop();
        if (killvert)
        {
            if ((horizate[h] && horizate[h] + horizcows[h].x < vertcows[v].x) || vertate[v])
                continue;
            vertate[v] = t;
            vertblame[v] = h + 1;
        }
        else
        {
            if ((vertate[v] && vertate[v] + vertcows[v].y < horizcows[h].y) || horizate[h])
                continue;
            horizate[h] = t;
            horizblame[h] = v + 1;
        }
    }

    auto fblames = [&]() // ;)
    {
        int vert = 0, horiz = 0;
        for (int i = 0; i < n; i++)
        {
            int blame = isvert[i] ? vertblame[vert++] : horizblame[horiz++];
            bool iv = !isvert[i];
            while (blame)
            {
                (iv ? vertblames : horizblames)[--blame]++;
                blame = (iv ? vertblame : horizblame)[blame];
                iv = !iv;
            }
        }
    };
    fblames();

    int vert = 0, horiz = 0;
    for (int i = 0; i < n; i++)
    {
        if (isvert[i])
        {
            cout << vertblames[vert++] << "\n";
        }
        else
        {
            cout << horizblames[horiz++] << "\n";
        }
    }
    return 0;
}
