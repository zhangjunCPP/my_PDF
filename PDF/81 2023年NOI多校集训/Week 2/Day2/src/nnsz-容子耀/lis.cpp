#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5e5 + 10;

vector<int> to[N];

int n, v;
int c[N], seq[N], tot;

bool dfs(int x, int fa, int mid)
{
//    for (int i = 1; i <= tot; ++i)
//        cout << seq[i] << ' ';
//    cout << endl;
    bool res = true;
    for (auto i : to[x])
    {
        if (i == fa) continue;
        if (i == v) continue;

        if (c[i] > seq[tot])
        {
            if (tot >= mid)
            {
                if (v == -1)
                {
                    v = i;
                    continue;
                }
//                else return cout << x << ' ' << i << ' ' << v << endl, false;
                else return false;
            }
            seq[++ tot] = c[i];
            res &= dfs(i, x, mid);
            -- tot;
        }
        else
        {
            int pos = lower_bound(seq + 1, seq + 1 + tot, c[i]) - seq;
            if (pos <= tot)
            {
                int t = seq[pos];
                seq[pos] = c[i];
                dfs(i, x, mid);
                seq[pos] = t;
            }
        }
    }

    return res;
}

bool check(int mid)
{
    bool res = true;
    v = -1;
    for (int i = 1; i <= n; ++i)
    {
        if (i == v)
        {
            v = -1;
            seq[++ tot] = c[i];
            res &= dfs(i, 0, mid);
            tot = 0;
            v = i;
            continue;
        }
        seq[++ tot] = c[i];
        res &= dfs(i, 0, mid);
        tot = 0;
    }

    return res;
}

int main()
{
    freopen("lis.in", "r", stdin);
    freopen("lis.out", "w", stdout);

    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) cin >> c[i];

//    cout << check(2) << endl;

    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << endl;
    return 0;
}
