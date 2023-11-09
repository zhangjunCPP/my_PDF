#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int N = 510;
unordered_set<int> S[N];

int stk[N], tot, cnt;
int n, q;

void dfs(int x, int last_len)
{
//    cout << x << ' ' << last_len << endl;
    if (x == n + 1)
    {
//        for (int i = 1; i <= tot; ++i)
//            cout << stk[i] << ' ';
//        cout << endl;

        int res = 0;
        for (int i = 1; i <= tot; ++i)
            for (int j = i + 1; j <= tot; ++j)
                res += stk[i] * stk[j];
        S[n].insert(res);
        return;
    }
    if (n - x + 1 < last_len) return;

    for (int i = x + last_len; i <= n + 1; ++i)
    {
        stk[++tot] = i - x;
        dfs(i, i - x);
        -- tot;
    }
}

int main()
{
    freopen("stick.in", "r", stdin);
    freopen("stick.out", "w", stdout);
    ios::sync_with_stdio(false);

    cin >> q;
    for (n = 1; n <= 50; ++n)
        dfs(1, 1);
    while (q --)
    {
        int a, b;
        cin >> a >> b;
        cout << "01"[S[a].count(b)] << '\n';
    }
    return 0;
}
