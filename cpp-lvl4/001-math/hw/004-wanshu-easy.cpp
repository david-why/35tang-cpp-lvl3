// 仅供搞笑 xD
#include <bits/stdc++.h>

using namespace std;

// https://oeis.org/A000396
string nums[] = {"6", "28", "496", "8128", "33550336", "8589869056", "137438691328", "2305843008139952128", "2658455991569831744654692615953842176", "191561942608236107294793378084303638130997321548169216"};

bool ge(const string &a, const string &b)
{
    return a.length() != b.length() ? a.length() > b.length() : a >= b;
}

int main()
{
    string n;
    cin >> n;
    for (size_t i = 0; i < sizeof(nums) / 4; i++)
    {
        if (ge(nums[i], n))
            break;
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
