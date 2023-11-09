#include<bits/stdc++.h>
using namespace std;
namespace IO{
	template<typename T> void read(T &x){
		x=0; bool f=0; char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
		for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
		if(f) x=-x;
	}
	template<typename T,typename ...Args> void read(T &x,Args &...args){
		read(x),read(args...);
	}
	template<typename T> void write(T x){
		if(x<0) putchar('-'),x=-x;
		short stk[50],top=0;
		do stk[++top]=x%10,x/=10; while(x);
		for(;top;top--) putchar(stk[top]^48);
	}
	void write(char x){ putchar(x); }
	template<typename T,typename ...Args> void write(T x,Args ...args){
		write(x),write(args...);
	}
}
const int N=5e5+5;
int h[N],cnt;
struct edge{ int to,nex,val; }e[N*2];
void add(int u,int v,int w){ e[++cnt]=(edge){v,h[u],w},h[u]=cnt; }
void add_edge(int u,int v,int w){ add(u,v,w),add(v,u,w); }
int n,m,q;
long long ans;
long long st;
int s,t;
void dfs(int u){
	if(st>m) return ;
	if(u==t) ans=max(ans,st);
	for(int i=h[u];i;i=e[i].nex){
		int v=e[i].to; long long w=e[i].val;
		st*=w;
		dfs(v);
		st/=w;
	}
}
int main(){
	freopen("tour.in","r",stdin);
	freopen("tour.out","w",stdout);
	IO::read(n,m,q);
	for(int i=2;i<=m;i++){
		int u,v; IO::read(u,v);
		add_edge(u,v,i);
	}
	for(;q--;){
		IO::read(s,t);
		st=1,ans=-1;
		dfs(s);
		IO::write(ans,'\n');
	}
	return 0;
}
