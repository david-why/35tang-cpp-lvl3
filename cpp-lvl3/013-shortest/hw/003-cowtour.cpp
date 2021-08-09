#include <bits/stdc++.h>

using namespace std;

struct pos_t
{
    int x;
    int y;
};
vector<pos_t> places;
double dist[150][150];
double shortest[150][151];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        pos_t p;
        cin >> p.x >> p.y;
        places.push_back(p);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            shortest[i][j] = c == '1';
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] =
                sqrt((places[i].x - places[j].x) * (places[i].x - places[j].x) +
                     (places[i].y - places[j].y) * (places[i].y - places[j].y));
            if (shortest[i][j])
                shortest[i][j] = dist[i][j];
            else
                shortest[i][j] = 10000000001;
        }
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (shortest[i][k] + shortest[k][j] < shortest[i][j] && i != j)
                    shortest[i][j] = shortest[j][i] = shortest[i][k] + shortest[k][j];

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (shortest[i][j] != 10000000001)
    //             printf("%.06f\t", shortest[i][j]);
    //         else
    //             printf("N/A\t\t\t");
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < n; i++)
    {
        double maxdist = 0;
        for (int j = 0; j < n; j++)
            if (shortest[i][j] > maxdist && shortest[i][j] != 10000000001)
                maxdist = shortest[i][j];
        shortest[i][150] = maxdist;
    }

    // for (int i = 0; i < n; i++)
    //     cout << shortest[i][150] << endl;

    double ans = 10000000001;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (shortest[i][j] != 10000000001 || i == j)
                continue;
            double diameter = shortest[i][150] + shortest[j][150] + dist[i][j];
            for (int k = 0; k < n; k++)
                if (shortest[k][150] > diameter && k != i && k != j)
                    diameter = shortest[k][150];
            if (diameter < ans)
                ans = diameter;
            // cout << i << "=>" << j << " " << diameter << endl;
        }
    }

    printf("%.6lf\n", ans);

    return 0;
}
