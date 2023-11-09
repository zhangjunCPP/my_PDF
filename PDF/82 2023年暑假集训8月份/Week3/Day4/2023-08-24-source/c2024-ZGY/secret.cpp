/*
D secret
吹波老匹（
暴力13分跑路 
*/
#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void r(T &&x)
{
	char c;x=0;
	while((c=getchar())<'0'||c>'9');
	while(c>='0'&&c<='9')x*=10,x+=c-'0',c=getchar();
	return;
}
template<typename T,typename ...Args>
inline void r(T &&x,Args &&...args){r(x);r(args...);return;}
vector<int>per;
#define ll long long
const int mod=65535;
inline void solve()
{
	per.clear();
	int k;
	r(k);
	for(int i=1;i<=k;i++)
	{
		int x,c;
		r(x,c);
		for(int j=1;j<=c;j++)per.push_back(x);
	}
	sort(per.begin(),per.end());
	ll ans=1;
	do
	{
		ll base=1,mul=0;
		for(int i=per.size()-1;i>=0;i--)(mul+=base*per[i]%mod)%=mod,(base*=256)%=mod;
		(ans*=mul)%=mod;
	}
	while(next_permutation(per.begin(),per.end()));//操！！！我为什么会写这个！！！ 
	printf("%lld\n",ans);
	return;
}
int main()
{
	freopen("secret.in","r",stdin);
	freopen("secret.out","w",stdout);
	int T;
	r(T);
	while(T--)solve();
	return 0;
}
