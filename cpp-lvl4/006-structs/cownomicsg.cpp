#include <bits/stdc++.h>

using namespace std;

ifstream fin("cownomics.in");
ofstream fout("cownomics.out");

string spotty[500], plain[500];

int n, m;

bool checkok(int len)
{
    for (int start = 0; start <= (m - len); start++)
    {
        set<string> seen;
        for (int i = 0; i < n; i++)
            seen.insert(spotty[i].substr(start, len));
        bool isok = true;
        for (int i = 0; i < n; i++)
        {
            if (seen.find(plain[i].substr(start, len)) != seen.end())
            {
                isok = false;
                break;
            }
        }
        if (isok)
            return true;
    }
    return false;
}

int main()
{
    fin >> n >> m;
    for (int i = 0; i < n; i++)
        fin >> spotty[i];
    for (int i = 0; i < n; i++)
        fin >> plain[i];

    int ans = INT_MAX;
    int left = 3, right = m;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (checkok(mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    fout << ans << endl;

    return 0;
}
