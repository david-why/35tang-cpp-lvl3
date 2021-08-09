/*
ID: david_w1
TASK: comehome
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

unsigned int shortest[52][52];
bool used[52];

#define toindex(c) ((c) >= 'a' ? (26 + (c) - 'a') : ((c) - 'A'))

int main()
{
    freopen("comehome.in", "r", stdin);
    freopen("comehome.out", "w", stdout);
    for (int i = 0; i < 52; i++)
        for (int j = 0; j < 52; j++)
            shortest[i][j] = INT_MAX;
    int p;
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        char a, b;
        unsigned int d;
        cin >> a >> b >> d;
        used[toindex(a)] = used[toindex(b)] = true;
        if (d < shortest[toindex(a)][toindex(b)])
            shortest[toindex(a)][toindex(b)] = shortest[toindex(b)][toindex(a)] = d;
    }

    for (int k = 0; k < 52; k++)
        for (int i = 0; i < 52 && used[k]; i++)
            for (int j = 0; j < 52 && used[i]; j++)
                if (used[j] && shortest[i][k] + shortest[k][j] < shortest[i][j])
                    shortest[i][j] = shortest[j][i] = shortest[i][k] + shortest[k][j];

    char pasture = 'Z';
    unsigned int length = INT_MAX;
    for (int i = 0; i < 25; i++)
    {
        if (shortest[i][toindex('Z')] < length)
        {
            length = shortest[i][toindex('Z')];
            pasture = 'A' + i;
        }
    }

    cout << pasture << " " << length << endl;

    return 0;
}
