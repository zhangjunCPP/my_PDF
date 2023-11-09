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

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	f(2,30,x){
		int t=x;
		LL ans=1;
		for(int i=2;i*i<=t;i++){
			if(t%i==0){
				int cnt=1;
				while(t%i==0){
					cnt++;
					t/=i;
				}
				ans*=cnt;
			}
		}
		if(t>1)ans*=2;
		printf("%d %lld\n",x,ans);
	} 
	return 0;
}

