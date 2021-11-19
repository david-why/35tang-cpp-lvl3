#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int even = 0, odd = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        (x % 2 ? odd : even)++;
    }

    bool iseven = true;
    int g;
    for (g = 0;; g++)
    {
        if (iseven)
        {
            if (even)
                even--;
            else if (odd >= 2)
                odd -= 2;
            else
                break;
        }
        else
        {
            if (odd)
                odd--;
            else
                break;
        }
        iseven = !iseven;
    }

    if (odd % 2)
        g--;
    cout << g << endl;
    return 0;
}
