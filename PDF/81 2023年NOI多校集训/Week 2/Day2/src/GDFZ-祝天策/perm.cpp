#include<bits/stdc++.h>
#define ll long long
#define mem(u,v) memset(u,v,sizeof(u))
#define rep(i,a,b) for(ll i=(a),KK##i=(b);i<=KK##i;i++)
#define drep(i,a,b) for(ll i=(a),KK##i=(b);i>=KK##i;i--)
#define go(u) for(ll i=head[u],v=e[i].to;i;i=e[i].nxt,v=e[i].to)
#define writesp(x) write(x),putchar(' ')
#define writeln(x) write(x),puts("")
#define Il inline
using namespace std;
Il ll read(){ll sum=0,f=0;char ch=getchar();while(!isdigit(ch))f|=(ch=='-'),ch=getchar();while(isdigit(ch))sum=(sum<<1)+(sum<<3)+(ch^48),ch=getchar();return f?-sum:sum;}
void write(const ll x){if(x<0){putchar('-');write(-x);return;}if(x>9)write(x/10);putchar(x%10+'0');}
#define N 11000000
ll mod,n,ans,inv2,f[N],mul[N];
ll mi(ll a,ll k){ll sum=1;for(;k;k>>=1,a=a*a%mod)if(k&1)sum=sum*a%mod;return sum;}
int main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	n=read();mod=read();inv2=mi(2,mod-2);
	f[1]=1,f[2]=2;mul[0]=mul[1]=1,mul[2]=2;
	rep(i,3,n)mul[i]=mul[i-1]*i%mod,f[i]=(f[i-2]*(i-1)+f[i-1])%mod;
//	rep(i,1,n)cout<<mul[i]<<" "<<f[i]<<endl;
	rep(i,1,n)ans^=(mul[i]-f[i]+mod)%mod*inv2%mod;//,cout<<(mul[i]-f[i]+mod)%mod*inv2<<' ';puts("");
	writeln(ans);
}
/*
4 998244353

*/
