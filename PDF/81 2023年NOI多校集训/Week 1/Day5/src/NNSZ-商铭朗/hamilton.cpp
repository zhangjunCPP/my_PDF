#include<bits/stdc++.h>

using namespace std;
#define speedup() {ios::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);}
const int MAXN=2e5+10, MAXM=4e5+10;

struct {
    int nxt, to;
} e[MAXM]; int h[MAXN], tot;

inline void add(int u, int v) {
    e[++tot].to=v, e[tot].nxt=h[u], h[u]=tot;
}
int n, m; int ind[MAXN], outd[MAXN];
int stk[MAXN], r;
bitset<MAXM> visv, vise, in_stk;

inline void dfs(int u) {
    visv[u]=1, in_stk[u]=1; stk[++r]=u;
    for (int i=h[u]; i; i=e[i].nxt) {
        int v=e[i].to;
        if (visv[v]) {
            // 遇到环了
            int j=0;
            for (int i=1, flag=false; i<=r; ++i) {
                if (stk[i]==v) {flag=true; j=i; cout<<r-i+1<<' ';}
                if (flag) cout<<stk[i]<<' ', in_stk[stk[i]]=false;
            }
            cout<<'\n';
            r=j-1;
        }
        if (!vise[i] && !visv[v]) {
            vise[i]=1;
            dfs(v);
        }
    }
}
int main() {
    #ifndef DEBUG
    freopen("hamilton.in", "r", stdin);
    freopen("hamilton.out", "w", stdout);
    #endif
    cin>>n>>m;
    int x, y;
    for (int i=1; i<=m; ++i) {
        cin>>x>>y;
        add(x,y);
        ind[y]++, outd[x]++;
    }
    for (int i=1; i<=n; ++i){
        if (!(ind[i]&&outd[i])) {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for (int u=1; u<=n; ++u) {
        if(!visv[u]) {
            //r=0;
            dfs(u);
            
        }
    }
    return 0;
}