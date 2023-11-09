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
using ll=long long;
const int N=305;
const ll p=65535,base=256;
ll pwr[N];
void init(){
	pwr[0]=1;
	for(int i=1;i<N;i++) pwr[i]=pwr[i-1]*base%p;
}
int k,n;
ll ans=1;
bitset<N> vis;
vector<ll> now,st;
ll calc(){
	ll tmp=0;
	for(int i=0;i<(int)st.size();i++) tmp=(tmp+now[i]*pwr[i]%p)%p;
	return tmp;
}
void dfs(int cnt){
	if(cnt==n+1){
//		for(auto v:now) IO::Write(v,'&');
//		IO::Write('\n');
		ans=ans*calc()%p;
		return ;
	}
	for(int i=0;i<n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		now.emplace_back(st[i]);
		dfs(cnt+1);
		now.pop_back();
		vis[i]=0;
	}
}
void solve(){
	now.clear();
	vis.reset();
	IO::Read(k);
	ans=1,n=0;
	st.clear();
	for(int i=1;i<=k;i++){
		int x,y; IO::Read(x,y);
		n+=y;
		for(;y--;) st.emplace_back(x);
	}
	dfs(1);
	IO::Write(ans,'\n');
}
int T;
int main(){
	freopen("secret.in","r",stdin);
	freopen("secret.out","w",stdout);
	init();
	IO::Read(T);
	for(;T--;) solve();
	return 0;
}

