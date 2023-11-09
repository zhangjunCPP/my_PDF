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

#define N 3005

int n,k,q;
int m;

char s[N];
char p[N];

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	read(k);
	scanf("%s",s+1);
	n=strlen(s+1);
	read(q);
	f(1,q,tim){
		scanf("%s",p+1);
		m=strlen(p+1);
		int ans=0;
		f(1,n-m+1,i){
			int mi=m+1,mx=0;
			f(1,m,j){
				if(s[i+j-1]!=p[j]){
					mi=j;
					break;
				}
			}
			if(m-mi<k){
				ans++;
				continue;
			}
			f_(m,1,j){
				if(s[i+j-1]!=p[j]){
					mx=j;
					break;
				}
			}
			if(mx-mi<k)ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}

