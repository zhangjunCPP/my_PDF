#include<bits/stdc++.h>
using namespace std;
namespace IO_ER{
	#define LL long long
	#define db double
	#define In inline
	#define ULL unsigned LL
	#define Re register
	#define f(a,b,i) for(Re int i=a;i<=b;i++)
	#define ff(a,b,i) for(Re int i=a;i<b;i++)
	#define f_(a,b,i) for(Re int i=a;i>=b;i--)
	#define ff_(a,b,i) for(Re int i=a;i>b;i--)
	const int inf=0x3f3f3f3f;
	const int INF=0x7f7f7f7f;
	const LL infll=0x3f3f3f3f3f3f3f3fll;
	const LL INFll=0x7f7f7f7f7f7f7f7fll;
	template<typename T>void read(T &x){
		static bool fl;
		static char ch;
		x=0;
		fl=0;
		ch=getchar();
		while(ch<'0'||ch>'9'){
			if(ch=='-')fl=1;
			ch=getchar();
		}
		while('0'<=ch&&ch<='9'){
			x=x*10+(ch^48);
			ch=getchar();
		}
		if(ch=='.'){
			ch=getchar();
			static db d;
			d=1.0;
			while('0'<=ch&&ch<='9'){
				x+=d*(ch^48);
				d*=0.1;
				ch=getchar();
			}
		}
		x=fl?-x:x;
	}
	template<typename T,typename ...Args>void read(T &x,Args &...args){
		read(x);
		read(args...);
	}
}
using namespace IO_ER;

In void write(__int128_t x){
	static short p[30];
	int tot=0;
	do{
		p[++tot]=x%10;
		x/=10;
	}while(x);
	f_(tot,1,i)putchar(p[i]+'0');
	putchar('\n');
}

#define N 20400050

LL n;

int pri[N];

int vis[N];

int tit;

int cnt[N];
LL sig[N];

__int128_t sum[N];

In void pre(){
	sig[1]=1;
	int x;
	f(2,N-5,i){
		if(!vis[i]){
			pri[++tit]=i;
			sig[i]=2;
			cnt[i]=2;
		}
		f(1,tit,j){
			x=i*pri[j];
			if(x>N-5)break;
			vis[x]=1;
			if(i%pri[j]==0){
				sig[x]=sig[i]/cnt[i]*(cnt[i]+1);
				cnt[x]=cnt[i]+1;
				break;
			}
			sig[x]=sig[i]*2;
			cnt[x]=2;
		}
	}
//	f(2,30,i)printf("%d %lld\n",i,sig[i]);
	f(1,N-5,i)sum[i]=sum[i-1]+(__int128_t)sig[i]*sig[i];
//	f(1,20,i)write(sum[i]);
}

int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	pre();
	int Ti;
	read(Ti);
	while(Ti--){
		read(n);
		if(n==1){
			puts("1");
			continue;
		}
		__int128_t mx=n*n;
		__int128_t ans=0;
		for(__int128_t l=n+1,r;l<=mx;l=r+1){
			r=mx/(mx/l);
			ans+=(mx/l)*(r-l+1)*(r-l+1);
		}
//		write(ans);
		write(sum[n*n]-2*ans);
	}
	return 0;
}

