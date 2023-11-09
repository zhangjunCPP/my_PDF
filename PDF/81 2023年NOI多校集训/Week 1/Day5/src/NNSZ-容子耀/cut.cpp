#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5e5 + 10;

int n;
vector<int> seq;
int a[N], f[N], mex[N], from[N];

int main()
{
    freopen("cut.in", "r", stdin);
    freopen("cut.out", "w", stdout);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        bool v[30];
        memset(v, 0, sizeof v);
        int idx = 0;
        for (int j = i; j >= 1 && mex[j] <= a[i]; --j)
        {
            v[a[j]] = true;
            while (v[idx]) ++ idx;
            if (mex[j] == a[i]) mex[j] = idx;
//            f[i] = max(f[i], mex[j] + f[j - 1]);
            if (mex[j] + f[j - 1] > f[i])
                f[i] = mex[j] + f[j - 1], from[i] = j;
        }
    }

    cout << f[n] << ' ';
    int pos = n;
    while (pos > 1)
        seq.push_back(from[pos]), pos = from[pos] - 1;
    reverse(seq.begin(), seq.end());
    cout << seq.size() << endl;
    for (auto i : seq)
        cout << i << ' ';
    return 0;
}
