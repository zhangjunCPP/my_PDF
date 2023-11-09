#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10, M = 510, INF= 1e9;

LL f[N];
int n, k;
int t[N], ptr[M], one;
PII time_tc[M];

int main()
{
    freopen("happy.in", "r", stdin);
    freopen("happy.out", "w", stdout);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> t[i];
    for (int i = 1; i <= k; ++i)
        cin >> time_tc[i].first >> time_tc[i].second;
    cin >> one;

    for (int i = 1; i <= n; ++i)
    {
        f[i] = f[i - 1] + one;
        for (int j = 1; j <= k; ++j)
        {
            auto &[num, cost] = time_tc[j];
            while (t[ptr[j] + 1] + num - 1 < t[i])
                ++ ptr[j];
            f[i] = min(f[i], f[ptr[j]] + cost);
        }
    }

//    for (int i = 1; i <= n; ++i)
//        cout << f[i] << endl;
    for (int i = 1; i <= n; ++i)
        cout << f[i] - f[i - 1] << '\n';
    return 0;
}
