#include <fstream> // ifstream, ofstream

using namespace std;

int main()
{
    ifstream fin("arith.in");
    int n;
    fin >> n;

    int ans = 0;
    int seq_index = 0, prev = 9999, diff = 9999;
    for (int i = 0; i < n; i++)
    {
        int x;
        fin >> x;

        if (prev + diff == x)
        {
            if (++seq_index > 0)
                ans += seq_index;
        }
        else
        {
            diff = x - prev;
            seq_index = 0;
        }

        prev = x;
    }

    fin.close();

    ofstream fout("arith.out");
    fout << ans << endl;
    fout.close();

    return 0;
}
