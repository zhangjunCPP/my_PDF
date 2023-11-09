#include<bits/stdc++.h>
using namespace std;
int n,m,siz;
int G[21][21];
char s[21];
vector< pair<int,int> > v;
int d[21],ans;
const int mod=998244353;
inline void dfs(int now){
	if(now==siz){
		bool f=1;
		for(int i=1;i<=n;i++){
			if(s[i]=='1' && d[i]<2) f=0;
		} 
		if(f) ans++;
		return ;
	}
	dfs(now+1);
	d[v[now].first]++;
	d[v[now].second]++;
	dfs(now+1);
	d[v[now].first]--;
	d[v[now].second]--;
}
inline void solve1(){
	v.clear();
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(s[i]=='1' && s[j]=='1' && G[i][j]){
				v.push_back(make_pair(i,j));
			}
		}
	}
	siz=v.size();
	memset(d,0,sizeof d); 
	ans=0;
	dfs(0);
	printf("%d\n",ans);
}
inline int C(int n,int m){
	if(n<m) return 0;
	int jc=1ll;
	for(int i=max(n-m,m)+1;i<=n;i++) jc*=i;
	for(int i=1;i<=min(n-m,m);i++) jc/=i;
	return jc;
}
inline void solve2(){
	memset(d,0,sizeof d);
	int M=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s[i]=='1' && s[j]=='1' && G[i][j]){
				d[i]++;
				M++;
			}
		}
	}
	M/=2;
	int sum=0;
	for(int i=1;i<=n;i++){
		sum|=((s[i]-'0')<<(i-1));
	}
	ans=0;
	for(int S=0;S<(1<<n);S++){
		if(S|sum>sum) continue;
		int ss=1,cnt=0;
		for(int i=0;i<n;i++){
			if((S>>i)&1){
				cnt++;
				ss*=C(d[i+1],2);
			}	
		}
		/*
		垃圾题目，不做了。 
		
		*/
	}
} 
int main(){
	freopen("big.in","r",stdin);
	freopen("big.out","w",stdout); 
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		G[x][y]=G[y][x]=1;
	}
	int q;
	scanf("%d",&q);
	while(q--){
		scanf("%s",s+1);
		solve1();
	}
	return 0;
}
/*
对于每个点的度都 >=2 。
那不就是一颗无根树的叶子节点都连一条边连出来的吗？
感觉会变成树形dp+容斥等一些怪糟糟的东西。
初始想法肯定就是枚举每一条边是否选入。
可以过前两个点。
后面的点数增长的较慢，难不成剪枝。
钦定严格每个点的度数是 2 的子图是小度图。
那么对于小度图外边的补集是可以随便选的。
设边数为 m ，点数为 n。
那么方案数在乘上一个系数。
但好像会算漏，因为不是所有大度图都可以生成小度图。
可以用容斥算一下：
>=0 的个数，也就是所有方案数。 
减去。。。。。。
或者钦定一个点度数>=2-2个点+3个点。
不行，点太乱了，长得不一样。
或者状压？ 锤子。
改成钦定一个点集度数>=2的方案数。
点集内部会有连边，不好处理。
看看会不会算重复吧。
用二项式反演证证：
证锤子，SB，伪了。
但是我感觉我接近正解了。
因为单次复杂度是 2^n
1e5 次可以考虑只做一次来求答案，因为所有都是点集的子集。
悲伤。
打下来吧，lz也不管正确性了。
先写下来再说。 
最后发现写和不写差不多，摆烂。 
*/
