#include <bits/stdc++.h>

using namespace std;
const int MAXN=5e5+10; 
int a[MAXN], d[MAXN], vis[21], tot, n;
int lft[MAXN], rght[MAXN];

#define speedup() {ios::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);}
int main() {
    #ifndef DEBUG
    freopen("cut.in", "r", stdin);
    freopen("cut.out", "w", stdout);
    #endif
    speedup();
    cin>>n;
    int flag=false, l=1;
    for (int i=1; i<=n; ++i) cin>>a[i];
    for (int i=1; i<=n; ++i) {
        if (i==n) rght[i]=i;
        if (vis[a[i]] || i==1) {
            d[++tot]=i;
            memset(vis,0,sizeof vis);
            if (i==1) vis[a[i]]=true;
            rght[i-1]=i-1;
            lft[i]=i, l=i;
        }
        else {
            vis[a[i]]=true;
            lft[i]=l;
        }
    }
    for (int i=2; i<=tot; ++i) {
        int r=rght[d[i]-1];
        for (int j=d[i]-1; j>=(d[i-2]?d[i-2]:1); --j) {
            rght[j]=r;
        }
    }
    
    int ans=0;
    for (int i=1; i<=tot; ++i) {
        memset(vis,0,sizeof vis);
        for (int j=d[i]; j<(d[i+1]?d[i+1]:n+1); ++j) {
            vis[a[j]]=true;
        }
        for (int j=0; j<=21; ++j) {
            if (!vis[j]) {ans+=j; break;}
        }
    }
    cout<<ans<<' '<<tot<<endl;
    for (int i=1; i<=tot; ++i) {
        cout<<d[i]<<' ';
    }
}