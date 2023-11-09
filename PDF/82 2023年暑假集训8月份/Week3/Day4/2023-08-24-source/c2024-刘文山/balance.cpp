#include<bits/stdc++.h>
using namespace std;
const int maxn=300005;
int n;
vector<int> G[maxn];
int siz[maxn],fa[maxn];
inline void dfs(int x,int f){
	siz[x]=1;
	for(auto v:G[x]){
		if(v==f) continue;
		fa[v]=x;
		dfs(v,x);
		siz[x]+=siz[v];
	}
}
int RT=0;
int SIZ[maxn],dp[maxn];
inline void get_rt(int x,int sum,int f){
	dp[x]=0;
	SIZ[x]=1;
	for(auto y:G[x]){
		if(y==f) continue;
		get_rt(y,sum,x);
		SIZ[x]+=SIZ[y];
		dp[x]=max(dp[x],SIZ[y]);
	}
	dp[x]=max(dp[x],sum-SIZ[x]);
	if(dp[x]<dp[RT]) RT=x;
}
inline void solve1(){//暴力 
	for(int i=1;i<=n;i++){
		int rt=0,sum=0;
		for(auto x:G[i]){
			if(x==fa[i]){
				if(sum<n-siz[i]){
					rt=x;
					sum=n-siz[i];
				}
			}
			else{
				if(sum<siz[x]){
					rt=x;
					sum=siz[x]; 
				}
			}
		}
		RT=0;
		get_rt(rt,sum,i);
		printf("%d\n",RT);	
	}
}
inline void solve2(){//菊花图
	printf("2\n");
	for(int i=2;i<=n;i++){
		printf("1\n");
	} 
}
inline void solve3(){//链 
	for(int i=1;i<=n;i++){
		int len1=i-1,len2=n-i;
		if(len1>len2){
			printf("%d\n",(len1-1)/2+1);
		}
		else{
			printf("%d\n",(len2-1)/2+1+i);
		}
	}
}
int main(){
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout); 
	scanf("%d",&n);
	bool f1=1,f2=1;
	dp[0]=n+1;
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
		if(x!=1 || y!=i+1)
			f1=0;
		if(x!=i || y!=i+1)
			f2=0;
	}
	if((!f1) && (!f2)){
		dfs(1,1);
		solve1(); 
	}
	else if(f1){
		solve2();
	}
	else if(f2){
		solve3(); 
	}
	else{
		for(int i=1;i<=n;i++)
			cout<<"肘鸡\n"; 
	}
	return 0;
}
/*口胡 n^2
首先删去一个点，会使得他的子树变成若干森林。
那么，发动人类智慧，肯定就从大的子树删除。
删除的点，就在最大的子树中求重心即可。
对于 100 % 的数据应该不会太难。
肯定就是优化找重心的过程，树形 dp + 换根？
6！
其实我觉得在看一下性质分就差不多了，毕竟T3不是相切就切。
对于部分数据是一条链，还有菊花图。
菊花图很简单，直接输出 1 就行了，1输出 2。
对于链的情况：
一个点分成两条链，直接将长的那条链折半就好了。
所以 60 分就这么水，这该不会是普及+ 提高- 的难度吧。。。 
刚好 114 行，真是牛逼！ 
*/ 
