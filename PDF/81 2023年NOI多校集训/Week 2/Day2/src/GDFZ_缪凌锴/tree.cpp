#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<bitset>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1e6+10;
const int INF=0x3f3f3f3f;
const long long LINF=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
int n;
long long ans=0;
vector <int> vec[MAXN];
void add_edge(int x,int y){
	vec[x].push_back(y);
}
bool val[MAXN];
int dp0[MAXN],dp1[MAXN];
int dad[MAXN];
int res;
void dfs(int x){
	if(val[x]){
		dp1[x]=0;
	}
	else{
		dp0[x]=0;
	}
	for(int i=0;i<vec[x].size();i++)
	{
		int to=vec[x][i];
		if(to==dad[x]){
			continue;
		}
		dad[to]=x;
		dfs(to);
		if(val[to]){
			res=max(res,dp1[x]+dp1[to]+1);
		}
		else{
			res=max(res,dp0[x]+dp0[to]+1);
		}
		dp0[x]=max(dp0[x],dp0[to]+1);
		dp1[x]=max(dp1[x],dp1[to]+1);
	}
	if(val[x]){
		res=max(res,dp1[x]);
	}
	else{
		res=max(res,dp0[x]);
	}
}
int get_val(){
	res=0;
	memset(dp0,-INF,sizeof(dp0));
	memset(dp1,-INF,sizeof(dp1));
//	for(int i=1;i<=n;i++)
//	{
//		cout << val[i];
//	}
//	cout << endl;
	dfs(1);
//	cout << res << endl;
	return res;
}
void dfs01(int d){
	if(d>n){
		ans+=get_val();
		ans%=mod;
		return ;
	}
	val[d]=true;
	dfs01(d+1);
	val[d]=false;
	dfs01(d+1);
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	if(n<=20){
		dfs01(1);
		printf("%lld\n",ans);
		return 0;
	}
	if(vec[1].size()==n-1){
		ans=1;
		for(int i=1;i<=n+1;i++)
		{
			ans*=2;
			ans%=mod;
		}
		printf("%lld\n",ans);
		return 0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
6
1 2
2 3
3 4
4 5
3 6
*/
