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
    }

    ofstream fout("rabit.out");
    fout << ans << endl;
    fout.close();

    return 0;
}
