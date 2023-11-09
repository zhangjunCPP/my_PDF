#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
const int N=1e6+5;
int n;
struct edge{
	int u,v;
}E[N];
int vis[N];
using ull=unsigned long long;
const ull mod=998244353;
unordered_map<ull,bool>mp;ull p=19491001;
int cnt;
void dfs(int x,ull key){
	if(x==n){
		if(!mp.count(key))mp[key]=1,cnt++;
		return;
	}
	if(vis[E[x].u]||vis[E[x].v]){
		dfs(x+1,key);
		return;
	}
	vis[E[x].u]=1;
	dfs(x+1,key*p+E[x].u);
	swap(vis[E[x].u],vis[E[x].v]);
	dfs(x+1,key*p+E[x].v);
	vis[E[x].v]=0;
}
int f[N];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int fl=1,fl2=1;
	n=rd();for(int i=1;i<n;i++){
		int u=rd(),v=rd();
		E[i]={u,v};
		fl&=(u==1&&v==i+1);
		fl2=(u==i&&v==i+1);
	}
	if(fl){
		printf("%d",n);
		return 0; 
	}if(fl2){
		f[1]=1,f[2]=2;
		for(int i=3;i<=n;i++)f[i]=(f[i-1]+f[i-2])%mod;
		cout<<f[n];
		return 0;
	}
	dfs(1,0);
	cout<<cnt;
	return 0;
}
/*
4    5    6
5    8
6
1 2
2 3
3 4
4 5
5 6
*/
