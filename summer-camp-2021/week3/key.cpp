#include <vector>  // vector
#include <fstream> // ifstream, ofstream

using namespace std;

vector<int> keys[1000];
bool visited[1000];
int n;

void dfs(int now)
{
    visited[now] = true;

    for (int key : keys[now])
        if (!visited[key])
            dfs(key);
}

int main()
{
    ifstream fin("key.in");
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        fin >> k;
        for (int j = 0; j < k; j++)
        {
            int key;
            fin >> key;
            keys[i].push_back(key);
        }
    }
    fin.close();

    dfs(0);

    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans = false;
            break;
        }
    }

    ofstream fout("key.out");
    fout << (ans ? "true" : "false") << endl;
    fout.close();

    return 0;
}
