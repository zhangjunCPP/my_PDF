#include <bits/stdc++.h>

using namespace std;

int n,m, q;

// (1)(1); (2)
// (2)(1); (1)(1)(1); 
#define int long long
int stick[500+!0], sum[500+10];
int f[100000];

int calc(int n) {
    sum[0]=0;
    int res=stick[1]*stick[2];
    for (int i=1; i<=n; ++i) {
        sum[i]=sum[i-1]+stick[i];
        if (i>2) {
            res+=sum[i-1]*stick[i];
        }
    }
    return res;
}

int flag=false;

void dfs(int step, int used, int n, int m) {
    if (flag) return;
    if (used==n) {
        //for (int i=1; i<step; ++i) printf("%d ", stick[i]);
        //puts("");
        if (calc(step-1)==m) 
            flag=true; 
        return;
    }
    for (int i=1; i<=n-used; ++i) {
        stick[step]=i;
        dfs(step+1,used+i,n,m);
        if (flag) return;
    }
}

signed main() {
    #ifndef DEBUG
    freopen("stick.in", "r", stdin);
    freopen("stick.out", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>q;
    while (q--) {
        cin>>n>>m;
        if (m==0 || m==n || m==n-1 || m<<1==n*(n-1)) {
            cout<<1<<endl; continue;
        }
        else if ((0<m&&m<n-1) || n*(n-1)<2*m || (n+1<=m&&m<=2*n-5)) {
            cout<<0<<endl; continue;
        }
        flag=false;
        dfs(1,0,n,m);
        if (flag)
            cout<<1<<endl;
        else 
            cout<<0<<endl;
    }
}