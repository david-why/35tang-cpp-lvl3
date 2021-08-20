#include <fstream> // ifstream, ofstream
#include <vector>  // vector
#include <unordered_set>     // unordered_set

using namespace std;

ifstream fin("selectp.in");
ofstream fout("selectp.out");

int n, k;
vector<int> nums;
unordered_set<int> primes;

bool isprime(int num)
{
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0)
            return false;
    return true;
}

void dfs(int nowsum, int selnext, int needsel)
{
    if (needsel == 0)
    {
        if (isprime(nowsum))
            primes.insert(nowsum);
        return;
    }

    for (int i = selnext; i < n; i++)
        dfs(nowsum + nums[i], i + 1, needsel - 1);
}

int main()
{
    fin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        fin >> x;
        nums.push_back(x);
    }

    dfs(0, 0, k);
    
    fout << primes.size() << endl;

    return 0;
}
