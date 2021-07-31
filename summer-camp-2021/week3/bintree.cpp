#include <fstream> // ifstream, ofstream
#include <map>     // map
#include <utility> // pair, make_pair

using namespace std;

map<char, pair<char, char>> nodes;
int n;

void show(char c, ofstream &fout)
{
    if (c == '*')
        return;

    fout << c;
    show(nodes[c].first, fout);
    show(nodes[c].second, fout);
}

int main()
{
    ifstream fin("bintree.in");
    fin >> n;
    char root = 0;
    for (int i = 0; i < n; i++)
    {
        char val, left, right;
        fin >> val >> left >> right;
        if (root == 0)
            root = val;
        nodes[val] = make_pair(left, right);
    }
    fin.close();

    ofstream fout("bintree.out");
    show(root, fout);
    fout.close();

    return 0;
}
