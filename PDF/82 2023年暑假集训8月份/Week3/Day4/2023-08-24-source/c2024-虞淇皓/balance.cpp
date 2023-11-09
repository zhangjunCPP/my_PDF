#include<bits/stdc++.h>
using namespace std;
const int N=300010;
int n,d[N];
vector<int>E[300010];
int dp[N],siz[N]; 
int father[N];
void dfs_siz(int u,int fa){
	siz[u]=1;father[u]=fa;
	for(int v:E[u]){
		if(v==fa)continue;
		dfs_siz(v,u);
		siz[u]+=siz[v];
	}
}
int root=0;
void dfs_zx(int u,int fa,int z){
	dp[u]=0;
	for(int v:E[u]){
		if(v==fa)continue;
		dfs_zx(v,u,z);
		dp[u]=max(dp[u],siz[v]);
	}
	dp[u]=max(dp[u],z-siz[u]);
	if(!root||dp[u]<dp[root])root=u;
}
void sol1(){//n<=5000±©Á¦n^2
	 for(int i=1;i<=n;i++){
	 	for(int j=1;j<=n;j++)dp[j]=siz[j]=0;
	 	dfs_siz(i,0);
	 	root=0;
	 	int mx=-1,ms=0;
	 	for(int j:E[i]){
	 		if(siz[j]>mx){
	 			mx=siz[j];ms=j;
			}
	 	}
	 	dfs_zx(ms,i,siz[ms]);
	 	printf("%d\n",root);
	 }
}
void sol2(){//¾Õ»¨
	for(int i=1;i<=n;i++){
		if(i==1)printf("%d\n",n);
		else printf("1\n");
	} 
}
void sol3(){//Á´
	for(int i=1;i<=n;i++){
		int l=i-1,r=n-i;
		if(l>r){
			printf("%d\n",i/2);
		}
		else{
			printf("%d\n",i+(n-i+1)/2); 
		}
	}
}
int siz4[N];
int ans4[N];
void dfs_zx4(int u,int fa,int z){
	dp[u]=0;siz4[u]=1;
	for(int v:E[u]){
		if(v==fa)continue;
		dfs_zx4(v,u,z);
		siz4[u]+=siz4[v];
		dp[u]=max(dp[u],siz4[v]);
	}
	dp[u]=max(dp[u],z-siz4[u]);
	if(!root||dp[u]<dp[root]||(dp[u]==dp[root]&&!ans4[u]))root=u;
//	cout<<u<<" "<<fa<<" "<<z<<"  "<<dp[u]<<endl;
}
void sol4(){
	 dfs_siz(1,0);
	 for(int i=1;i<=n;i++){
	 	if(ans4[i]){
	 		printf("%d\n",ans4[i]);
	 		continue;
	 	}
//	 	for(int j=1;j<=n;j++)dp[j]=siz[j]=0;
	 	root=0;
	 	int mx=-1,ms=0;
	 	for(int j:E[i]){
	 		if(siz[j]>mx&&j!=father[i]){
	 			mx=siz[j];ms=j;
			}
	 	}
	 	if(n-siz[i]>mx){
	 		ms=father[i];
	 		dfs_zx4(ms,i,n-siz[i]);
	 	}
	 	else dfs_zx4(ms,i,siz[ms]);
//	 	cout<<i<<" "<<ms<<endl;
	 	ans4[root]=i;
	 	printf("%d\n",root);
	 }
}

int main(){
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout); 
	scanf("%d",&n);int fl=1;
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x); 
		d[x++];d[y++];
		if(abs(x-y)!=1)fl=0;
	}
	if(n<=5000)sol1();
	else if(d[1]==n-1)sol2();
	else if(fl)sol3();
	else sol4();
	return 0;
}

