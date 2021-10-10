#include <bits/stdc++.h>

using namespace std;

enum logicop
{
    noop   = 0,
    op_and = 1,
    op_or  = 2,
    op_not = 3
};

struct Node
{
    logicop op;
    bool val;
    Node* parent;
    Node* left;
    Node* right;
    Node(logicop op, bool val, Node* left = nullptr, Node* right = nullptr) : op(op), val(val), parent(nullptr), left(left), right(right) {}
    Node(bool val = false) : op(noop), val(val), parent(nullptr), left(nullptr), right(nullptr) {}
};

char expr[1000001];
Node* vars[100001];

int main()
{
    cin.getline(expr, 1000001);
    int n, q;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        bool v;
        cin >> v;
        vars[i] = new Node(v);
    }
    stringstream ss(expr);
    stack<Node*> st;
    string e;
    while (ss >> e)
    {
        if (e == "&")
        {
            Node* a = st.top();
            st.pop();
            Node* b = st.top();
            st.pop();
            Node* node = new Node(op_and, a->val & b->val, a, b);
            a->parent = node;
            b->parent = node;
            st.push(node);
        }
        else if (e == "|")
        {
            Node* a = st.top();
            st.pop();
            Node* b = st.top();
            st.pop();
            Node* node = new Node(op_or, a->val | b->val, a, b);
            a->parent = node;
            b->parent = node;
            st.push(node);
        }
        else if (e == "!")
        {
            Node* a = st.top();
            st.pop();
            Node* node = new Node(op_not, !a->val, a);
            a->parent = node;
            st.push(node);
        }
        else
        {
            st.push(vars[stoi(e.substr(1).c_str()) - 1]);
        }
    }
    Node* root = st.top();
    st.pop();
    assert(st.empty() && "Invalid data");

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        Node* now = vars[x - 1];
        bool val = !now->val;
        while (now->parent != nullptr)
        {
            Node* parent = now->parent;
            Node* other = (now == parent->left ? parent->right : parent->left);
            if (parent->op == op_and)
                val = val & other->val;
            else if (parent->op == op_or)
                val = val | other->val;
            else
                val = !val;
            if (val == parent->val)
            {
                val = root->val;
                break;
            }
            now = parent;
        }
        cout << val << '\n';
    }
    return 0;
}
