/*
B trans
肯定暴力乱冲，前三档拿了就走人
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
int n,m,k;
int dif[110],sam[110],x[110],y[110];
inline int Check()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)scanf("%d%d%d%d",x+i,y+i,dif+i,sam+i);
    if(n==2)return 1;
    if(n==9||n==12)return 2;
    if(n<=10)return 3;
    return 0;
}
namespace Solve1//n=2
{
    inline void work()
    {
        ll dift=1,samt=1;
        for(int i=1;i<=m;i++)dift=dift*dif[i]%mod,samt=samt*sam[i]%mod;
        printf("%lld\n",(dift*k%mod*(k-1)%mod+samt*k%mod)%mod);
        return;
    }
}
namespace Solve2//搜
{
    int col[20];
    inline ll calc()
    {
        ll ret=1;
        for(int i=1;i<=m;i++)ret=ret*(col[x[i]]==col[y[i]]?sam[i]:dif[i])%mod;
        return ret;
    }
    int ans=0;
    void DFS(int i)
    {
        if(i>n){ans=(ans+calc())%mod;return;}
        for(int j=1;j<=k;j++)
        {
            col[i]=j;
            DFS(i+1);
        }
        return;
    }
    inline void work()
    {
        ans=0;
        for(int i=1;i<=n;i++)col[i]=i+1000000;
        DFS(1);
        printf("%d\n",ans);
    }
}
namespace Solve3//还是搜
{
    int ans=0;
    int col[20];
    bool vis[110][110];
    struct edge{
        int v,nex;
    }e[110];
    int fir[110],ent;
    inline void add(int u,int v)
    {
        e[++ent]={v,fir[u]};
        fir[u]=ent;
        return;
    }
    inline ll calc()
    {
        ll ret=1;
        for(int i=1;i<=m;i++)ret=ret*(col[x[i]]==col[y[i]]?sam[i]:dif[i])%mod;
        return ret;
    }
    void DFS(int u)
    {
        if(col[u])return;
        if(u>n){ans=(ans+calc())%mod;return;}
        memset(vis[u],0,sizeof vis[u]);
        for(int i=fir[u];i;i=e[i].nex)vis[u][col[e[i].v]]=true;
        for(int i=1;i<=k;i++)
        {
            if(vis[u][i])continue;
            col[u]=i;
            DFS(u+1);
            col[u]=0;
        }
        return;
    }
    int val[110];
    inline ll qpow(ll a,int b)
    {
        if(!b)return 1;if(!a)return 0;
        ll ret=1;
        while(b){if(b&1)ret=(ret*a)%mod;a=(a*a)%mod;b>>=1;}
        return ret;
    }
    inline ll C(int n,int m)
    {
        ll ret=1;
        for(int i=1;i<=m;i++)ret=ret*(n-i+1)%mod;
        for(int i=2;i<=m;i++)ret=ret*qpow(i,mod-2)%mod;
        return ret;
    }
    inline void work()
    {
        int t=k;
        for(int i=2;i<=n;i++)
        {
            ans=0;
            k=i;
            DFS(1);
            val[i]=ans;
        }
        ll ret=0;
        for(int i=2;i<=n;i++)ret=(ret+C(t,i)*val[i])%mod;
        printf("%lld",ret);
        return;
    }
}
int main()
{
    freopen("trans.in","r",stdin);
    freopen("trans.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int mode=Check();
//        if(mode==1)Solve1::work();
//        if(mode==2)Solve2::work();
//        if(mode==3)Solve3::work();
//        if(mode==0)puts("1919810");
		Solve2::work();
    }
    return 0;
}
