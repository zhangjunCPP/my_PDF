/*
考虑的是最坏情况，所以是优先堵关键点，然后是离关键点最近的。
从一个点到达关键点似乎很难考虑，能否反着来？
一个点能直达关键点，是 d[u]<key[u]
必定不会往回走（不优或无解）
关键点周围的一圈，答案能直接算
也许能先去除一些无用的边：
- 关键点之间的
- d[u]>=key[u] 时和 u 相连的所有关键点
- d[u]<key[u] 时所有的关键点，并预算答案
这样，只剩一部分有答案的，以及一些互相之间移动。
然后似乎边都很有用。可以把预算了答案的加进去，开始跑 dij
 */
#include<bits/stdc++.h>
namespace IO{
    #define _fre_(file,in,out) { \
        if(in) freopen(file".in","r",stdin); \
        if(out) freopen(file".out","w",stdout); \
    }
    void read(int &x){
        x=0;bool sign=false;char ch=getchar();
        for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') sign=true;
        for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+(sign?-(ch&15):(ch&15));
    }
}
template<typename ...Args>
void read(Args &...args){(void)(std::initializer_list<int>{(IO::read(args),0)...});}
namespace MAIN{
    constexpr int N=2e5+5,M=2e5+5;
    using ll=long long;
    int n,m,sk,d[N],key[N];
    int hd[N],ver[M*2],nxt[M*2],cost[M*2],tot=1;
    void add(int u,int v,int w){nxt[++tot]=hd[u],ver[hd[u]=tot]=v,cost[tot]=w;}
    bool is_key[N];
    ll f[N];
    void _main_(){
        read(n,m,sk);
        for(int i=1,x;i<=sk;++i) read(x),is_key[x]=true;
        if(is_key[1]) return std::puts("0"),void();
        for(int i=1;i<=n;++i) read(d[i]);
        for(int i=1,u,v,w;i<=m;++i){
            read(u,v,w);
            if(is_key[u]&&is_key[v]) continue;
            if(is_key[u]) ++key[v];
            else if(is_key[v]) ++key[u];
            add(u,v,w),add(v,u,w);
        }
        memset(f,0x3f,sizeof f);
        for(int u=1;u<=n;++u){
            if(!is_key[u]){
                static std::vector<int> v;
                v.clear();
                for(int e=hd[u];e;e=nxt[e])
                    if(is_key[ver[e]]) v.emplace_back(cost[e]);
                if(v.size()<=d[u]) d[u]-=v.size();
                else{
                    std::nth_element(v.begin(),v.begin()+d[u],v.end());
                    f[u]=v[d[u]],d[u]=0;
                }
            }
        }
        std::priority_queue<std::pair<ll,int>> q;
        for(int u=1;u<=n;++u)
            if(f[u]!=f[0]) q.emplace(-f[u],u);
        if(q.empty()) return std::puts("-1"),void();
        static bool used[N];
        for(int u;!q.empty();){
            u=q.top().second,q.pop();
            if(used[u]) continue;
            used[u]=true;
            for(int e=hd[u],v,c;e;e=nxt[e])
                if(!is_key[v=ver[e]]&&--d[v]<=0&&f[v]>f[u]+(c=cost[e]))
                    q.emplace(-(f[v]=f[u]+c),v);
        }
        std::printf("%lld\n",f[1]==f[0]?-1:f[1]);
        return;
    }
}
signed main(){
    _fre_("maze",1,1);
    return MAIN::_main_(),0;
}