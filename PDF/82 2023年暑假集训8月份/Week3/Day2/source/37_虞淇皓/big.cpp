#include<bits/stdc++.h>
using namespace std;
int n,m,q;
struct as{
	int x,y;
}e[10000];
int d[5000],vis[5000],dis[10000];
int ans=0;
bool ch(){
	memset(d,0,sizeof(d));
	for(int i=1;i<=m;i++){
		if(dis[i]){
			d[e[i].x]++;d[e[i].y]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(d[i]<2)return false;
	}
	return true;
}
void dfs(int k){
	if(k>m){
		if(ch()){
			ans++;
		}
		return;
	}
	if(!vis[e[k].x]||!vis[e[k].y]||dis[k]){
		dfs(k+1);return;
	}
	dfs(k+1);
	dis[k]=1;
	dfs(k+1);
	dis[k]=0;
}
int main(){
	freopen("big.in","r",stdin);
	freopen("big.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&e[i].x,&e[i].y);
	}
	scanf("%d",&q);
	string str;cin>>str;
	for(int i=0;i<n;i++){
		if(str[i]=='1'){
			vis[i+1]=1;
		}
	}
	for(int i=1;i<=m;i++){
		if(vis[e[i].x]&&vis[e[i].y]){
			d[e[i].x]++;d[e[i].y]++;
		}
	}
	for(int i=1;i<=m;i++){
		if(vis[e[i].x]&&vis[e[i].y]){
			if(d[e[i].x]<2||d[e[i].y]<2){
				cout<<0;
				return 0;
			}
			if(d[e[i].x]==2||d[e[i].y]==2){
				dis[i]=1;
			}
		}
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}


