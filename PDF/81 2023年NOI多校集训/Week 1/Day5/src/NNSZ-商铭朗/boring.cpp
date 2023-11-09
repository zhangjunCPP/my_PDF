#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
#define speedup() {ios::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);}
constexpr int MAXN=1e5+10, p=998244353;
int a[MAXN], n, q;
int t[MAXN];
inline int qpow(int a, int n, int p) { a%=p; int res=1; while (n) { if (n&1) res=res*a%p; a=a*a%p; n>>=1; } return res; }
inline int inv(int a) { return qpow(a, p-2, p); }
inline int gcd(int a, int b) { return b?gcd(b,a%b):a; }
inline int lcm(int a, int b) { return (a*b)%p*inv(gcd(a,b))%p; }
inline int lcm(int f[], int l, int r) { if (l==r) return f[l];
    if (r-l==1) return lcm(f[l], f[r]);
    //int res=lcm(f[l],f[l+1]);
    //for (int i=l+2; i<=r; ++i) res=lcm(res,f[i]);
   // return res;
    int mid=(l+r)>>1;
    return lcm(lcm(f, l, mid), lcm(f, mid+1, r));
}
signed main() {
    #ifndef DEBUG
    freopen("boring.in", "r", stdin);
    freopen("boring.out", "w", stdout);
    #endif
    speedup();
    cin>>n>>q;
    for (int i=1; i<=n; ++i) cin>>a[i];
    int k;
    while (q--) {
        cin>>k;
        int l, r;
        for (int i=1; i<=k; ++i) {
            cin>>l>>r;
            t[i]=lcm(a,l,r);
        }
        cout<<lcm(t,1,k)%p<<endl;
    }
    return 0;
}