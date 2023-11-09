#include <cstdio>
#include <bitset>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20;

int n, cnt;
int a[N], p[N], Map[1 << N], lup[N], rup[N], ldown[N], rdown[N];

void dfs(int x, int v)
{
//    cout << x << ' ' << bitset<7>(v) << endl;
    if (x == n + 1)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (p[i] == p[i - 1] + 1) lup[i] = lup[i - 1] + 1;
            else lup[i] = 1;
            if (p[i] == p[i - 1] - 1) ldown[i] = ldown[i - 1] + 1;
            else ldown[i] = 1;
        }
        for (int i = n; i >= 1; --i)
        {
            if (p[i] == p[i + 1] - 1) rup[i] = rup[i + 1] + 1;
            else rup[i] = 1;
            if (p[i] == p[i + 1] + 1) rdown[i] = rdown[i + 1] + 1;
            else rdown[i] = 1;
        }
//        for (int i = 1; i <= n; ++i)
//            cout << p[i] << ' ';
//        cout << endl;
//        for (int i = 1; i <= n; ++i)
//            cout << lup[i] << ' ';
//        cout << endl;
//        for (int i = 1; i <= n; ++i)
//            cout << rup[i] << ' ';
//        cout << endl << endl;

        bool flag = false;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] == 1)
            {
                if (lup[i] + rup[i] - 1 == 1 && ldown[i] + rdown[i] - 1 == 1)
                    continue;
                else flag = true;
            }
            else if (lup[i] + rup[i] - 1 == a[i] || ldown[i] + rdown[i] - 1 == a[i])
                continue;
            else flag = true;
        }

        cnt += !flag;
//        if (!flag)
//        {
//            for (int i = 1; i <= n; ++i)
//                cout << p[i] << ' ';
//            cout << endl;
//            for (int i = 1; i <= n; ++i)
//                cout << rdown[i] << ' ';
//            cout << endl << endl;
//        }
        return;
    }

    for (int i = v; i; i -= i & -i)
    {
        int j = Map[i & -i];
//        cout << j << ' ' << (i & -i) << endl;
        p[x] = j;
        dfs(x + 1, v ^ (1 << j - 1));
    }
}

int main()
{
    freopen("gap.in", "r", stdin);
    freopen("gap.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= 1 << n; i <<= 1) Map[i] = Map[i >> 1] + 1;
//    cout << Map[2] << endl;
    dfs(1, (1 << n) - 1);
    cout << cnt << endl;
    return 0;
}
