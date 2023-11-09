#include<bits/stdc++.h>
using namespace std;
template<typename T> void _(T &x){
	x=0; bool f=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	if(f) x=-x;
}
#define int long long
const int INF=0x3f3f3f3f3f3f3f3f;
const int N=2e5+5;
int n,a[N];
namespace DFS{
	int cnt;
	vector<int> st[N];
	int calc(){
		int maxn=-INF,minn=INF;
		for(int i=1;i<=cnt;i++){
			int sum=0;
			for(auto j:st[i]) sum+=a[j];
			maxn=max(maxn,sum),minn=min(minn,sum);
		}
		return maxn-minn;
	}
	int ans=INF;
	void dfs(int step){
		if(step>n){
			ans=min(ans,calc());
			return ;
		}
		if(step>1&&st[cnt].size()<2){
			st[cnt].emplace_back(step);
			dfs(step+1);
			st[cnt].pop_back();
		}
		st[++cnt].emplace_back(step);
		dfs(step+1);
		st[cnt--].pop_back();
	}
	void work(){
		dfs(1);
		printf("%lld",ans);
	}
}
namespace WA{
	pair<int,int> dp[N][2];
	int get_val(int i,int j){
		return max(dp[i-1][j].first,a[i])-min(dp[i-1][j].second,a[i]);
	}
	pair<int,int> get_pair(int i,int j){
		return make_pair(max(dp[i-1][j].first,a[i]),min(dp[i-1][j].second,a[i]));
	}
	void work(){
		for(int i=1;i<=n;i++) dp[i][0]=dp[i][1]=make_pair(-INF,INF);
		dp[1][0]=make_pair(a[1],a[1]); 
		dp[2][0]=make_pair(max(a[1],a[2]),min(a[1],a[2]));
		dp[2][1]=make_pair(a[1]+a[2],a[1]+a[2]);
		for(int i=3;i<=n;i++){
			dp[i][0]=(get_val(i,0)<get_val(i,1))?get_pair(i,0):get_pair(i,1);
//			printf("i:%lld type:0 first:%lld second:%lld\n",i,dp[i][0].first,dp[i][0].second);
			dp[i][1]=make_pair(max(dp[i-1][0].first,a[i-1]+a[i]),min(dp[i-1][0].second,a[i-1]+a[i])); 
//			printf("i:%lld type:1 first:%lld second:%lld\n",i,dp[i][1].first,dp[i][1].second);
		}
		printf("%lld",min(dp[n][0].first-dp[n][0].second,dp[n][1].first-dp[n][1].second));
	}
	
}
signed main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	_(n);
	for(int i=1;i<=n;i++) _(a[i]);
	if(n<=18) DFS::work();
	else WA::work();
	return 0;
}
/*
5
2 2 3 5 2
*/
