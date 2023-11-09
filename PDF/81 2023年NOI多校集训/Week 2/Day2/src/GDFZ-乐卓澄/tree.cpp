#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
const int mod=1e9+7;
bool flaga,flagb,flagc;
int n,cnt,head[maxn],tot,dep[maxn],d1,d2,ans,ito[maxn];
bool vis[maxn];
struct edge{
	int to,nxt;
}e[maxn<<1];
void addedge(int u,int v){
	e[++cnt]={v,head[u]};
	head[u]=cnt;
}
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans*=a;
			ans%=mod;
		}
		a*=a;
		a%=mod;
		b>>=1;
	}
	return ans;
}
void dfs(int u,int fa,bool t){
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(!vis[v]&&v!=fa){
			dep[v]=dep[u]+1;
			dfs(v,u,t);
			if(t){
				if(dep[v]==dep[d2])tot++;
				else if(dep[v]>dep[d2]){
					d2=v;
					tot=1;
				}
			}
			else {
				if(dep[v]>dep[d1])d1=v;
			}
		}
	}
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		addedge(u,v);
		addedge(v,u);
		if(abs(u-v)!=1)flaga=1;
		if(u!=1&&v!=1)flagb=1;
		ito[u]++,ito[v]++;
	}
	if(!flaga){
		for(int i=1;i<n;i++){
			ans+=i*(n-i)%mod*qpow(2,n-i)%mod;
			ans%=mod;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(!flagb){
		if(n==3){
			puts("16");
			return 0;
		}
		ans=qpow(2,n)*2%mod;
		cout<<ans<<endl;
		return 0;
	}
	dfs(1,0,0);
	dep[d1]=0;
	dfs(d1,0,1);
	while(n>1){
		ans+=(dep[d2])*qpow(2,n-1)%mod;
		n-=2;
		vis[d1]=1,vis[d2]=1;
		d1=d2=0;
		dep[d2]=0;
		dfs(1,0,0);
		dep[d1]=0;
		dfs(d1,0,1);
		ans%=mod;
	} 
	cout<<ans<<endl;
}
