#include<stdio.h>

#define int long long
//static char buf[1000000],*p1=buf,*p2=buf,obuf[1000000],*p3=obuf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
//#define putchar(x) (p3-obuf<1000000)?(*p3++=x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=x)
template<typename item>
inline void read(item &x){
    x=0;int f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
    x*=f;
}
template<typename item>
inline void write(item x){
    if(x<0){putchar('-');x=-x;}
    if(x>9) write(x/10); putchar(x%10+48);
}
template<typename dy> dy max(dy x,dy y){return x>y?x:y;}
template<typename dy> dy min(dy x,dy y){return x<y?x:y;}
const int N=5e5+5;
struct dy{
    int v,next,w;
}edge[N<<1];
int head[N],cnt=1;
void add(int u,int v,int w){
    edge[cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
int n,m,q,ans,S,T;
bool f;
void dfs(int u,int s){
	if(u==T) ans=max(ans,s); 
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].v,w=edge[i].w;
		if(s*w<=m) dfs(v,s*w);
	}
}
signed main(){
	freopen("tour.in","r",stdin);
	freopen("tour.out","w",stdout);
	read(n);read(m);read(q);
	for(int i=1;i<m;i++)
	{
		int u,v;read(u);read(v);
		add(u,v,i+1);add(v,u,i+1);
	}
	while(q--)
	{
		read(S);read(T);
		ans=-1;dfs(S,1);
		write(ans);putchar('\n');
	}
    return 0;
}