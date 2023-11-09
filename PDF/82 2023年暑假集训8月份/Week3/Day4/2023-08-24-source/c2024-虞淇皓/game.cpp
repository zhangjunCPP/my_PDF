#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,v[N];
void sol1(){
	printf("%d\n",n*(n-1)/2);
	for(int i=n;i;i--)printf("%d ",i);
}
void sol2(){
	printf("%d\n",n*(n-1));
	for(int i=2;i<=n;i++)printf("%d ",i);
	printf("1");
}
int ans,s[20],b[20],vis[20],st[20];
int ch(){
	int top=0,hs=0;
	for(int i=1;i<=n;i++){
		while(top&&st[top]>b[i])top--,hs+=v[b[i]];
		st[++top]=b[i];
	}
	return hs;
}
void dfs(int k){
	if(k>n){
		int x=ch();
		if(x>ans){
			ans=x;
			for(int i=1;i<=n;i++)s[i]=b[i];
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			b[k]=i;
			dfs(k+1);
			b[k]=0;
			vis[i]=0;
		}
	}
}
void sol3(){
	dfs(1);
	printf("%d\n",ans);
	for(int i=1;i<=n;i++){
		printf("%d ",s[i]);
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	int fl1=1,fl2=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&v[i]);
		if(v[i]!=i)fl1=0;
		if(v[i]!=n-i+1)fl2=0;
	}
	if(fl1)sol1();
	else if(fl2)sol2();
	else if(n<=9)sol3();
//	else sol4();
	return 0;
}


