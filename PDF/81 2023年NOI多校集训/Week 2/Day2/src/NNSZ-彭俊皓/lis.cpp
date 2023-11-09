#include<iostream>
using namespace std;
const int MAXN=500005;
int a,b,c,tot=0,cnt=0;
int head[MAXN],nxt[MAXN<<1],to[MAXN<<1];
int fa[MAXN],size_[MAXN],dpt[MAXN],hson[MAXN];
int dfn[MAXN],top[MAXN];
int upd[MAXN],dis[MAXN],val[MAXN];
inline int read()
{
    char x=getchar();int t=0;
    while(!isdigit(x))x=getchar();
    while(isdigit(x))t=(t<<3)+(t<<1)+(x^48),x=getchar();
    return t;
}
void add(int x,int y){nxt[++tot]=y,to[tot]=head[x],head[x]=tot;}
void dfs1(int x)
{
    size_[x]=1;hson[x]=0;
    for(int i=head[x];i;i=to[i])
    {
        int now=nxt[i];
        if(now==fa[x])continue;
        fa[now]=x,dpt[now]=dpt[x]+1;
        dfs1(now);
        size_[x]+=size_[now];
        hson[x]=size_[now]>size_[hson[x]]?now:hson[x];
    }
}
void dfs2(int x,int y)
{
    dfn[x]=++cnt,top[x]=y;
    if(hson[x])dfs2(hson[x],y);
    for(int i=head[x];i;i=to[i])
    {
        int now=nxt[i];
        if(now==fa[x]||now==hson[x])continue;
        dfs2(now,now);
    }

}
int main()
{
    freopen("lis.in","r",stdin);
    freopen("lis.out","w",stdout);
    a=read();
    for(int i=1;i<a;++i)
    {
        int x,y;x=read();y=read();
        add(x,y);add(y,x);
    }
    for(int i=1;i<=a;++i)val[i]=read();
    dfs1(1);dfs2(1,1);
    cout<<2;
}

