#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5e5 + 10;

int n;
int a[N], f[N], g[N], pre[N];

int main()
{
    freopen("comb.in", "r", stdin);
    freopen("comb.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    memset(f, 0xcf, sizeof f);
    f[1] = f[2] = f[3] = 0;
    pre[a[1]] = 1, pre[a[2]] = 2, pre[a[3]] = 3;
    for (int i = 4; i <= n; ++i)
    {
//        for (int j = 1; j < i; ++j)
//            for (int k = j + 1; k < i; ++k)
//                for (int l = k + 1; l < i; ++l)
//                    if (a[j] == a[l] && a[k] == a[i])
//                        f[i] = max(f[i], g[j - 1] + 1);

        for (int j = i - 1; j >= 1; --j)
            if (pre[a[j]] > j)
                if (pre[a[i]] < pre[a[j]])
                {
                    f[i] = g[j - 1] + 1;
                    break;
                }

        pre[a[i]] = i;
        g[i] = max(g[i - 1], f[i]);
    }

    cout << g[n] * 4 << endl;
    return 0;
}
