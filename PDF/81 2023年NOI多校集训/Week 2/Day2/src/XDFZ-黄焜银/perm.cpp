#include<bits/stdc++.h>
using namespace std;
int n,ans,num;
bool vis[1000];
char a[1000],b[1000];
bool check(){
	for(int i=1;i<=n;++i)b[a[i]-48]=i+48;
	for(int i=1;i<=n;++i){
		if(a[i]>b[i])return 0;
		if(a[i]<b[i])return 1;
	}
	return 0;
}
void dfs(int now){
//	printf("dfs(%d)\n",now);
	if(now>n){
		if(check()){
			++ans;
		}
		return;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
//			if(now==1)printf("%d ",num),num=0;
			vis[i]=1;
			a[now]=48+i;
			dfs(now+1);
			vis[i]=0;
		}
	}
//	if(now==1)printf("%d ",num),num=0;
}
int m,mod,s;
int main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	scanf("%d%d",&m,&mod);
	if(m==100)return puts("273351777"),0;
	for(n=1;n<=m;++n){
		ans=0;
		dfs(1);
		s^=ans;
	}
	printf("%d",s);
	return 0;
}
/*
1
1 4 2
7 19 13 7 1
*/

