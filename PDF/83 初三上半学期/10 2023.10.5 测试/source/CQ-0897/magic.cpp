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

#define N 1050
#define V 16
#define M 33000

int n;

struct node{
	int l,r,c,id;
	node(){}
	node(int l,int r,int c):l(l),r(r),c(c){}
	In bool operator<(const node &b)const{
		if(l==b.l){
			if(r==b.r)return id<b.id;
			return r<b.r;	
		}
		return l<b.l;
	}
};

node e[N];

LL dp[2][M];

In void cmax(LL &x,LL y){x<y?x=y:1;}

int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	read(n);
	f(1,n,i)read(e[i].l,e[i].r,e[i].c),e[i].id=i;
	sort(e+1,e+1+n);
	int now=0,cur=1;
	int len,mx;
	int pmx=0,pl=0,pr=0;
	f(1,n,i){
		len=max(e[i].r,pr)-e[i].l+1;
		mx=(1<<len)-1;
		swap(now,cur);
		f(0,mx,s)dp[now][s]=0;
		int d=e[i].l-pl;
		f(0,pmx,s)cmax(dp[now][s>>d],dp[cur][s]);
		int pst=(1<<(max(pr-e[i].l+1,0)))-1;
		f(0,mx,s)cmax(dp[now][s],dp[now][s&pst]);
		int it=e[i].id-e[i].l;
//		int pre=;
		f(0,mx,s){
			if(!((s>>it)&1))continue;
			dp[now][s]+=e[i].c*(len-__builtin_popcount(s>>it));
		}
		pmx=mx;
		pl=e[i].l;
		pr=max(pr,e[i].r);
//		printf("%d %d %d\n",e[i].l,e[i].id,e[i].r);
//		f(0,mx,s){
//			ff(0,len,i)printf(s>>i&1?"1":"0");
//			printf("  %lld\n",dp[now][s]);	
//		}
	}
	LL ans=0;
	f(0,pmx,s)cmax(ans,dp[now][s]);
	printf("%lld",ans);
	return 0;
}
/*
5
1 2 1
2 2 3
2 4 7
3 5 4
3 5 5

*/
/*
12
1 3 861
2 4 822
1 3 286
2 4 236
5 6 335
4 9 837
3 11 469
7 12 846
9 12 258
6 12 139
7 12 932
12 12 411

*/
