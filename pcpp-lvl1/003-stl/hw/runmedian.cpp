#include <iostream>
#include <set>

using namespace std;

int main()
{
    int p;
    cin >> p;
    for (int _ = 0; _ < p; _++)
    {
        int n, m;
        cin >> n >> m;
        int no = m / 2 + 1;
        cout << n << " " << no << "\n";

        multiset<int> nums;
        int i;
        cin >> i;
        nums.insert(i);
        cout << i;
        int out = 1;
        for (i = 1; i < no; i++)
        {
            int x;
            cin >> x;
            nums.insert(x);
            cin >> x;
            nums.insert(x);
            multiset<int>::iterator it = nums.begin();
            for (int j = 0; j < i; j++)
                it++;
            if (out == 10)
            {
                cout << "\n";
                out = 0;
            }
            else
                cout << " ";
            cout << *it;
            out++;
        }
        cout << "\n";
    }

    return 0;
}
