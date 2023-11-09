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

#define N 30050

int n,q;

char sh[N][N];

int len[N];

char ch[N];

int main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	read(n);
	f(1,n,i)scanf("%s",sh[i]+1),len[i]=strlen(sh[i]+1);
	read(q);
	f(1,q,ti){
		scanf("%s",ch+1);
		int m=strlen(ch+1);
		int ans=0;
		int fl=0;
		f(1,n,i){
			ans++;
			int mx=min(m,len[i]);
			fl=0;
			f(1,len[i],j){
				if(ch[j]!=sh[i][j]){
					fl=1;
					break;	
				}
				ans++;
			}
			if(!fl)	break;	
		}
		printf("%d\n",ans);
	}
	return 0;
}

