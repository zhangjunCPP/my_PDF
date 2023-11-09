#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10,mod=998244353;
int n,a[N],b[N],ans;
int vis[N];
int st[N],tot;
void dfs(int k){
	if(k>=n){
		ans++;
		if(ans>=mod)ans-=mod;
		// for(int i=1;i<=tot;i++){
		// 	cout<<st[i]<<" ";
		// }cout<<endl;
		return;
	}
	if(vis[a[k]]||vis[b[k]]){
		dfs(k+1);
		return;
	}
	// st[++tot]=a[k];
	vis[a[k]]=1;dfs(k+1);vis[a[k]]=0;
	// tot--;
	// st[++tot]=b[k];
	vis[b[k]]=1;dfs(k+1);vis[b[k]]=0;
	// tot--;
}
void sol1(){
	dfs(1);
	printf("%lld",ans);
}
int fib[N];
void sol2(){
	fib[2]=2;fib[3]=3;
	for(int i=4;i<=n;i++){
		fib[i]=fib[i-1]+fib[i-2];
		fib[i]%=mod;
	}
	printf("%lld",fib[n]);
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld",&n);
	int fl1=1,fl2=1;
	for(int i=1;i<n;i++){
		scanf("%lld%lld",&a[i],&b[i]);
		if(a[i]!=1||b[i]!=i+1)fl1=0;
		if(a[i]!=i||b[i]!=i+1)fl2=0;
		// cout<<a[i]<<" "<<b[i]<<endl;
		// int x=a[i]+b[i];
	}
	// return 0;
	if(fl1){printf("%lld",n);return 0;}
	if(fl2){sol2();return 0;}
	sol1();return 0;
	return 0;
}
/*
g++ tree.cpp -o tree -std=c++14 -O2 -Wall
./tree
*/