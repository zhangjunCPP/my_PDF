#include<bits/stdc++.h>
#define N 1005
#define int long long
using namespace std;
int n,l[N],r[N],c[N],fg=1,sum,p[N],vis[N],ans,d[N],tree[N];
int lowbit(int x){
	return x&(-x);
}
void add(int x,int cg){
	for(;x<=n;x+=lowbit(x))tree[x]+=cg;
}
int ask(int x){
	int res=0;
	for(;x;x-=lowbit(x))res+=tree[x];
	return res;
}
void update(int l,int r,int cg){
	add(l,cg);
	add(r+1,-cg);
}
void dfs(int x){
	if(x==n+1){
		int res=0;
		for(int i=0;i<=n;i++)tree[i]=0;
		for(int i=1;i<=n;i++){
			res+=ask(p[i]);
			update(l[p[i]],r[p[i]],c[p[i]]);
		}
		ans=max(ans,res);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&l[i],&r[i],&c[i]);
		sum+=c[i];
		if(l[i]!=r[i])fg=0;
	}
	if(fg){
		printf("%lld",sum);
		return 0;
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
/*
5
1 2 1
2 2 3
2 4 7
3 5 4
3 5 5
*/
