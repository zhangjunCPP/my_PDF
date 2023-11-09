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
const int N=2e5+5;
int v[N],n;
namespace sub1{
	bool check(){
		for(int i=1;i<=n;i++) if(v[i]!=i) return 0;
		return 1;
	}
	void work(){
		ll ans=0;
		for(int i=1;i<n;i++) ans+=v[i];
		IO::Write(ans,'\n');
		for(int i=n;i;i--) IO::Write(i,' ');
	}
}
namespace sub2{
	bool check(){
		for(int i=1;i<=n;i++) if(v[i]!=n+1-i) return 0;
		return 1;
	}
	void work(){
		ll ans=(ll)v[1]*(ll)(n-1);
		IO::Write(ans,'\n');
		for(int i=2;i<=n;i++) IO::Write(i,' ');
		IO::Write(1);
	}
}
namespace sub3{
	ll ans;
	int asd[N];
	bitset<N> vis;
	pair<int,int> a[N],st[N];
	ll calc(){
		ll res=0;
		stack<int> stk;
		for(int i=1;i<=n;i++){
			for(;!stk.empty()&&stk.top()>st[i].first;stk.pop()) res+=st[i].second;
			stk.emplace(st[i].first);
		}
		return res;
	}
	void dfs(int cnt){
		if(cnt==n+1){
			ll tmp=calc();
			if(tmp>ans){
				ans=tmp;
				for(int i=1;i<=n;i++) asd[i]=st[i].first;
			}
			return ;
		}
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			vis[i]=1;
			st[cnt]=a[i];
			dfs(cnt+1);
			vis[i]=0;
		}
	}
	void work(){
		for(int i=1;i<=n;i++) a[i]=make_pair(i,v[i]);
		dfs(1);
		IO::Write(ans,'\n');
		for(int i=1;i<=n;i++) IO::Write(asd[i],' ');
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	IO::Read(n);
	for(int i=1;i<=n;i++) IO::Read(v[i]);
	if(sub1::check()) sub1::work();
	else if(sub2::check()) sub2::work();
	else sub3::work();
	return 0;
}
