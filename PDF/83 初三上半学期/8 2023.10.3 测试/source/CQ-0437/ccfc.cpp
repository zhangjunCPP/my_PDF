#include<bits/stdc++.h>
using namespace std;
namespace IO_ER{
	#define LL long long
	#define db double
	#define ULL unsigned long long
	#define In inline
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
#define P 1145141

int n;

char s[N];

ULL H[N];
ULL P_[N];

int ans[N];

In ULL gtha(int l,int r){
	return H[r]-H[l-1]*P_[r-l+1];
}

int main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
//	cout<<n<<endl;
	f(1,n,i)H[i]=H[i-1]*P+s[i]-'a'+1;
	P_[0]=1;
	f(1,n,i)P_[i]=P_[i-1]*P;
	f_(n,1,i){
		if(n-i+1<=3){
			ans[i]=0;
			continue;
		}
		ULL h1,h2;
		int mx=(n+2*i)/3-1;
		f(i,mx,j){
			int k=2*j-i+1;
			int l=n-j+i;
			h1=gtha(i,j);
			h2=gtha(j+1,k);
			if(h1!=h2)continue;
			h2=gtha(l,n);
			if(h1!=h2)continue;
//			if(i==6)cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
			ans[i]++;
		}
	}
	ff(1,n,i)printf("%d ",ans[i]);
	printf("%d\n",ans[n]);
	return 0;
}

