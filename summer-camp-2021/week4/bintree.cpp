#include <fstream> // ifstream, ofstream
#include <map>     // map
#include <cmath>   // sqrt

using namespace std;

#define MOD 1000000007

map<int, int> nums;

int main()
{
    ifstream fin("bintree.in");
    int n;
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        fin >> x;
        nums[x] = 1;
    }
    fin.close();

    int ans = 0;
    for (map<int, int>::iterator it = nums.begin(); it != nums.end(); it++)
    {
        int i = (*it).first;
        double s = sqrt(i);
        for (map<int, int>::iterator it2 = nums.begin(); (*it2).first <= s; it2++)
        {
            if (i % (*it2).first == 0 && nums.find(i / (*it2).first) != nums.end())
            {
                if ((*it2).first * (*it2).first == i)
                    (*it).second = ((*it).second + (*it2).second * (*it2).second % MOD) % MOD;
                else
                    (*it).second = ((*it).second + 2 * (*it2).second * nums[i / (*it2).first] % MOD) % MOD;
            }
        }
        ans = (ans + (*it).second) % MOD;
    }

    ofstream fout("bintree.out");
    fout << ans << endl;
    fout.close();
}
