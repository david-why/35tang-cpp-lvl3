//老师，你的rabit拼错了，应该是rabbit :-)

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

    int rpos = 0, time = 0, prev = -1, ans = 0;
    while (true)
    {
        pair<int, int> station;
        bool found = false;
        while (!stations.empty())
        {
            station = stations.top();
            stations.pop();
            if (station.second > prev)
            {
                found = true;
                break;
            }
        }
        if (!found)
            break;
        int need = (station.second - rpos) * rr;
        time += need;
        rpos = station.second;
        // cout << "I used " << need << "s to get to station @ " << station.second << "m, now it's " << time << "s." << endl;
        // cout << "The slow turtle is now at " << rt * time << "m." << endl;
        int rest = rpos * rt - time;
        time += rest;
        int yum = rest * station.first;
        ans += yum;
        // cout << "I rested " << rest << "s here and got " << yum << " yum points." << endl;
    }

    ofstream fout("rabit.out");
    // cout << "I got " << ans << " yum points in total. Yum yum!" << endl;
    fout << ans << endl;
    fout.close();

    return 0;
}
