#include<bits/stdc++.h>
using namespace std; 
inline void read(int &x){
	x=0;
	bool f=0;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	if(f) x=-x;
}
int n,m;
const int maxn=1e6+5; 
vector<int> G[maxn];
int d[maxn],vis[maxn];
inline void solve(){
	read(n),read(m);
	for(int i=1;i<=n;i++){
		vis[i]=0,d[i]=0; G[i].clear();
	}
	for(int i=1,x,y;i<=m;i++){
		read(x),read(y);
		d[x]++; d[y]++;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,d[i]);
	if(ans>=3){
		printf("%d\n",ans);
		return ;
	}
	bool f=0;
	for(int i=1;i<=n;i++){
		for(auto j:G[i]) vis[j]=1;
		for(auto j:G[i]){
			for(auto k:G[j]){
				if(vis[k]) f=1;
			}
		}
		for(auto j:G[i]) vis[j]=0;
	}
	if(f) ans=max(ans,3);
	printf("%d\n",ans);
}
int main(){
	freopen("match.in","r",stdin); 
	freopen("match.out","w",stdout); 
	int T; 
	read(T);
	while(T--){
		solve();
	} 
	return 0;
}
/*
T1 感觉简单
图合法匹配很少
因为任意两条边共端点。
暴力给的很多，所以感觉简单。
考虑一下，对于 3 元环，是合法的匹配。
还有一种类似于菊花图，以一个点为中心，周围的点都能选。
答案就是度数。
证明了充分性 
如何证明只有这两种情况必要性：
考虑一个环，如果出现了4个点，就一定不行。
对边不共端点。
因为是对于任意两条边，所以对于完全图也无伤大雅。
所以图中只要选出了4元环及以上，一定GG。
所以只能包含3元环。
同时3元环必须裸的，但凡外面多加一个点，就有一条边不相邻。
对于菊花情况，也是一样的，所以本题判断一下是否存在3元环。
存在和度数取max即可。 
1e6直接三元环计数 m sqrt(m) 有点危险，只给了 1s。
虽然跑不满，不知道能不能卡。
没有其他更好的算法了。。。 
只用判断是否存在3元环应该好判吧。
不能生成树来搞。 那不如还是用3元环计数问题。
没关系，我觉得可以乱搞。
当ans<3时，我才看有没有三元环，>=3直接拜拜。
说明每个点的度数都<=3然后我枚举两层，不就是9的常数吗？
6。 
小丑题目。 
*/
