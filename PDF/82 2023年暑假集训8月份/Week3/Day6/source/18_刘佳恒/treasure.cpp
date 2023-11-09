#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=30;
int n,val[N];
int vis[N],ans=1e15;
int an[N];
void dfs(int now,int a,int b,int c) {
	if(now>n) {
		int sum=max({a,b,c})-min({a,b,c});
		if( ans>sum ) {
			ans=sum;
			for(int i=1;i<=n;i++) an[i]=vis[i];
		}
		return ;
	}
	vis[now]=1; dfs(now+1,a+val[now],b,c);
	vis[now]=2; dfs(now+1,a,b+val[now],c);
	vis[now]=3; dfs(now+1,a,b,c+val[now]);
}
bool FBI=false;
void fds(int now,int a,int b,int c,int mid) {
//	cout<<now<<" "<<a<<" "<<b<<" "<<c<<endl;
	if( a>mid || b>mid || c>mid ) return ;
	if(now>n) {
		for(int i=1;i<=n;i++) an[i]=vis[i];
		FBI=true; return ;
	}
	if(FBI) return ;
	if( a+val[now]<=mid ) vis[now]=1, fds(now+1,a+val[now],b,c,mid);
	if( b+val[now]<=mid ) vis[now]=2, fds(now+1,a,b+val[now],c,mid);
	if( c+val[now]<=mid ) vis[now]=3, fds(now+1,a,b,c+val[now],mid);
}
signed main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&val[i]);
	if( n<=15 ) {
		dfs(1,0,0,0);
		for(int i=1;i<=n;i++) printf("%lld ",an[i]);
		return 0;
	}
	int sum=0;
	for(int i=1;i<=n;i++) sum+=val[i];
	sort( val+1,val+1+n,[](int x,int y){ return x>y; } );
	int mid=sum/3ll;
	fds(1,0,0,0,mid);
	for(int i=1;i<=n;i++) printf("%lld ",an[i]);
	return 0;
}
/*
20
1 1 1 3 1 1 1 1 3 1 1 1 1 1 1 1 1 3 3 3

25
10 20 30 20 20 20 20 20 20 10 2 2 2 2 2 30 30 5 5 5 5 5 5 5 5

15
1 3 2 3 234 534 23 4 234 43 32 54 54 5 312
*/
