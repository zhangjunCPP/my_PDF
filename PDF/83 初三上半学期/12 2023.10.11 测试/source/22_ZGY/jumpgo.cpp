/*
T3 jumpgo
Solve1是一个暴力程序，我想可以拿来找规律
但是可惜没能敲出来，乐
那么Solve4反而是能搞的，这东西比你想象的好整得多
我们只需要处理出三个段的长度 $a,b,c$，然后就可以爆算了
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
int n;
char s[510];
//namespace Solve1
//{
//	int _[11],_c[11];
//	int tot=0,ans=0;
//	inline void work()
//	{
//		for(int i=1;i<=tot;i++)s[_[i]]=_c[i];
//		
//		return;
//	}
//	void DFS(int i)
//	{
//		if(i>tot){work();return;}
//		_c[i]=true;
//		DFS(i+1)
//		_c[i]=false;
//		DFS(i+1);
//	}
//	inline void solve()
//	{
//		for(int i=0;i<n;i++)if(s[i]=='?')_[++tot]=i;
//		DFS(1);
//	}
//}
namespace Solve4
{
	ll s[510][510];
	ll fac[1010],inv[1010];
	inline ll qpow(ll a,ll b)
	{
		ll ret=1;
		while(b)
		{
			if(b&1)ret=ret*a%mod;
			a=a*a%mod;b>>=1;
		}
		return ret;
	}
	inline void INIT()
	{
		fac[0]=1;
		for(int i=1;i<=1000;i++)fac[i]=fac[i-1]*i%mod;
		inv[1000]=qpow(fac[1000],mod-2);
		for(int i=999;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
		return;
	}
	inline ll C(ll n,ll m){return fac[n]*inv[m]%mod*inv[n-m]%mod;}
	inline void solve()
	{
		int a=0,b=0,c=0;
		while(s[a]=='0')a++;
		while(s[a+b]=='1'&&a+b<n)b++;
		c=n-a-b;
		//突然不想打了，觉得这场很难受
		//自己的状态又双叒叕出了问题，真是不知道之后怎么调整了
		
		//还有25min的话，写一写？
		b>>=1;
		ll ans=0;
		for(int i=0;i<=b;i++)
		{
			ll tmp=0;
			for(int j=0;)
		}
		//又错了，这个也不会，写了白写 
		return;
	}
} 
int main()
{
	freopen("jumpgo.in","r",stdin);
	freopen("jumpgo.out","w",stdout);
	scanf("%d",&n);scanf("%s",s);
//	if(n<=20)Solve1::solve();
//	Solve4::solve();
	return 0;
}
