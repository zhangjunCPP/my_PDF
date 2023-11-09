#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e7 + 10;

int f[N], fact[N], sum[N], s;
int n, P;

void init(int n)
{
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
        fact[i] = (LL)fact[i - 1] * i % P;
}

int main()
{
    freopen("perm.in", "r", stdin);
    freopen("perm.out", "w", stdout);

    cin >> n >> P;

    init(n);
    for (int i = 1; i <= n; ++i) sum[i] = (sum[i - 1] + i) % P;
    for (int i = 3; i <= n; ++i)
    {
//        for (int j = 3; j <= i; ++j)
//            f[i] = (f[i] + (LL)fact[i - 2] * (j - 2) % P) % P;
        f[i] = (f[i] + (LL)fact[i - 2] * sum[i - 2] % P) % P;
        f[i] = (f[i] + f[i - 1]) % P;
//        for (int j = 2; j <= i; ++j)
//            f[i] = (f[i] + f[i - 2]) % P;
        f[i] = (f[i] + (LL)f[i - 2] * (i - 1) % P) % P;
        s ^= f[i];
    }

    cout << s << endl;
    return 0;
}
