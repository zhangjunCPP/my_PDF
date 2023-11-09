#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

const int MAXN=1e7+5;
int n,cnt,lim,mod,a[MAXN],b[MAXN];
bool vis[MAXN];
inline bool check(){
	for(int i=1;i<=lim;i++)b[a[i]]=i;
	for(int i=1;i<=lim;i++)
		if(b[i]^a[i])return b[i]>a[i];
	return false; 
}
void dfs(int dep){
	if(dep>lim){if(check())cnt++;return;}
	for(int i=1;i<=lim;i++)if(!vis[i]){
		vis[i]=true;a[dep]=i;dfs(dep+1);vis[i]=false;
	}
}
int main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	scanf("%d%d",&n,&mod);
	int res=0;
	for(int i=1;i<=n;i++){
		cnt=0;lim=i;dfs(1);
		res^=cnt;
	}
	printf("%d\n",res%mod);
	return 0;
} 
