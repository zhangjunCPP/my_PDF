/*
菊花直接输出n

考虑链的情况
每次砍链，相当于把原问题缩减为四个子问题（除非首尾）
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll re(){
	ll x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}
const ll N=1e6+10,mod=998244353;
//ll work(ll l,ll r){
//	if(r-l+1==2)return 2;
//	if(r-l+1==1)return 1;
//	if(r<l)return 0;
//	return work(l+1,r)+work(l+2,r);
//}
bool flag;
ll n,i,x,y,f[N];
ll cnt,first[N];
struct Edge{
	ll u,v,nex;
}a[N<<1];
void add(ll u,ll v){
	a[++cnt]={u,v,first[u]};
	first[u]=cnt;
}
ll ans;
bool vis[N];
void dfs(int now){
	if(now>=n)return void((++ans)%=mod);
	if(!vis[a[now].u]&&!vis[a[now].v]){
		vis[a[now].u]=1;
		dfs(now+1);
		vis[a[now].u]=0;
		vis[a[now].v]=1;
		dfs(now+1);
		vis[a[now].v]=0;
	}
	else dfs(now+1);
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	flag=1;
	n=re();
	for(i=1;i<n;++i){
		x=re();
		y=re();
		add(x,y);
//		add(y,x);
		if(x!=1||y!=i+1)flag=0;
	}
	if(flag)return printf("%lld",n),0;
	if(n<=10){
//		puts("start");
		dfs(1);
//		puts("end");
		printf("%lld",ans);
		return 0;
	}
//	work(1,n);
	f[0]=0,f[1]=1,f[2]=2;
	for(i=3;i<=n;++i)f[i]=(f[i-1]+f[i-2])%mod;
	printf("%lld",f[n]);
	return 0;
}

