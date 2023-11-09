#include <bits/stdc++.h>

using namespace std;
const int MAXN=2e3+10; int a[MAXN], n;
int ans, f[MAXN], used[MAXN], b[MAXN];
int typ[MAXN];

void dfs(int step, int type=0, int start=0) {
    if (step>n) {
        ans=(ans+1)%998244353; return;
    }
    if (a[step]==1) {
        for (int i=1; i<=n; ++i) {
            if (used[i] || i==f[step-1]-1 || i==f[step-1]+1) continue;
            used[i]=true;
            f[step]=i;
            dfs(step+1,0,0);
            used[i]=false;
        }
    }
    else {
        if (!start) {
            start=step;
            for (int i=1; i<=n; ++i) {
                if (used[i] ||  i==f[step-1]-1 || i==f[step-1]+1) continue;
                used[i]=1;
                f[step]=i;
                dfs(step+1, 1, start);
                typ[step]=-1;
                dfs(step+1, -1, start);
                used[i]=0;
            }
        }
        else {
            int nxt=f[step-1]+type;
            if (nxt<1 || nxt>n || used[nxt]) return;
            used[nxt]=true; 
            f[step]=nxt;
            dfs(step+1, type, start);
            used[nxt]=false;
        }
    }
}

int main() {
    #ifndef DEBUG
    freopen("stick.in", "r", stdin);
    freopen("stick.out", "w", stdout);
    #endif
    cin>>n;
    for (int i=1; i<=n; ++i) cin>>a[i];
    dfs(1);
    cout<<ans<<endl;
    return 0;
}