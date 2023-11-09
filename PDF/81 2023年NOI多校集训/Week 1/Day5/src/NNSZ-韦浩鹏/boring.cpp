#include<bits/stdc++.h>
using namespace std;
namespace io{
    int read(){
        int r=0; char c;
        do c=getchar(); while(!isdigit(c));
        do r=(r<<3)+(r<<1)+(c^'0'), c=getchar(); while(isdigit(c));
        return r;
    }
}
using namespace io;
typedef long long LL;
const int N=1e5+3, Mod=998244353, M=1e7+3;
int prime[N], zys[N], cnt;
bool f[N];
LL a[N];
set <int> h, t, r;
map <set<int>,LL> mp;
LL ans;
map <int,int> c;
LL solve(){
    if(mp.count(h)) return mp[h];
    c.clear();
    for(auto it=h.begin();it!=h.end();++it){
        int x=*it;
        if(!f[x]&&x%2) c[x]=max(c[x], 1);
        else{
            int tmp=x;
            for(int i=1;i<=cnt&&prime[i]*prime[i]<=tmp;++i)
                if(x%prime[i]==0){
                    int k=0;
                    while(x%prime[i]==0) x/=prime[i], ++k;
                    c[prime[i]]=max(c[prime[i]], k);
                }
            if(x!=1) c[x]=max(c[x], 1);
        }
    }
    h.clear();
    for(auto it=c.begin();it!=c.end();++it){
        int x=(*it).first, y=(*it).second;
        h.insert(pow(x, y));
    }
    ans=1, r=h;
    for(auto it=mp.begin();it!=mp.end();++it){
        t.clear();
        t=(*it).first;
        for(auto j=t.begin();j!=t.end();++j)
            if(!h.count((*j))) goto rst;
        for(auto j=t.begin();j!=t.end();++j)
            r.erase((*j));
        ans=ans*(*it).second%Mod;
        rst:;
    }
    for(auto it=r.begin();it!=r.end();++it)
        ans=ans*(*it)%Mod;
    mp[h]=ans%Mod;
    return ans%Mod;
}
int main(){
    freopen("boring.in", "r", stdin);
    freopen("boring.out", "w", stdout);
    prime[++cnt]=2;
    for(int i=3;i<N;i+=2){
        if(!f[i]) prime[++cnt]=zys[i]=i;
        for(int j=2;j<=cnt;++j){
            if(prime[j]*i>=N||prime[j]>zys[i]) break;
            f[prime[j]*i]=1;
        }
    }
    int n, q;
    n=read(), q=read();
    for(int i=1;i<=n;++i)
        a[i]=read();
    while(q--){
        int k, x, y;
        k=read();
        h.clear();
        while(k--){
            x=read(), y=read();
            for(int i=x;i<=y;++i)
                h.insert(a[i]);
        }
        printf("%lld\n", solve());
    }
    return 0;
}
