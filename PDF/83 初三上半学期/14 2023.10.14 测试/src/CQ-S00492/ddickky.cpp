#include<bits/stdc++.h>
using namespace std;
namespace IO_ER{
	#define LL long long
	#define db double
	#define In inline
	#define ULL unsigned long long
	#define Re register
	#define f(a,b,i) for(int i=a;i<=b;i++)
	#define ff(a,b,i) for(int i=a;i<b;i++)
	#define f_(a,b,i) for(int i=a;i>=b;i--)
	#define ff_(a,b,i) for(int i=a;i>b;i--)
	const int inf=0x3f3f3f3f;
	const int INF=0x7f7f7f7f;
	const LL infll=0x3f3f3f3f3f3f3f3fll;
	const LL INFll=0x7f7f7f7f7f7f7f7fll;
	template<typename T>void read(T &x){
		x=0;
		bool fl=0;
		char ch=getchar();
		while(ch<'0'||'9'<ch){
			if(ch=='-')fl=1;
			ch=getchar();
		}
		while('0'<=ch&&ch<='9'){
			x=x*10+(ch^48);
			ch=getchar();
		}
		x=fl?-x:x;
	}
	template<typename T,typename ...Args>void read(T &x,Args &...args){
		read(x);
		read(args...);
	}
}
using namespace IO_ER;

#define N 50
#define B 455
#define mod 998244353

In LL pow_(LL a,LL b,LL Mod){	
	LL ans=1;
	while(b){
		if(b&1)ans=ans*a%Mod;
		a=a*a%Mod;
		b>>=1;
	}
	return ans;
}

int n,q;

int a[N];

int ans[N][N];

In LL gcd(LL a,LL b){
	if(b==0)return a;
	return gcd(b,a%b);
}

int main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
//cout<<pow_(2,29)*9%mod<<endl;
	read(n,q);
	f(1,n,i)read(a[i]);
	f(1,n,l){
		f(l,n,r){
			int s=0;
			f(l,r,k)s|=(1<<k-1);
			LL res=1;
			for(int t=s;t;t=(t-1)&s){
				LL d=0;
				f(1,n,i){
					if(t&(1<<i-1)){
						d=gcd(d,a[i]);	
					}
				}
				res=res*d%mod;
			}
			ans[l][r]=res;
		}
	}
	int l,r;
	f(1,q,i){
		read(l,r);
		printf("%d\n",ans[l][r]);
	}
	return 0;
}

