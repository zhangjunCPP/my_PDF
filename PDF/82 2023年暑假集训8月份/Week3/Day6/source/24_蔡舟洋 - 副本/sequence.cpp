#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,k;
const ll mod=998244353;
int cnt[114514],sum,sm;
int vis[21][1048576];
int tot=0;
void check(int x,int q,int sb,int ct){
	if(sum>k)return;
	if(sb==n+1){
//		cerr<<x<<' '<<q<<endl;
//		if(x==7)cerr<<q<<endl;
		if(ct==0)return;
		if(vis[ct][q]!=tot)vis[ct][q]=tot,sum++;
		return ;
	}check(x,q,sb+1,ct);
	check(x,q*2+((x>>(sb-1))&1),sb+1,ct+1);
}
void dfs(int x,int len){
	if(len==n+1){
//		memset(vis,0,sizeof vis);
//		for(int j=1;j<=n;j++)vis[j].reset();
		tot++;
		sum=0;
		check(x,0,1,0);
		if(sum>k)return;
//		cerr<<x<<" "<<sum<<endl;
		cnt[sum]++;
		return;
	}dfs(x*2,len+1),dfs(x*2+1,len+1);
}
ll dp[44][253];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d",&n,&k);
//	int p=clock();
	dfs(0,1);
	for(int i=1;i<=k;i++)cout<<cnt[i]<<' ';
//	cerr<<endl<<clock()-p;
	return 0;
}

