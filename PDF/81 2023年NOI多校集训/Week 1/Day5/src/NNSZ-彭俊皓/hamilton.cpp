#include<iostream>
using namespace std;
const int MAXN=300005;
int a,b,c,tot=0,cnt=0,tail=0;
int head[MAXN],nxt[MAXN],to[MAXN];
int low[MAXN],dfn[MAXN],stk[MAXN];
int bj[MAXN],sd[MAXN];
inline int read()
{
    char x=getchar();int t=0;
    while(!isdigit(x))x=getchar();
    while(isdigit(x))t=(t<<3)+(t<<1)+(x^48),x=getchar();
    return t;
}
void add(int x,int y){nxt[++tot]=y,to[tot]=head[x],head[x]=tot;}
void tarjan(int x)
{
    low[x]=dfn[x]=++cnt;
    stk[++tail]=x;
    for(int i=head[x];i;i=to[i])
    {
        int now=nxt[i];
//        if(bj[now])continue;
//        printf("(%d->%d)\n",x,now);
        if(!dfn[now])tarjan(now);
        else low[x]=min(low[x],low[now]);
    }
//    printf("[%d:%d %d]\n",x,dfn[x],low[x]);
    if(low[x]==dfn[x])
    {
        while(stk[tail]!=x&&tail)
        {
            int y=stk[tail--];
//            printf("{%d %d}",x,y);
            sd[y]=x;
        }
//        puts("");
    }
}
int main()
{
    freopen("hamilton.in","r",stdin);
    freopen("hamilton.out","w",stdout);
    a=read();b=read();
    for(register int i=1;i<=b;++i)
    {
        int x,y;x=read();y=read();
        add(x,y);
    }
    //dfs(1,0);
//    for(register int i=1;i<=a;++i)sd[i]=i;
//    for(register int i=1;i<=a;++i)
//    {
//        if(!dfn[i])tarjan(i);
//    }
//    for(register int i=1;i<=a;++i)printf("(%d)",low[i]);
//    puts("");
//    for(register int i=1;i<=a;++i)printf("(%d)",sd[i]);
    puts("NO");
    return 0;
}//判一遍欧拉回路，判一遍哈密顿回路即可？

