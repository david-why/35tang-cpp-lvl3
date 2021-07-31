#include <fstream>   // ifstream, ofstream
#include <algorithm> // sort

using namespace std;

int cookies[30000], children[30000];

int main()
{
    ifstream fin("cookie.in");
    int m, n;
    fin >> m >> n;
    for (int i = 0; i < m; i++)
        fin >> cookies[i];
    for (int i = 0; i < n; i++)
        fin >> children[i];
    fin.close();

    sort(cookies, cookies + m);
    sort(children, children + n);

    int cookie = 0, ans = 0;
    for (int child = 0; child < n; child++)
    {
        while (cookies[cookie] < children[child] && cookie < m)
            cookie++;
        if (cookies[cookie] >= children[child])
        {
            ans++;
            cookie++;
        }
        else if (cookie >= m - 1)
            break;
    }

    ofstream fout("cookie.out");
    fout << ans << endl;
    fout.close();

    return 0;
}
