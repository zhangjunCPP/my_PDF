#include<bits/stdc++.h>
using namespace std;
int n,ans=0x7fffffff;
int num[3],out[30],now[30],w[30];
void dfs(int i){
	if(i==n+1){
		if(ans>max({num[0],num[1],num[2]})-min({num[0],num[1],num[2]})){
			for(int i=1;i<=n;i++)out[i]=now[i];
			ans=max({num[0],num[1],num[2]})-min({num[0],num[1],num[2]});
		}
		return;
	}
	now[i]=0;
	num[0]+=w[i];
	dfs(i+1);
	num[0]-=w[i];
	
	now[i]=1;
	num[1]+=w[i];
	dfs(i+1);
	num[1]-=w[i];
	
	now[i]=2;
	num[2]+=w[i];
	dfs(i+1);
	num[2]-=w[i];
}
void Freopen(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	dfs(1);
	for(int i=1;i<=n;i++)
		printf("%d ",out[i]+1);
	return 0;
}

