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
const ll inf=1e18;
ll n,m,head[16],tot,M,N,B,fk,fans=-inf,ans[16],mx,bk[16],s[400],t[400],mk[1<<16];
struct edge{
    ll t,nxt;
}e[32];
void add(ll st,ll ed){
    e[++tot]={ed,head[st]};
    head[st]=tot;
}
vector<ll> v;
ll count(ll u){
    ll res=0;
    for(ll i=head[u];i;i=e[i].nxt) if(bk[e[i].t]) res++;
    return res;
}
void mark(ll x){
    ll cnt=0;
    vector<ll> v;
    for(ll i=1;i<=n;i++){
        if(x&(1<<(i-1))){
            v.push_back(i-1);
            cnt++;
        }
    }
    for(ll i=0;i<1<<cnt;i++){
        ll num=0;
        for(ll j=0;j<cnt;j++) if(i&(1<<j)) num|=1<<v[j];
        mk[num]=1;
    }
}
void solve(){
    read(n),read(m),read(M),read(N),read(B);
    for(ll i=1;i<=m;i++){
        ll u,v;
        read(u),read(v);
        s[i]=u,t[i]=v;
        add(u,v),add(v,u);
    }
    mx=1<<n;
    for(ll i=1;i<n;i++) ans[i]=-inf;
    for(ll k=1;k<n;k++){
        memset(mk,0,sizeof(mk));
        for(ll i=mx-1;i>=1;i--){
            if(mk[i]||__builtin_popcount(i)<=k) continue;
            memset(bk,0,sizeof(bk));
            v.clear();
            for(ll j=1;j<=n;j++){
                if(i&(1<<(j-1))){
                    v.push_back(j);
                    bk[j]=1;
                }
            }
            ll flag=1;
            for(ll j=0;j<v.size();j++){
                ll u=v[j];
                if(count(u)<k){
                    flag=0;
                    break;
                }
            }
            if(!flag) continue;
            ll res=-__builtin_popcount(i)*N;
            for(ll j=1;j<=m;j++){
                if(bk[s[j]]&&bk[t[j]]) res+=M;
                if((bk[s[j]]&&!bk[t[j]])||(bk[t[j]]&&!bk[s[j]])) res+=B;
            }
            ans[k]=max(ans[k],res);
            mark(i);
        }
    }
    for(ll i=n-1;i>=1;i--){
        if(ans[i]>fans){
            fans=ans[i];
            fk=i;
        }
    }
    write(fk),putchar(' '),write(fans);
}
int main(){
    freopen("subgraph.in","r",stdin);
    freopen("subgraph.out","w",stdout);
    int t=1;
    while(t--) solve();
}
