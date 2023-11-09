#include<bits/stdc++.h>
using namespace std;
namespace IO_ER{
	#define LL long long
	#define db double
	#define ULL unsigned long long
	#define In inline
	#define Re register
	#define f(a,b,i) for(int i=a;i<=b;i++)
	#define ff(a,b,i) for(int i=a;i<b;i++)
	#define f_(a,b,i) for(int i=a;i>=b;i--)
	#define ff_(a,b,i) for(int i=a;i>b;i--)
	typedef pair<int,int> Pi;
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
			x=(x<<3)+(x<<1)+(ch^48);
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

#define N 100050
#define mod 1000000007
#define inv2 500000004

int n,m,k;

struct edge{
	int u,v;
	LL d,s;
}e[N];

int tot;

map<Pi,int>mp;

int main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	int T;
	read(T);
	while(T--){
		read(n,m,k);
		int u,v,d,s;
		mp.clear();
		tot=0;
		f(1,m,i){
			read(u,v,d,s);
			if(u>v)swap(u,v);
			if(mp[Pi(u,v)]){
				int it=mp[Pi(u,v)];
				(e[it].d*=d)%=mod;
				(e[it].s*=s)%=mod;
			}
			else{
				mp[Pi(u,v)]=++tot;
				e[tot]=edge{u,v,d,s};
			}
		}
		if(n==2){
			LL ans=e[1].s*k%mod+e[1].d*k%mod*(k-1)%mod;
			printf("%lld\n",ans);
			continue;
		}
		LL ans=1;
		f(1,n,i)ans=ans*(k-i+1)%mod;
		printf("%lld\n",ans);
		
	}
	return 0;
}

