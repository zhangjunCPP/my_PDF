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
const int p=998244353;
const int N=20;
int q,n,m;
int ans;
vector<int> e[N];
bitset<N> dk;
bitset<N> st;
int d[N];
bool check(){
	memset(d,0,sizeof d);
	for(int i=1;i<=n;i++) if(st[i]){
		for(auto v:e[i]) d[v]++;
	}
	for(int i=1;i<=n;i++) if(d[i]<2) return 0;
	return 1;
}
void dfs(int step){
	if(step==n+1){
		ans=(ans+check())%p;
		return ;
	}
	if(dk[step]){
		st[step]=1;
		dfs(step+1);
		st[step]=0;
		dfs(step+1);
	}else dfs(step+1);
}
int main(){
	freopen("big.in","r",stdin);
	freopen("big.out","w",stdout);
	IO::read(n,m);
	for(int i=1;i<=m;i++){
		int u,v; IO::read(u,v);
		e[u].emplace_back(v),e[v].emplace_back(u);
	}
	IO::read(q);
	for(;q--;){
		for(int i=1;i<=n;i++){
			int x; scanf("%1d",&x);
			dk[i]=x; 
		}
		ans=0;
		st.reset();
		dfs(1);
		IO::write(ans,'\n');
	}
	return 0;
}
