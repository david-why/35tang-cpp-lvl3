/*
USACO 2021 February Contest, Bronze
Problem 1. Year of the Cow
*/
#include <bits/stdc++.h>

using namespace std;

const string years[] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};

int year2index(const string &s)
{
    for (int i = 0; i < 12; i++)
        if (s == years[i])
            return i;
    return -1;
}

int main()
{
    int n;
    cin >> n;
    unordered_map<string, pair<int, int>> year;
    year["Bessie"] = make_pair(0, 0);
    for (int i = 0; i < n; i++)
    {
        string tmp, name1, dir, yearof, name2;
        cin >> name1 >> tmp >> tmp >> dir >> yearof >> tmp >> tmp >> name2;
        const pair<int, int> &n2 = year[name2];
        int yearind = year2index(yearof), newyear = n2.first;
        if (dir == "next")
        {
            if (n2.second >= yearind)
                newyear += 12 - n2.second + yearind;
            else
                newyear += yearind - n2.second;
        } else {
            if (n2.second > yearind)
                newyear -= n2.second - yearind;
            else
                newyear -= 12 - yearind + n2.second;
        }
        year[name1] = make_pair(newyear, yearind);
    }

    cout << abs(year["Elsie"].first) << endl;
    return 0;
}
