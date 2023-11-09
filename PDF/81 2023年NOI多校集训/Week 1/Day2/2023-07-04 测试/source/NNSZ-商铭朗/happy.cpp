#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MAXN=1e5+10, MAXK=5e2+10;
int n, K, T[MAXN], pr; 

struct Ticket {
    int num, cost;
    Ticket(int x=0, int y=0) {
        num=x, cost=y;
    }
} tic[MAXK]; int maxnum=-1;

int f[MAXN], spend[MAXN];

int solve(int l, int r, int type) {
    int res=0, last=0;
    for (int i=l; i<=r; ++i) {
        if (last<T[i]) {
            last=T[i]+tic[type].num-1;
            res+=tic[type].cost;
        }
    }
    return res;
}

signed main() {
    #ifndef DEBUG
    freopen("happy.in", "r", stdin);
    freopen("happy.out", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>K;
    for (int i=1; i<=n; ++i) cin>>T[i];
    int x, y;
    for (int i=1; i<=K; ++i) {
        cin>>x>>y;
        tic[i]=Ticket(x,y);
        maxnum=max(maxnum,x);
    }
    cin>>pr;
    tic[0]=Ticket(1,pr);
    memset(f,0x3f,sizeof f);
    f[0]=0;
    for (int i=1; i<=n; ++i) {
        for (int j=0; j<i; ++j) {
            if (maxnum!=-1 &&
            i>=maxnum && T[j]+maxnum-1<T[i]) continue;
            for (int k=0; k<=K; ++k) {
                f[i]=min(f[i],f[j]+solve(j+1,i,k));
            }
        }
        spend[i]=f[i]-f[i-1];
        cout<<spend[i]<<'\n';
    }
    return 0;
}