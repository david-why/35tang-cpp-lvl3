#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    // {time, price}
    deque<pair<int, int>> coupons;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        int is_bus, price, time;
        cin >> is_bus >> price >> time;
        if (is_bus)
        {
            bool pay = true;
            while (!coupons.empty() && coupons.front().first < time)
            {
                coupons.pop_front();
            }
            deque<pair<int, int>>::iterator it;
            for (it = coupons.begin(); it != coupons.end(); it++)
            {
                pair<int, int> coupon = *it;
                if (coupon.second < price)
                    continue;
                pay = false;
                break;
            }
            if (pay)
                total += price;
            else
                coupons.erase(it);
        }
        else
        {
            total += price;
            coupons.push_back(make_pair(time + 45, price));
        }
    }

    cout << total << endl;

    return 0;
}
