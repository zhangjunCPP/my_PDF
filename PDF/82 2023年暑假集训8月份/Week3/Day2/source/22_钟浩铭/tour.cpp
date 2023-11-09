#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int n,m,q;
template <typename T>
inline void read(T &x){
	bool f=0; x=0; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=1; ch=getchar();}
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x=f?-x:x;
} 
template <typename T,typename ...Args>
inline void read(T &x,Args &...args){read(x); read(args...);}
inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int head[MAXN<<1],tot;
struct node{
	int to,nxt,w;
}edge[MAXN<<1];
inline void add(int u,int v,int w){
	edge[++tot]={v,head[u],w}; head[u]=tot;
	return ;
}
long long ans=-1;
void dfs(int u,long long sum,int t){
	if(sum>m) return ;
	if(u==t) ans=max(ans,sum);
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to,w=edge[i].w;
		dfs(v,sum*w,t);
	}
}
int main(){
	freopen("tour.in","r",stdin);
	freopen("tour.out","w",stdout);
	read(n,m,q);
	for(int w=2;w<=m;w++){
		int u,v; read(u,v);
		add(u,v,w); add(v,u,w);
	}
	int s,t;
	while(q--){
		ans=-1; read(s,t);
		dfs(s,1ll,t);
		printf("%lld\n",ans);
	}
	return 0;
}
