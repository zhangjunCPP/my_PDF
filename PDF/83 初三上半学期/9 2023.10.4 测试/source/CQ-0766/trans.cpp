/* 
天安门广场续集：1e9 个国家平分 100 个据点。
首先这个国家数量过于吓人，然后我感觉他不重要，只要确定几个国家参与、分配方式再组合数一下。
然后有一堆0边很牛逼，这些边可以做成必选。
然后这张图点边数量很TM神奇，以及有树还全随机。
综上，猜测是个dp然后矩阵迭代啥的搞一搞。
 */
#include<bits/stdc++.h>
namespace IO{
	#define _fre_(file,in,out) { \
		if(in) std::freopen(file".in","r",stdin); \
		if(out) std::freopen(file".out","w",stdout); \
	}
	template<typename _Tp>
	void read(_Tp &x){
		x=0;bool sign=false;char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()) sign|=ch=='-';
		for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+(sign?-(ch&15):(ch&15));
	}
	template<typename _Tp>
	void write(_Tp x){
		if(x<0) putchar('-'),x=-x;
		if(x>9) write(x/10);
		putchar((x%10)|48);
	}
	void write(char ch){putchar(ch);}
}
template<typename ...Args>
void read(Args &...args){(void)std::initializer_list<int>{(IO::read(args),0)...};}
template<typename ...Args>
void write(Args ...args){(void)std::initializer_list<int>{(IO::write(args),0)...};}
namespace MAIN{
    constexpr int mod=1e9+7;
    constexpr int N=105,M=105;
	using ll=long long;
	int fac[N],inv[N];
	int qpow(ll a,int x){int ret=1;for(;x;x>>=1,a=a*a%mod) if(x&1) ret=ret*a%mod;return ret;}
	int C(int n,int m){
		if(n<m) return 0;
		// std::printf("%d %d: %d %d %d\n",n,m,fac[n],inv[m],inv[n-m]);
		if(n>=N){
			ll up=1;
			for(int i=n-m+1;i<=n;++i) up=up*i%mod;
			return up*inv[m]%mod;
		}
		else return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
	}
    int n,m,k;
	struct edge{int u,v,diff,same;};
	edge E[M];
	std::vector<int> with[N],out[N];
	namespace solve1{
		int ans=0;
		int col[N];
		bool eva;
		void dfs(int u){
			if(u==n+1){
				ll tmp=1;
				for(int i=1;i<=m;++i)
					if(col[E[i].u]==col[E[i].v]) (tmp*=E[i].same)%=mod;
					else (tmp*=E[i].diff)%=mod;
				if(eva){
					static std::set<int> S;
					S.clear();
					for(int i=1;i<=n;++i) S.emplace(col[i]);
					ans=(ans+tmp*C(k,S.size()))%mod;
				}
				else ans=(ans+tmp)%mod;
				return;
			}
			if(!with[u].empty()){
				for(int v:with[u]) if(~col[v]){
					col[u]=col[v];
					dfs(u+1);
					col[u]=-1;
					return;
				}
			}
			for(int i=1;i<=(eva?n:k);++i){
				col[u]=i;
				dfs(u+1);
				col[u]=-1;
			}
		}
		void _main_(){
			std::memset(col,-1,sizeof col);
			eva=k>100;
			ans=0;
			dfs(1);
			write(ans,'\n');
			return;
		}
	}
	void _main_(){
        read(n,m,k);
		for(int i=1;i<=n;++i) with[i].clear(),out[i].clear();
        for(int i=1,u,v,d,s;i<=m;++i){
			read(u,v,d,s),E[i]={u,v,d,s};
			if(!d) with[u].emplace_back(v),with[v].emplace_back(u);
			else out[u].emplace_back(v),out[v].emplace_back(u);
		}
		if(n<=9) return solve1::_main_();
		return;
	}
}
signed main(){
	_fre_("trans",0,0);
    int T;
	MAIN::fac[0]=MAIN::inv[0]=1;
	for(int i=1;i<MAIN::N;++i) MAIN::inv[i]=MAIN::qpow(MAIN::fac[i]=1ll*MAIN::fac[i-1]*i%MAIN::mod,MAIN::mod-2);
    for(read(T);--T;) MAIN::_main_();
	return MAIN::_main_(),0;
}
/* 
g++ -std=c++14 -O2 -Wall -Wextra -fsanitize=address,undefined trans.cpp -o trans
./trans < "/mnt/hgfs/win_d/CQ-0766/trans_data/ex_trans1.in"
 */