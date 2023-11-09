#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10,mod=998244353;
int n,m,val[N];
vector<int>E[N];
int father[N],deep[N];
int s1[N],s2[N],tot1,tot2;
void dfs_t(int u,int fa){
	father[u]=fa;deep[u]=deep[fa]+1;
	for(int v:E[u]){
		if(v==fa)continue;
		dfs_t(v,u);
	}
}
int s[N],vis[N],ans,a[N],b[N];
void dfs(int k,int nn,int mm){
	if(k==nn+1){
		ans++;
		if(ans>=mod)ans-=mod;
		return;
	}
	for(int i=1;i<=mm;i++){
		for(int j=1;j<=mm;j++){
			if(i==j||vis[i]||vis[j])continue;
			if(s[k]==1){
				if(i<j)continue;
			}
			if(s[k]==0){
				if(i>j)continue;
			}
			if(i<a[k-1]||j<b[k-1])continue;
			vis[i]=vis[j]=1;
			a[k]=i,b[k]=j;
			dfs(k+1,nn,mm);
			a[k]=0,b[k]=0;
			vis[i]=vis[j]=0;
		}
	}
}
int sol(int nn,int mm){
	ans=0;
//	for(int i=1;i<=nn;i++){
//		cout<<s[i]<<" ";
//	}
	dfs(1,nn,mm);
	return ans;
}
signed main(){
	freopen("umi.in","r",stdin);
	freopen("umi.out","w",stdout);
	int id;
	scanf("%lld%lld%lld",&n,&m,&id);
	for(int i=1;i<=n;i++){
		scanf("%lld",&val[i]);
	}
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%lld%lld",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	dfs_t(1,0);
	int q;
	scanf("%lld",&q);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		tot1=0;tot2=0;
		if(deep[x]<deep[y])swap(x,y);
		while(deep[x]!=deep[y]){
			s1[++tot1]=val[x];
//			cout<<"@"<<x<<"@";
			x=father[x];
		}
		while(x!=y){
			s1[++tot1]=val[x];
			s2[++tot2]=val[y];
//			cout<<"&"<<x<<" "<<y<<"&";
			x=father[x];y=father[y];
		}
//		cout<<endl;
		s1[++tot1]=val[x];
		for(int i=1;i<=tot1;i++){
			s[i]=s1[i];
		}
		for(int i=1;i<=tot2;i++){
			s[i+tot1]=s2[tot2-i+1];
		}
		printf("%lld\n",sol(tot1+tot2,m));
	} 
	return 0;
}

