#include<bits/stdc++.h>
using namespace std;
namespace IO{
	void Read(double &x){
		x=0; bool f=0; char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
		for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+(ch^48);
		if(ch=='.'){
			double ccc=1; ch=getchar();
			for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+(ch^48),ccc*=10;
			x/=ccc;
		}
		if(f) x=-x;
	}
	void Read(string &x){
		x=""; char ch=getchar();
		for(;ch<'!'||ch>'~';ch=getchar());
		for(;ch>='!'&&ch<='~';ch=getchar()) x=x+ch;
	}
	template<typename T> void Read(T &x){
		x=0; bool f=0; char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
		for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
		if(f) x=-x;
	}
	template<typename T,typename ...Args> void Read(T &x,Args &...args){
		Read(x),Read(args...);
	}
	void Write(const string x){ int len=x.size(); for(int i=0;i<len;i++) putchar(x[i]); }
	void Write(const char x){ putchar(x); }
	template<typename T> void Write(T x){
		if(x<0) putchar('-'),x=-x;
		int stk[50],top=0;
		do stk[++top]=x%10,x/=10; while(x);
		for(;top;top--) putchar(stk[top]^48);
	}
	template<typename T,typename ...Args> void Write(const T x,const Args ...args){
		Write(x),Write(args...);
	}
}
namespace ALG{
	const double Pi=acos(-1);
	const double Eps=1e-7;
	template<typename T> T Min(const T a,const T b){ return a<b?a:b; }
	template<typename T,typename ...Args> T Min(const T a,const T b,const Args ...args){
		return Min(a,Min(b,args...));
	}
	template<typename T> T Max(const T a,const T b){ return a>b?a:b; }
	template<typename T,typename ...Args> T Max(const T a,const T b,const Args ...args){
		return Max(a,Max(b,args...));
	}
	template<typename T> void Swap(T &a,T &b){ a^=b^=a^=b; }
	template<typename T> T Abs(const T a){ return a<0?-a:a; }
	template<typename T> T Gcd(T a,T b){
		if(!a) return b;
		for(;a^=b^=a^=b%=a;);
		return b;
	}
}
const int N=3e5+5;

struct edge{
	int to,nex;
}e[N*2];
int h[N],cnt;
void add(int u,int v){ e[++cnt]=(edge){v,h[u]},h[u]=cnt; }
void add_edge(int u,int v){ add(u,v),add(v,u); }

int n,u[N],v[N];


namespace sub3{
	bool check(){
		for(int i=1;i<n;i++) if(u[i]!=i||v[i]!=i+1) return 0;
		return 1;
	}
	void work(){
		for(int i=1;i<=n;i++){
			if(i<=n/2) IO::Write((n-i)/2+i+1,'\n');
			else IO::Write(i/2,'\n');
		}
	}
}
namespace sub4{
	bool check(){
		for(int i=1;i<n;i++) if(u[i]!=1||v[i]!=i+1) return 0;
		return 1;
	}
	void work(){
		IO::Write(2,'\n');
		for(int i=2;i<=n;i++) IO::Write(1,'\n');
	}
}
namespace asd{
	int rt,sz[N],f[N];
	void dfs(int u,int fa){
		sz[u]=1,f[u]=0;
		for(int i=h[u];i;i=e[i].nex){
			int v=e[i].to;
			if(v==fa) continue;
			dfs(v,u);
			sz[u]+=sz[v];
			f[u]=ALG::Max(f[u],sz[v]);
		}
		f[u]=ALG::Max(f[u],sz[u]-f[u]);
		if(f[u]<=n/2) rt=u;
	}
	void work(){
		for(;;);
	}
}
int main(){
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	IO::Read(n);
	for(int i=1;i<n;i++) IO::Read(u[i],v[i]),add_edge(u[i],v[i]);
	if(sub3::check()) sub3::work();
	else if(sub4::check()) sub4::work();
	else asd::work();
	return 0;
}

