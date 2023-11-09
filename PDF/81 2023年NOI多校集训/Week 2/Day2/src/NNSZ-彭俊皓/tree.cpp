#include<iostream>
#include<string.h>
#define ll long long
using namespace std;
const int MAXN=1000005,modd=1e9+7;
int a,b,c,tot=0,dep=0,root=0;
ll sum=0;
int head[MAXN],nxt[MAXN<<1],to[MAXN<<1];
int fa[MAXN],dpt[MAXN];
inline int read()
{
    char x=getchar();int t=0;
    while(!isdigit(x))x=getchar();
    while(isdigit(x))t=(t<<3)+(t<<1)+(x^48),x=getchar();
    return t;
}
void add(int x,int y){nxt[++tot]=y,to[tot]=head[x],head[x]=tot;}
void dfs(int x)
{
//    cout<<x<<"!";
    for(int i=head[x];i;i=to[i])
    {
        int now=nxt[i];
        if(now==fa[x])continue;
        fa[now]=x,dpt[now]=dpt[x]+1;
        dfs(now);
    }
    if(dpt[x]>dep)root=x,dep=dpt[x];
}
void print(ll x)
{
    for(ll i=0;i<=(1<<x)-1;++i)
    {
        int s=i,d=0,k=x;
        int l=0,r=x-1;
        s=i;
        while(s||k)s>>=1,k--;
        s=i;
        while((s&(1<<l))&&l<r)l++;
        while((s&(1<<r))&&l<r)r--;
        d+=r-l;
//        printf("(%d->",d);
        l=0,r=x-1;
        s=i;
        while((s&(1<<l))==0&&l<r)l++;
//        cout<<l<<r<<"->";
        while((s&(1<<r))==0&&l<r)r--;
//        cout<<l<<r<<"->";
        d+=r-l;
//        if(__builtin_popcount(i)==1||__builtin_popcount(i)==x-1)
//        {cerr<<"!";d--;}
//        printf("%d)",d);
//        printf("[%d,%d,%d,%d]:%d\n",1<<l,1<<r,i&(1<<l),i&(1<<r),d);
        (sum+=d)%=modd;
    }
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    a=read();
    for(int i=1;i<a;++i)
    {
        int x,y;x=read();y=read();
        add(x,y);add(y,x);
    }
    dpt[1]=0;dfs(1);
    int x1=root;
    memset(fa,0,sizeof(fa));
//    for(int i=1;i<=a;++i)printf("fa=%d",fa[i]);
    dpt[x1]=0;dep=0;
    dfs(x1);
    int x2=root;
//    cout<<dpt[x2];
//    for(int i=1;i<=a;++i)
//    {
//        sum=0;
//        print(i);
//        printf("%d:%lld\n",i,sum);
//    }
    print(dpt[x2]);
    printf("%lld",sum%modd);
    return 0;
}
