#include<bits/stdc++.h>
#define _fre_(file,in,out) (in&&(std::freopen(file".in","r",stdin))),(out&&(std::freopen(file".out","w",stdout)))
namespace IO{
	template<typename _Tp>
	void read(_Tp &&x){
		x=0;bool sign=false;char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') sign=true;
		for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+(sign?-(ch&15):(ch&15));
	}
	void read(char *str){
		for(;(*str=getchar())==' '||*str=='\n';);
		for(;(*++str=getchar())!=' '&&*str!='\n';);
		*str='\0';
	}
}
template<typename ...Args>
void read(Args &&...args){(void)std::initializer_list<int>{(IO::read(args),0)...};}
using ll=long long;
constexpr int N=1e6+5;
constexpr ll mod=998244353;
int n;
struct edge{int u,v;};
edge E[N];
ll ans;
void dfs(int e){
	static bool col[N];
	if(e==n) return ++ans,void();
	if(!col[E[e].u]&&!col[E[e].v]){
		col[E[e].u]=true,dfs(e+1),col[E[e].u]=false;
		col[E[e].v]=true,dfs(e+1),col[E[e].v]=false;
	}
	else dfs(e+1);
}
int fib(int n){
	if(n<=3) return n;
	int x=1,y=2;
	for(int z=--n;--n;) z=(x+y)%mod,x=y,y=z;
	return y;
}
signed main(){
	_fre_("tree",1,1);
	bool sub4=true,sub5=true;
	read(n);
	for(int i=2,u,v;i<=n;++i){
		read(u,v);
		sub4&=u==1&&v==i;
		sub5&=u==v-1;
		E[i-1]={u,v};
	}
	if(sub4) return std::printf("%d",n),0;
	else if(sub5) return std::printf("%d",fib(n)),0;
	else return dfs(1),std::printf("%lld",ans),0;
	return 0;
}
/*
g++ -std=c++14 -O2 -o code -Wall -Wextra -fsanitize=address,undefined tree.cpp
./code < tree/ex_tree1.in
*/