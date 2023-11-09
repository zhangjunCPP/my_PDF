#include<bits/stdc++.h>
using namespace std;
namespace IO_ER{
	#define LL long long
	#define db double
	#define ULL unsigned long long
	#define In inline
	#define Re register
	#define f(a,b,i) for(int i=a;i<=b;i++)
	#define ff(a,b,i) for(Re int i=a;i<b;i++)
	#define f_(a,b,i) for(Re int i=a;i>=b;i--)
	#define ff_(a,b,i) for(Re int i=a;i>b;i--)
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

#define N 200050

int n;

LL a[N];

int m;
LL b[N];
unordered_map<LL,int>mp;

template<typename T>In void cmax(T &x,T y){x<y?x=y:1;}
template<typename T>In void cmin(T &x,T y){x>y?x=y:1;}

namespace sub1{

	int Main(){
		LL dp[n+5][m+5]={0};
		memset(dp,0x3f,sizeof dp);
		dp[0][0]=-infll;
		LL mx,mn;
		f(1,n,i){
			f(0,m,j){
				if(dp[i-1][j]!=infll){
					mx=b[j];
					mn=b[j]-dp[i-1][j];
					cmax(mx,a[i]);
					cmin(mn,a[i]);
					cmin(dp[i][mp[mx]],mx-mn);	
				}
				if(i>=2&&dp[i-2][j]!=infll){
					mx=b[j];
					mn=b[j]-dp[i-2][j];
					cmax(mx,a[i-1]+a[i]);
					cmin(mn,a[i-1]+a[i]);
					cmin(dp[i][mp[mx]],mx-mn);	
				}
			}
		}	
		LL ans=INFll;
		f(0,m,j)ans=min(ans,dp[n][j]);
		printf("%lld",ans);
		return 0;
	}
}

int main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	read(n);
	f(1,n,i){
		read(a[i]);
		b[++m]=a[i];	
	}
	ff(1,n,i)b[++m]=a[i]+a[i+1];	
	sort(b+1,b+1+m);
	m=unique(b+1,b+1+m)-b-1;
	f(0,m,i)mp[b[i]]=i;
	sub1::Main();
	return 0;
}

