#include <bits/stdc++.h>

using namespace std;
const int MAXN=1e6+10;
int n, a[MAXN];
int ans=0;

inline void solve(int start) {
    int res=0;
    for (int i=start; i<=n; ++i) {
        if (a[i]==a[i+2] && a[i+1]==a[i+3]) res+=4, i+=3;
    }
    ans=max(res,ans);
}

int main() {
    #ifndef DEBUG
    freopen("comb.in", "r", stdin);
    freopen("comb.out", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for (int i=1; i<=n; ++i) cin>>a[i];
    for (int i=1; i<4; ++i) solve(i);
    cout<<ans;
    return 0;
}