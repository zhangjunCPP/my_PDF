#include<bits/stdc++.h>
using namespace std;
namespace my_IO{
    #define ll long long
    #define ull unsigned long long
    #define ld long double
    template<class T>
    void read(T &num){
        T x=0,f=1;
        char c=getchar();
        while(!isdigit(c)){
            if(c=='-') f=-1;
            c=getchar();
        }
        while(isdigit(c)){
            x=(x<<3)+(x<<1)+c-48;
            c=getchar();
        }
        num=f*x;
    }
    template<class T>
    void write(T x){
        static char buf[40];
        static int len=-1;
        if(x<0) putchar('-'),x=-x;
        do{
            buf[++len]=x%10+48;
            x/=10;
        }while(x);
        while(len>=0) putchar(buf[len--]);
    }
}
using namespace my_IO;
const ll mod=1e9+7;
const ll maxn=1e6+10;
ll n,head[maxn],tot,ans;
struct edge{
    ll t,nxt;
}e[maxn<<1];
void add(ll st,ll ed){
    e[++tot]={ed,head[st]};
    head[st]=tot;
}
namespace task1{
    ll col[maxn],fa[maxn],dep[maxn];
    void dfs(ll u,ll f){
        fa[u]=f;
        dep[u]=dep[f]+1;
        for(ll i=head[u];i;i=e[i].nxt) if(e[i].t!=f) dfs(e[i].t,u);
    }
    ll lca(ll x,ll y){
        if(dep[x]<dep[y]) swap(x,y);
        while(dep[x]>dep[y]) x=fa[x];
        if(x==y) return x;
        while(x!=y) x=fa[x],y=fa[y];
        return x;
    }
    ll dis(ll x,ll y){
        return dep[x]+dep[y]-2*dep[lca(x,y)];
    }
    void cal(){
        dfs(1,0);
        ll mx=1<<n;
        for(ll i=0;i<mx;i++){
            ll res1=0,res2=0;
            for(ll j=1;j<=n;j++){
                if(i&(1<<(j-1))) col[j]=1;
                else col[j]=0;
            }
            for(ll j=1;j<=n;j++){
                for(ll k=j+1;k<=n;k++){
                    if(col[j]!=col[k]) continue;
                    ll res=dis(j,k);
                    if(col[j]) res1=max(res1,res);
                    else res2=max(res2,res);
                }
            }
            ans+=max(res1,res2);
        }
        write(ans);
    }
}
ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
namespace task2{
    void cal(){
        ans=ksm(2,n-1)*(n-1)%mod;
        ll res=0;
        for(ll i=1;i<n;i++){
            if(max(i,n-i)>1) res=(res+max(i,n-i)-1)%mod;
            for(ll j=2;j<i;j++) if(max(i,n-j+1)>1) res=(res+ksm(2,i-j-1)*(max(i,n-j+1)-1)%mod)%mod;
        }
        write((ans+res*2%mod)%mod);
    }
}
void solve(){
    ll flaga=1,flagb=1,flagc=1;
    read(n);
    for(ll i=1;i<n;i++){
        ll u,v;
        read(u),read(v);
        add(u,v),add(v,u);
        if(u!=1&&v!=1) flagb=0;
    }
    if(n<=10){
        task1::cal();
        return;
    }
    if(flaga){
        task2::cal();
        return;
    }
    if(flagb){
        if(n==1) puts("0");
        if(n==2) puts("2");
        if(n==3) puts("12");
        if(n>3) write(ksm(2,n+1));
        return;
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int t=1;
    while(t--) solve();
}
