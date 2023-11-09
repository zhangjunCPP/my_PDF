#include <set>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10, M = 2e5 + 10;

int n, m;
bool v[N];
int in[N], out[N];
int h[N], ne[M], e[M], idx;
set<PII> S;
vector<int> path;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int x)
{
    v[x] = true;
    for (int i = h[x]; ~i; i = ne[i])
    {
        int y = e[i];
        if (!v[y])
        {
            path.push_back(y);
            dfs(y);
        }
    }
}

int main()
{
    freopen("hamilton.in", "r", stdin);
    freopen("hamilton.out", "w", stdout);
    ios::sync_with_stdio(false);

    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (S.count({a, b})) continue;
        S.insert({a, b});
        add(a, b);
        ++ in[b], ++ out[a];
    }
    for (int i = 1; i <= n; ++i)
        if (!in[i] || !out[i])
            return cout << "NO\n", 0;

    cout << "YES\n";
    for (int i = 1; i <= n; ++i)
    {
        if (v[i]) continue;

        path.clear();
        path.push_back(i);
        dfs(i);

        cout << path.size() << ' ';
        for (auto i : path)
            cout << i << ' ';
        cout << '\n';
    }
    return 0;
}
