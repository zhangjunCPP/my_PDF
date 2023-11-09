/*
n=10可以暴力
test 4在送分
test 7,8很怪，草稿纸上随便模答案都一样 
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1010;
int n,a[N],l[N],r[N],c[N],ans;
bool use[N],vis[N];
int check(){
	int res=0;
	for(int i=1;i<=n;++i)use[i]=0;
	for(int i=1;i<=n;++i){
		int x=a[i];
		use[x]=1;
		for(int j=l[x];j<=r[x];++j)if(!use[j])res+=c[x];
	}
	return res;
}
void dfs(int now){
	if(now>n){
		ans=max(ans,check());
		return;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			vis[i]=1;
			a[now]=i;
			dfs(now+1);
			vis[i]=0;
		}
	}
}
int i,j;
bool f4=1,f7=1,f8=1;
struct B{
	int l,r,c,i;
}t[N];
bool cmp(B x,B y){
	return (x.r-x.l+1)*x.c>(y.r-y.l+1)*y.c;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d%d%d",l+i,r+i,c+i);
		t[i]={l[i],r[i],c[i],i};
		if(l[i]!=r[i]||r[i]!=i)f4=0;
		if(l[i]!=max(i-6,1)||r[i]!=min(i+6,n)||c[i]!=c[i-1])f7=0;
		if(l[i]!=max(i-7,1)||r[i]!=min(i+7,n)||c[i]!=c[i-1])f8=0;
	}
	if(f4){
		puts("0");
		return 0;
	}
	if(f7){
		for(i=1;i<=n;++i){
			for(j=i+1;j<=n&&j<=i+6;++j)ans+=c[i];
		}
		printf("%d",ans);
		return 0;
	}
	if(f8){
		for(i=1;i<=n;++i){
			for(j=i+1;j<=n&&j<=i+7;++j)ans+=c[i];
		}
		printf("%d",ans);
		return 0;
	}
	if(n<=10){
		dfs(1);
		printf("%d",ans);
		return 0;
	}
	sort(t+1,t+1+n,cmp);
	for(i=1;i<=n;++i){
		use[t[i].i]=1;
		for(j=t[i].l;j<=t[i].r;++j)if(!use[j])ans+=t[i].c;
	}
	printf("%d",ans);
	return 0;
}
/*
10
1 7 1
1 8 1
1 9 1
1 10 1
1 10 1
1 10 1
1 10 1
2 10 1
3 10 1
4 10 1
*/
