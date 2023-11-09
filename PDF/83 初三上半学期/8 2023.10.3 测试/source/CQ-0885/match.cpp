#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m;
vector<int>b[N];
int a[3][N],mx[N];
int ans[N],vis[N],fl=0;
void dfs(int k){
	if(k>n){
		fl=1;
		for(int i=m;i;i--){
			int x=a[1][i]|a[2][i];
			if(ans[i]!=x){
				if(ans[i]==1){
					for(int j=1;j<=m;j++){
						ans[j]=a[2][j]|a[1][j];
					}
					return;
				}
			}
		}
		return;
	}
	if(!vis[mx[k]+1]&&mx[k]<m){
		a[k][mx[k]+1]=1;
		vis[mx[k]+1]=1;
		dfs(k+1);
		a[k][mx[k]+1]=0;
		vis[mx[k]+1]=0;
	}
	for(int i:b[k]){
		if(vis[i])return;
	}
	for(int i:b[k]){
		a[k][i]=1;
		vis[i]=1;
	}
	dfs(k+1);
	for(int i:b[k]){
		a[k][i]=0;
		vis[i]=0;
	}
}
void sol1(){
	if(n==2){
		for(int i=1;i<=m;i++)ans[i]=1;
		dfs(1);
		if(!fl){
			cout<<-1;
			return;
		}
		for(int i=m;i;i--){
			cout<<ans[i];
		}
	}
	else{
		for(int i:b[1]){
			ans[i]=1;
		}
		for(int i=m;i;i--){
			cout<<ans[i];
		}
	}
} 
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		for(int j=1;j<=x;j++){
			int y;scanf("%d",&y);
			b[i].push_back(y);
			mx[i]=max(mx[i],y);
		} 
	}
	if(n<=2)sol1();
	else{
		cout<<-1;
	}
	return 0;
}

