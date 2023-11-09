#include<bits/stdc++.h>
template<typename T> void _(T &x){
	x=0; bool f=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	if(f) x=-x;
}
const int N=1e6+5;
const int p=998244353;
int n;
struct edge{
	int u,v;
}e[N];
namespace sub1{
	bool check(){
		for(int i=1;i<n;i++) if(e[i].u!=i||e[i].v!=i+1) return 0;
		return 1; 
	}
	int f[N];
	void work(){
		f[2]=2,f[3]=3;
		for(int i=4;i<=n;i++) f[i]=(f[i-1]+f[i-2])%p;
		printf("%d",f[n]);
	}
}
namespace sub2{
	bool check(){
		for(int i=1;i<n;i++) if(e[i].u!=1||e[i].v!=i+1) return 0;
		return 1; 
	}
	void work(){
		printf("%d",n);
	}
}
namespace sub3{
	bool now[N];
	int ans;
	void dfs(int step){
		if(step>n-1){
			ans=(ans+1)%p;
			return ;
		}
		if(!now[e[step].u]&&!now[e[step].v]){
			now[e[step].u]=1;
			dfs(step+1);
			now[e[step].u]=0;
			now[e[step].v]=1;
			dfs(step+1);
			now[e[step].v]=0;
		}else dfs(step+1);
	}
	void work(){
		ans=0;
		dfs(1);
		printf("%d",ans);
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	_(n);
	for(int i=1;i<n;i++) _(e[i].u),_(e[i].v);
	if(sub1::check()) sub1::work();
	else if(sub2::check()) sub2::work();
	else sub3::work();
	return 0;
}
/*
5
1 2
1 3
1 4
1 5

7
7 2
7 6
1 2
7 5
4 7
3 5 
*/
