#include <bits/stdc++.h>

using namespace std;

ifstream fin("citystate.in");
ofstream fout("citystate.out");

#define s2i(c, s) (((((c)[0] - 'A') * 26 + ((c)[1] - 'A')) * 26 + ((s)[0] - 'A')) * 26 + ((s)[1] - 'A'))
#define rotate(i) ((i) / 26 / 26 + ((i) % (26 * 26)) * 26 * 26)

int city_state[26 * 26 * 26 * 26];

int main()
{
    int n;
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        string city, state;
        fin >> city >> state;
        city_state[s2i(city, state)]++;
    }

    int ans = 0;
    for (int i = 0; i < 26 * 26 * 26 * 26; i++)
    {
        int c = city_state[i];
        if (!c)
            continue;
        int j = rotate(i);
        if (i == j)
            continue;
        ans += c * city_state[j];
    }

    fout << (ans / 2) << endl;

    return 0;
}
