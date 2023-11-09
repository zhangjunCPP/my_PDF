#include<bits/stdc++.h>
using namespace std;
int rd(int x=0,char c=getchar()){int f=1;while(!isdigit(c))f=(c=='-'?1:-1),c=getchar();while(isdigit(c))x=x*10+c-48,c=getchar();return x*f;}
int n,m;
//vector<int> E[N];
using ll=long long;
long long ans;
const long long mod=998244353;
/*ll ksm(ll a,ll b){
	ll r=1;
	while(b){
		if(b&1)r=r*a%mod;
		a=a*a%mod,b>>=1;
	}return r;
}*/
struct Edge{
	int u,v;
}E[454];
int vis[234],pos[3122],r[4534];
void dfs(int x){
	if(x==m+1){
		for(int i=1;i<=n;i++)if(vis[i]&&r[i]<2)return;
		ans+=1;ans%=mod;
		return;
	}
	if(vis[E[x].u]&&vis[E[x].v]){
		r[E[x].u]++,r[E[x].v]++;
		pos[x]=1,dfs(x+1);
		r[E[x].u]--,r[E[x].v]--;
	}
	pos[x]=0;
	dfs(x+1);
}
int main(){
	freopen("big.in","r",stdin);
	freopen("big.out","w",stdout);
	n=rd(),m=rd();
	for(int i=1;i<=m;i++){
		int u=rd(),v=rd();
		E[i]={u,v};
	}int q=rd();
	while(q--){
		for(int i=1;i<=n;i++)scanf("%1d",&vis[i]);
		ans=0,dfs(1);
		printf("%lld\n",ans);
	}
	return 0;
}

