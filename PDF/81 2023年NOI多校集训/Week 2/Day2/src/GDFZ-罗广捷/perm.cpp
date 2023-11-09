#include<bits/stdc++.h>
using namespace std;
namespace my_std
{
	typedef long long ll;
	const ll inf=0x3f3f3f3f;
	#define fir first
	#define sec second
	#define MP make_pair
	#define fr(i,x,y) for(ll i=(x);i<=(y);++i)
	#define pfr(i,x,y) for(ll i=(x);i>=(y);--i)
	#define space putchar(' ')
	#define enter putchar('\n')
	inline ll read()
	{
		ll sum=0,f=1;char ch=0;
		while(!isdigit(ch)){if(ch=='-'){f=-1;}ch=getchar();}
		while(isdigit(ch)) sum=sum*10+(ch^48),ch=getchar();
		return sum*f;
	}
	inline void write(ll x)
	{
		if(x<0) putchar('-'),x=-x;
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
	inline void writesp(ll x){write(x),space;}
	inline void writeln(ll x){write(x),enter;}
}
using namespace my_std;
const ll N=1e7+50;
ll n,mod,f[N],mul=1,inv2,ans=0;
int main(void)
{
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	n=read(),mod=read(),inv2=(mod+1)/2,f[0]=f[1]=1;
	fr(i,2,n) mul=mul*i%mod,f[i]=(f[i-1]+(i-1)*f[i-2]%mod)%mod,ans^=((mul-f[i]+mod)%mod*inv2%mod);
	return writeln(ans),0;
}
