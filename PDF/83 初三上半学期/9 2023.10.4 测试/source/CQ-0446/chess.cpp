#include<bits/stdc++.h>
using namespace std;
namespace IO_ER{
	#define LL long long
	#define db double
	#define ULL unsigned long long
	#define In inline
	#define Re register
	#define f(a,b,i) for(int i=a;i<=b;i++)
	#define ff(a,b,i) for(int i=a;i<(int)b;i++)
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


In pow_(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}

set<int>e[N];

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(p,k);
	n=pow_(p,k);
	if(k==1){
		puts("1");
		ff(0,n,i)printf("%d ",i);
		puts("");
		return 0;
	}
	ff(0,n,i){
		ff(i+1,n,j){
			e[i].emplace(j);
			e[j].emplace(i);
		}	
	}
	if(p==2){
		printf("%d\n",n*(n-1)/2);
		ff(0,n,i){
			ff(i+1,n,j){
				printf("%d %d\n",i,j);
			}
		}
		return 0;
	}
//	f(1,)
	return 0;
}


