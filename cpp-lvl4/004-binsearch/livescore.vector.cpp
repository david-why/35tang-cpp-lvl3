#include <bits/stdc++.h>

using namespace std;

vector<int> scores;

int main()
{
    int n, w;
    cin >> n >> w;

    for (int i = 1; i <= n; i++)
    {
        int score;
        cin >> score;
        scores.push_back(score);
        sort(scores.begin(), scores.end());
        // cout << "(" << i << ", " << i * w / 100 << ")" << endl;
        cout << scores[scores.size() - max(1, i * w / 100)] << (i == n ? '\n' : ' ');
    }

    return 0;
}
