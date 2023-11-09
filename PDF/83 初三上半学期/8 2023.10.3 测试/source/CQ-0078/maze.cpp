/*
图上dp？
普通dp不好写，写记忆化？
设 f[i]表示的第i个点到离开点的最少花费
对于一个点，便利连接的每一个点，时间就是第d[u]+1个
因为w没有非负数，用一个vis数组统计走没走过
最后输出f[1]
时间n+m级别 

过了？怎么这么水？ 
不对，好像会爆longlong 
*/

#include<bits/stdc++.h>
#define int long long
void read(int &x){
	x=0;bool f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
	if(f)x=-x;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	char stk[14];int tot=0;
	do stk[++tot]=x%10+48,x/=10;while(x);
	for(;tot;tot--)putchar(stk[tot]);
}

#define inf 0x3f3f3f3f3f3f
const int maxn=2e5+4;
int n,m,k,s[maxn],d[maxn];
long long dp[maxn];
std::vector<std::pair<int,int> >E[maxn];
bool vis[maxn];
int dfs(int x){
	if(dp[x]<inf)return dp[x];
	if(vis[x])return inf;//环的情况 
	vis[x]=1;
	std::priority_queue<int>que;
	for(auto v:E[x]){
		int lp=dfs(v.first);
		if(lp!=inf)que.push(-lp-v.second);
	}
	vis[x]=0;
	dp[x]=inf;
	for(int i=1;i<=d[x]&&que.size();++i)que.pop();
	if(que.size())dp[x]=-que.top();
	return dp[x];
}
signed main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	read(n);read(m);read(k);
	for(int i=1;i<=k;++i)read(s[i]);
	for(int i=1;i<=n;++i)read(d[i]);
	for(int i=1;i<=m;++i){
		int x,y,val;read(x);read(y);read(val);
		E[x].emplace_back(std::make_pair(y,val));
		E[y].emplace_back(std::make_pair(x,val));
	}
	for(int i=1;i<=n;++i)dp[i]=inf;
	for(int i=1;i<=k;++i)dp[s[i]]=0;
	write(dfs(1));
	return 0;
}
