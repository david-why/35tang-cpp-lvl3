/**
 * @author David
 * 
 * @brief Huffman tree genereator/encoder
 * 
 * This program will read from stdin until EOF, and use this data to generate
 * a Huffman tree (see: https://en.wikipedia.org/wiki/Huffman_coding). There will
 * be user-friendly data outputted to stderr, and the binary string that contains
 * 0's and 1's will be outputted to stdout.
 * 
 * There will also be a file named "generated.dot" in the working directory. This
 * is a Graphviz DOT language file (see https://graphviz.org/doc/info/lang.html).
 * You can use `dot -Tpng generated.dot > generated.png` to convert this into a PNG
 * image file. This image would be the Huffman tree.
 */

#include <bits/stdc++.h>

using namespace std;

struct huffman_node_t
{
    huffman_node_t *left, *right;
    char val;
    int weight;

    huffman_node_t(huffman_node_t *l, huffman_node_t *r, char v, int w) : left(l), right(r), val(v), weight(w) {}
    huffman_node_t() {}
};

struct cmp
{
    bool operator()(const huffman_node_t *a, const huffman_node_t *b)
    {
        return a->weight > b->weight;
    }
};

int counts[256];
char buf[1001];
string str;
priority_queue<huffman_node_t *, vector<huffman_node_t *>, cmp> pending;
map<char, string> mapping;

unsigned int dotindex;
vector<int> ranksames;

void dfs(huffman_node_t *node, string prefix, ostream &file)
{
    int thisindex = dotindex++;
    file << thisindex << "[label=\"";
    if (node->val)
    {
        file << "'";
        if (node->val == '"')
            file << "\\\"";
        else
            file << (unsigned char)node->val;
        file << "'*";
    }
    file << node->weight;
    if (node->left == NULL)
    {
        file << "\\n"
             << prefix;
    }
    file << "\"];";

    if (node->left != NULL)
    {
        file << thisindex << "->" << dotindex << "[label=0];";
        dfs(node->left, prefix + "0", file);
        file << thisindex << "->" << dotindex << "[label=1];";
        dfs(node->right, prefix + "1", file);
    }
    else
    {
        cerr << "'" << node->val << "' -> " << prefix << endl;
        mapping[node->val] = prefix;
        ranksames.push_back(thisindex);
    }
}

int main(int argc, char **argv)
{
    cerr << "Please enter some string, ending with EOF:" << endl;
    while (cin.read(buf, 1))
    {
        for (size_t i = 0; i < strlen(buf); i++)
            counts[(int)buf[i]]++;
        str += buf;
    }
    if (str[str.length() - 1] == '\n')
    {
        counts['\n']--;
        str = str.substr(0, str.length() - 1);
    }

    cerr << "Calculating..." << flush;

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
        huffman_node_t *newnode = new huffman_node_t(first, second, 0, first->weight + second->weight);
        pending.push(newnode);
    }

    cerr << "\nMapping:" << endl;
    ofstream dotout("generated.dot");
    dotout << "digraph G {node[shape=circle];";
    dfs(pending.top(), "", dotout);
    dotout << "{rank=same;";
    for (int i : ranksames)
        dotout << i << ";";
    dotout << "};}" << endl;
    dotout.close();
    cerr << "Encoded:" << endl;
    size_t after_encode = 0;
    for (unsigned char c : str)
    {
        cout << mapping[c];
        after_encode += mapping[c].length();
    }
    size_t len = str.length();
    cerr << endl
         << "This would use " << after_encode / 8
         << " bytes, while the original used " << len << " bytes." << endl
         << "This algorithm used " << (double)after_encode / len * 12.5
         << "% of the original space." << endl;

    return 0;
}
