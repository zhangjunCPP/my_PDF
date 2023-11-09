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

#define N 2050

int n;

int p,k;

int a[N];

int b[N];

In void fj(int *A,int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			while(x%i==0){
				A[i]++;
				x/=i;
			}
		}
	}
	if(x>1)A[x]++;
}

int main(){
//	freopen("chess.in","r",stdin);
//	freopen("chess.out","w",stdout);
	read(p,k);
	int pwp=1;
	f(1,k,i)pwp*=p;
	LL ans=pwp*(pwp-1)/2;
	printf(ans%p==0?"YES":"NO");
	return 0;
}
