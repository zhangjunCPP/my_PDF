//time limit 更改:5s,9,10为8s
//a0d0=a1d1<=>a0/a1=d1/d0
//发现这只和上下有关
//考虑计算a/b((a,b)=1,a>=b)的一些东西.没错数量就是phi(a)
//答案是2sum(2<=i<=n)floor(n/i)^2phi(i)-n^2?
//#include<bits/stdc++.h>
//using namespace std;
//int t,n,phi[21000010];
//int main(){
//	for(cin>>t;t--;){
//		cin>>n;
//		iota(phi+1,phi+n+1,1);
//		for(int i=2;i<=n;i++)
//		if(phi[i]==i)for(int j=i;j<=n;j+=i)
//		(phi[j]/=i)*=i-1;
//		long long ans=-n*1ll*n;
//		for(int i=1;i<=n;i++)
//		ans+=n/i*(n/i)*2ll*phi[i];
//		cout<<ans<<endl;
//	}
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int pren=23000000;
using lll=__int128;
void w(lll x){if(x>9)w(x/10);putchar(x%10+'0');}
ll n,lm[660000];
lll S[660000],phi[23000010];
int id1[330000],sqn,m,id2[330000];
auto id=[](ll x)->int&{return x<=sqn?id1[x]:id2[n/x];};
lll solve(){
	sqn=sqrt(n)+1;
	for(ll l=1,r;l<=n;l=r+1)
	r=n/(n/l),lm[id(n/l)=++m]=n/l;
	for(int i=m;i;i--)
	if(lm[i]<=pren)S[i]=phi[lm[i]];
	else{
		S[i]=(lll)lm[i]*(lm[i]+1)/2;
		for(ll l=2,r;l<=lm[i];l=r+1)
		r=lm[i]/(lm[i]/l),S[i]-=(r-l+1)*S[id(lm[i]/l)];
	}lll ans=0;
	for(ll l=1,r;l<=n;l=r+1)
	r=n/(n/l),ans+=(S[id(r)]-S[id(l-1)])*(n/l)*(n/l);
	m=0;return ans*2-(lll)n*n;
}
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	iota(phi+1,phi+pren+1,1);
	for(int i=2;i<=pren;i++)
	if(phi[i]==i)for(int j=i;j<=pren;j+=i)
	(phi[j]/=i)*=i-1;
	for(int i=1;i<=pren;i++)phi[i]+=phi[i-1];
	int t;for(cin>>t;t--;){scanf("%lld",&n);w(solve());puts("");}
	return 0;
}
