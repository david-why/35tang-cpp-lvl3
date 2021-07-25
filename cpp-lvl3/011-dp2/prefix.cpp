/*
ID: david_w1
TASK: prefix
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

struct node
{
    bool end;
    map<char, node *> m;
    node() : end(false) {}
} root;

bool canreach[200001];

void insert(const char str[])
{
    node *now = &root;
    for (size_t i = 0; i < strlen(str); i++)
    {
        char c = str[i];
        if (now->m.find(c) == now->m.end())
            now->m[c] = new node;
        now = now->m[c];
    }
    now->end = true;
}

int main()
{
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
    char in[77] = "";
    while (strcmp(in, "."))
    {
        cin >> in;
        insert(in);
    }

    string str;
    while (cin >> in)
        str.append(in);

    int m = 0;
    canreach[0] = true;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!canreach[i])
            continue;
        int j = i;
        node *now = &root;
        while (now->m.find(str[j]) != now->m.end())
        {
            now = now->m[str[j]];
            j++;
            if (now->end)
            {
                canreach[j] = true;
                if (j > m)
                    m = j;
            }
        }
    }

    cout << m << endl;

    return 0;
}
