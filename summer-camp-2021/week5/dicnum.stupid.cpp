#include <fstream>   // ifstream, ofstream
#include <vector>    // vector
#include <string>    // string, to_string
#include <algorithm> // sort

using namespace std;

ifstream fin("dicnum.in");
ofstream fout("dicnum.out");

vector<string> nums;

int main()
{
    int n;
    fin >> n;

    for (int i = 1; i <= n; i++)
        nums.push_back(to_string(i));

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
        fout << nums[i] << (i == n - 1 ? "\n" : " ");

    return 0;
}
