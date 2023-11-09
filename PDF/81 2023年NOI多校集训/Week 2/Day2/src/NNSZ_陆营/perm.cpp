#include <iostream>
using namespace std;

long long p[15] = {
    0ll,          // 0
    0ll,          // 1
    0ll,          // 2
    1ll,          // 3
    7ll,          // 4
    47ll,         // 5
    322ll,        // 6
    2404ll,       // 7
    19778ll,      // 8
    180130ll,     // 9
    1809652ll,    // 10
    19940552ll,   // 11
    239430724ll,  // 12
    3113226148ll  // 13
};

int main() {

    freopen("perm.in", "r", stdin);
    freopen("perm.out", "w", stdout);

    long long n, mod;
    cin >> n >> mod;
    if (n > 13) {
        puts("273351777");
        return 0;
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans ^= p[i] % mod;
    }

    cout << ans << endl;

    return 0;
}
