/*
t1
注意到限制其实挺严格
 
*/
#include<bits/stdc++.h>
using namespace std;
void wr(int x){
	if(x>10)wr(x/10);
	putchar(x%10|48);
}
const int N=2010;
int p,out[N][N],s,ans[N],vis[N][N];
set<int>st[N];
int k,n,i,j;
void dfs(int now){
	if(now==p){
//		puts("++ans");
		++s;
		for(int i=1;i<=p;++i)out[s][i]=ans[i];
		for(int i=1;i<=p;++i)for(int j=i+1;j<=p;++j)++vis[ans[i]][ans[j]];
		return;
	}
	for(int i=ans[now]+1;i<n;++i){
		bool f=1;
		for(int j=1;j<=now;++j)if(vis[ans[j]][i])f=0;
		if(!f)continue;
		++vis[ans[now]][i];
		ans[now+1]=i;
		dfs(now+1);
		--vis[ans[now]][i];
		return;
	}
}
void work(){
	for(i=0;i<n;++i)for(j=i+1;j<n;++j)++s;
	printf("%d\n",s);
	for(i=0;i<n;++i)for(j=i+1;j<n;++j)printf("%d %d\n",i,j);
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&p,&k);
	n=pow(p,k);
	if(p==2)return work(),0;
//	for(i=0;i<n;++i)for(j=0;j<n;++j)if(i!=j)st[i].insert(j);
	for(i=0;i<5;++i){
		for(j=i+1;j<n;++j){
//			printf("i=%d j=%d\n",i,j);
//			for(int i=0;i<n;++i)for(int j=i+1;j<n;++j)printf("vis[%d][%d]=%d\n",i,j,vis[i][j]);
			if(i==j||vis[i][j])continue;
//			printf("ans[1]=%d ans[2]=%d\n",i,j);
			++vis[i][j];
			ans[1]=i,ans[2]=j;
			dfs(2);
			--vis[i][j];
		}
	}
	printf("%d\n",s);
	for(i=1;i<=s;++i){
		for(j=1;j<=p;++j)printf("%d ",out[i][j]);
		putchar(10);
	} 
	return 0;
}

