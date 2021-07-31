#include <fstream> // ifstream, ofstream

using namespace std;

struct node
{
    char val;
    char left;
    char right;
} nodes[26];
int n;

void show(const node &n, ofstream &fout)
{
    fout << n.val;
    if (n.left != '*')
        show(nodes[n.left - 'a'], fout);
    if (n.right != '*')
        show(nodes[n.right - 'a'], fout);
}

int main()
{
    ifstream fin("bintree.in");
    fin >> n;
    int root = -1;
    for (int i = 0; i < n; i++)
    {
        char val, left, right;
        fin >> val >> left >> right;
        int index = val - 'a';
        if (root == -1)
            root = index;
        nodes[index].val = val;
        nodes[index].left = left;
        nodes[index].right = right;
    }
    fin.close();

    ofstream fout("bintree.out");
    show(nodes[root], fout);
    fout.close();

    return 0;
}
