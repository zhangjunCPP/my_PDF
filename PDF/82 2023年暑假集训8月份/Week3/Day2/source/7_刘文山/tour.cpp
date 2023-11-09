#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
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
}
int n,m,q;
vector< pair<int,int> > G[maxn];
bool dp[1005][1005],dp2[1005][1005];
int s,t;
inline void solve1(){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			dp[i][j]=0;
		}
	}
	dp[s][1]=1;
	for(int i=1;i<=log2(m);i++){
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				dp2[i][j]=dp[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(auto j:G[i]){
				int to=j.first,w=j.second;
				for(int val=1;val*w<=m;val++){
					dp[to][val*w]|=dp2[i][val];
				}
			} 
		}
	}
	int ans=m;
	for( ; ans>=0; ans--){
		if(dp[t][ans]) break;
	}
	if(ans) printf("%d\n",ans);
	else puts("-1");
} 
int main(){
	freopen("tour.in","r",stdin);
	freopen("tour.out","w",stdout); 
	read(n),read(m),read(q);
	for(int i=2,x,y;i<=m;i++){
		read(x),read(y);
		G[x].push_back(make_pair(y,i));
		G[y].push_back(make_pair(x,i));
	}
	while(q--){
		scanf("%d%d",&s,&t);
		solve1();
	} 
	return 0;
}
/*
dp i j
表示从 S 开始走是否能走到 i 并且权值为 j。
总共可能转移 log m 次。
每次复杂度是 nm。
总时间复杂度是 O(nm log m)。
可以过 40 分？
能不能把 m 那一维压入 bitset 中。
如果可以：
复杂度 O(n log m m/w) 可以过 60?
但是是乘法不是很好转移。。。。 
知足者长乐，长乐者知足。
mad，还有 40 min ，就先这样差不多了。
好像还有个 SB q 的复杂度没算。
cao，就这样，打了先说。 
刚才好像算错了是 m^2 log m 的。
打完暴力，还有半小时，考虑优化。 
我觉得可以用 bitset 优化一波。
考虑一个数乘上一个 w 的会发生什么。
1,2,3,4,...  -> w,2w,3w,4w.....
好像也不是很好搞。
至少有点规律。
说实话 w 是一个调和级数，所以暴力复杂度是:
m^log^2m 
还是比较优秀了，主要是有一个SB询问次数，还有 SB 空间大小。
空间大小是 O n m 的很悲惨。
我觉得 1e4 肯定要开一些科技。 
我是可以如果怕 q 过大，我是可以提前处理的哈。
也可以算一次记录一次答案，就保证他最多算 n 次。
所以是 n m^log^2m 
还是没想到优化。
wtcl。
最后也不想处理 q 了。
就让他 q m log^2 m
出题人要卡这 20 pts 就卡吧，我也不想挣扎了。 
*/
