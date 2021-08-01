#include <fstream> // ifstream, ofstream
#include <queue>   // priority_queue
#include <utility> // pair, make_pair

using namespace std;

int main()
{
    ifstream fin("rabit.in");
    int L, N, rt, rr;
    fin >> L >> N >> rt >> rr;
    priority_queue<pair<int, int>> stations;
    for (int i = 0; i < N; i++)
    {
        int x, c;
        fin >> x >> c;
        stations.push(make_pair(c, x));
    }

    int rpos = 0, time = 0;
    unsigned long long ans = 0;
    while (!stations.empty())
    {
        pair<int, int> station;
        station = stations.top();
        stations.pop();
        if (station.second < rpos)
            continue;

        int need = (station.second - rpos) * rr;
        time += need;
        rpos = station.second;
        int rest = rpos * rt - time;
        time += rest;
        int yum = rest * station.first;
        ans += yum;
        /**
         * 之所以在这里使用了“逻辑有点复杂”的模拟，是因为我认为这样是最容易理解的。
         * 更何况性能也没有太大的影响。
         * 代码的逻辑越容易理解，越简单，出错的可能性就越小。
         * 这是我的思路。
         */
    }

    ofstream fout("rabit.out");
    fout << ans << endl;
    fout.close();

    return 0;
}
