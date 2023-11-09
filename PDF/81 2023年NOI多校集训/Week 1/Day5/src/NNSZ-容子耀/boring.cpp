//#pragma GCC optimize(2)
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e4 + 10, P = 998244353;

typedef long long LL;

short a[1250][10010];
short st[1250][10010][15];
int primes[N], pos[N], ori[N], cnt;
bool v[N];
int n, q;

void init(int n)
{
    for (int i = 2; i <= n; ++i)
    {
        if (!v[i]) primes[++ cnt] = i;
        for (int j = 1; primes[j] <= n / i; ++j)
        {
            v[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

short ask(int k, int l, int r)
{
    int t = log2(r - l + 1);
    return max(st[k][l][t], st[k][r - (1 << t) + 1][t]);
}

int power(int a, int b)
{
    int res = 1;
    for (int i = b; i; i >>= 1)
    {
        if (i & 1) res = (LL)res * a % P;
        a = (LL)a * a % P;
    }

    return res;
}

int main()
{
    freopen("boring.in", "r", stdin);
    freopen("boring.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin >> n >> q;
    int L = 0;
    for (int i = 1; i <= n; ++i)
        cin >> ori[i], L = max(L, ori[i]);
    init(L);
    for (int i = 1; i <= cnt; ++i)
        pos[primes[i]] = i;

    for (int i = 1; i <= n; ++i)
    {
        int x = ori[i];
        for (int j = 2; j <= x / j; ++j)
            while (x % j == 0) ++ a[pos[j]][i], x /= j;
        if (x > 1) ++ a[pos[x]][i];
    }
    for (int k = 1; k <= cnt; ++k)
        for (int j = 0; j <= 14; ++j)
            for (int i = 1; i + (1 << j) - 1 <= n; ++i)
                if (j == 0) st[k][i][j] = a[k][i];
                else st[k][i][j] = max(st[k][i][j - 1], st[k][i + (1 << j - 1)][j - 1]);

    for (int i = 1; i <= q; ++i)
    {
        int k;
        cin >> k;
        static short mx[1250];
        memset(mx, 0, sizeof mx);
        while (k --)
        {
            int l, r;
            cin >> l >> r;
            for (int j = 1; j <= cnt; ++j)
                mx[j] = max(mx[j], ask(j, l, r));
        }

        int res = 1;
        for (int j = 1; j <= cnt; ++j)
            if (mx[j])
                res = (LL)res * power(primes[j], mx[j]) % P;
        cout << res << '\n';
    }
    return 0;
}
