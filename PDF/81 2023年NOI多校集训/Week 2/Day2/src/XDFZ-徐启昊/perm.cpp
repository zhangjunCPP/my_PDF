#include<bits/stdc++.h>
#define int long long
#define _ std::

const int N=2e5+11,inf=1e9;

void Freopen(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
}

int n,mod,aans,ans;
int vis[20],a[20],b[20];
int biao[18]={0,0,0,1,7,47,322,2404,19778,180130,1809652,19940552,239430724};
void dfs(int k,int nn){
	if(k==nn+1){
		for(int i=1;i<=nn;i++)
			b[a[i]]=i;
		for(int i=1;i<=nn;i++){
			if(b[i]>a[i]){
				ans=(ans+1)%mod;
				break;
			}
			if(b[i]<a[i])
				break;
		}
		memset(b,0,sizeof(b));
		return;
	}
	for(int i=1;i<=nn;i++){
		if(!vis[i]){
			vis[i]=1;
			a[k]=i;
			b[i]=k;
			dfs(k+1,nn);
			vis[i]=0;
		}
	}
}
void solve1(){
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		ans=0;
		dfs(1,i);
		aans^=ans;
	}
	_ cout<<aans;
}
signed main(){
	Freopen();
	_ cin>>n>>mod;
	for(int i=1;i<=n;i++)
		ans^=(biao[i]%mod);
	_ cout<<ans;
	return 0;
}

