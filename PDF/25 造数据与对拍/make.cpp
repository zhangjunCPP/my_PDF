#include <bits/stdc++.h>
using namespace std;
ll random(ll mod)
{
    ll n1, n2, n3, n4, ans;
    n1 = rand();
    n2 = rand();
    n3 = rand();
    n4 = rand();
    ans = n1 * n2 % mod;
    ans = ans * n3 % mod;
    ans = ans * n4 % mod;
    return ans;
}

int main()
{
    srand((unsigned)time(0));
    ll n;
    while (1)
    {
        n = random(1000000);
        cout << n << endl;
    }
    return 0;
}
