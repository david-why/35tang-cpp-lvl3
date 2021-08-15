#include <bits/stdc++.h>

using namespace std;

struct huffman_node_t
{
    huffman_node_t *left, *right;
    char val;
    int weight;

    huffman_node_t(huffman_node_t *l, huffman_node_t *r, char v, int w) : left(l), right(r), val(v), weight(w) {}
    huffman_node_t() : val(0) {}
};

struct cmp
{
    bool operator()(const huffman_node_t *a, const huffman_node_t *b)
    {
        return a->weight > b->weight;
    }
};

int counts[256];
string str;
priority_queue<huffman_node_t *, vector<huffman_node_t *>, cmp> pending;

void dfs(huffman_node_t *node, string prefix)
{
    if (node->left != NULL)
    {
        dfs(node->left, prefix + "0");
        dfs(node->right, prefix + "1");
    }
    else
    {
        cout << node->val << " " << prefix << endl;
    }
}

int main(int argc, char **argv)
{
    string s;
    while (cin >> s)
    {
        for (int c : s)
            counts[c]++;
        str += s;
        counts[' ']++;
    }
    counts[' ']--;

    for (short c = 0; c < 256; c++)
    {
        if (counts[c])
        {
            huffman_node_t *node = new huffman_node_t(NULL, NULL, c, counts[c]);
            pending.push(node);
        }
    }

    while (pending.size() > 1)
    {
        huffman_node_t *first = pending.top();
        pending.pop();
        huffman_node_t *second = pending.top();
        pending.pop();
        huffman_node_t *newnode = new huffman_node_t(first, second, -1, first->weight + second->weight);
        pending.push(newnode);
    }

    dfs(pending.top(), "");

    return 0;
}
