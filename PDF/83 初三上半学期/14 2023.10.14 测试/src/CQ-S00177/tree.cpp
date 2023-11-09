/*
T3 tree
正解太难了，直接打暴力
Sub1 搜
Sub4 n
Sub5 Fib_n
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=998244353,N=1000010;
int a[N],b[N];
namespace Sub1
{
	bool vis[N];
	ll ans=0;
	void DFS(int i,int n)
	{
		if(i==n){ans++;return;}
		if(vis[a[i]]||vis[b[i]]){DFS(i+1,n);return;}
		vis[a[i]]=true;
		DFS(i+1,n);
		vis[a[i]]=false;
		vis[b[i]]=true;
		DFS(i+1,n);
		vis[b[i]]=false;
		return;
	}
	inline void work(int n)
	{
		DFS(1,n);
		printf("%lld",ans);
		return;
	}
}
namespace Sub4{inline void work(int n){printf("%d",n);return;}}
namespace Sub5
{
	ll fib[N];
	inline void work(int n)
	{
		fib[0]=fib[1]=1;
		for(int i=2;i<=n;i++)fib[i]=(fib[i-1]+fib[i-2])%mod;
		printf("%lld",fib[n]);
		return;
	}
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	scanf("%d",&n);
	bool f4=true,f5=true;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",a+i,b+i);
		if(a[i]!=1)f4=false;
		if(a[i]!=b[i]-1)f5=false;
	}
	if(f4)Sub4::work(n);
	else if(f5)Sub5::work(n);
	else Sub1::work(n);
	return 0;
}