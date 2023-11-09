#include<bits/stdc++.h> 
using namespace std;
const int p=1000000007;
int t,n,m,k;
int inv[105],u[105],v[105],d[105],s[105];
int C(int n,int m){
	int ans=1;
	for(int i=n-m+1;i<=n;i++)ans=1ll*ans*i%p;
	for(int i=1;i<=m;i++)ans=1ll*ans*inv[i]%p;
	return ans;
}
int ans,cnt;
int c[105],vis[105];
void dfs(int now,int x){
	if(cnt>n-now+1)return;
	if(now==n+1){
		long long mul=1;
		for(int i=1;i<=m;i++)mul=1ll*mul*(c[u[i]]==c[v[i]]?s[i]:d[i])%p;
		ans=(ans+mul)%p;
		return;
	}
	for(int i=1;i<=x;i++){
		cnt-=(!vis[i]++);c[now]=i;
		dfs(now+1,x);
		cnt+=(!--vis[i]);
	}
}
void Freopen(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d",&t);
	inv[0]=inv[1]=1;
	for(int i=2;i<=100;i++)inv[i]=1ll*inv[p%i]*(p-p/i)%p;
	while(t--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++)scanf("%d%d%d%d",&u[i],&v[i],&d[i],&s[i]);
		int sum=0;
		for(int i=1;i<=min(k,n);i++){
			ans=0; 
			cnt=i;
			dfs(1,i);
			sum=(sum+1ll*ans*C(k,i)%p)%p;
		}
		printf("%d\n",sum);
	}
}
