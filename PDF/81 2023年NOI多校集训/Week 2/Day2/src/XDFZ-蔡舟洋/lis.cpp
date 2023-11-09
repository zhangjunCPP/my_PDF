#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
int w[N],dp[4004][4004];
vector<int> E[N];
vector<int> pos;
int c[N];
void change(int x,int y){for(;x<=n;x+=(x&-x))c[x]=max(c[x],y);}
int ask(int x){int res=0;for(;x;x-=(x&-x))res=max(res,c[x]);return res;}
void dfs(int rt,int u,int dad){
	dp[rt][u]=ask(w[u]-1)+1;
	int pa[19],pb[19],tot=0; 
	for(int x=w[u];x<=n;x+=(x&-x))pa[++tot]=x,pb[tot]=c[x],c[x]=max(c[x],dp[rt][u]);
	pos.push_back(u);
	for(int v:E[u])if(v^dad)dfs(rt,v,u);
	pos.pop_back();
	for(int i=1;i<=tot;i++)c[pa[i]]=pb[i];
}
void add(int u,int dad){pos.push_back(u);for(int v:E[u])if(v^dad)add(v,u);}
int f[N],cnt[4004];
void solve(int u,int dad){
	vector<int> x;
	for(int i=1;i<=n;i++)x.push_back(cnt[i]);
	for(int v:E[u]){
		if(v==dad)continue;
		add(u,v);
		for(int k:pos)cnt[dp[u][k]]++,cnt[dp[k][u]]++;
		pos.clear();
		add(v,u);
		for(int k:pos)cnt[dp[v][k]]--,cnt[dp[k][v]]--;
		for(int i=n;i>=1;i--)if(cnt[i]){f[v]=i;break;}
		pos.clear();
		solve(v,u);
	}
	for(int i=1;i<=n;i++)cnt[i]=x[i-1];
}
int main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),E[u].push_back(v),E[v].push_back(u);
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		dp[i][i]=1;
		change(w[i],1);
		dfs(i,i,0);
		for(int i=1;i<=n;i++)c[i]=0;
	}
	int ans=998244353;
	for(int i=1;i<=n;i++){
		int tmp=0;
		for(int v:E[i]){
			add(v,i);
			for(int v1:pos)for(int v2:pos)tmp=max(tmp,dp[v1][v2]),cnt[dp[v1][v2]]++;
			pos.clear();
		}
		ans=min(ans,tmp);
	}
//	f[1]=tmp;
//	solve(1,0);
//	for(int i=1;i<=n;i++)ans=min(ans,f[i]),cout<<f[i]<<' ';
//	cout<<endl;
	printf("%d",ans);
	return 0;
}
/*
暴力算链的LIS，O(n^3)

然后枚举断点，算权值 O(n^3)

LIS好像可以O(n^2logn)求，但算权值还是O(n^3)

换根dp?好像可以。然后就可以O(n^2)求权值了 

但是我不会 O(nlogn)求lIS啊。

欸，这个值域小可以直接用树状数组。 

OK，LIS搞定，然后换根dp。 

。。。换根写挂了。 


5
1 2
2 3
3 4
4 5
1 2 3 4 5

*/
