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

#define N 1000050

int n,m;

vector<int>p[N];

namespace sub1{
	int a[N];
	int b[N];
	int ans[N];
	int Main(){
		for(auto x:p[1])a[x]=1;
		for(auto x:p[2])b[x]=1;
		int mx=max(p[1].back(),p[2].back());
		if(mx>m-1){
			puts("-1");
			return 0;
		}
		int it=-1;
		f_(mx,0,i){
			if(a[i]==b[i]){
				it=i;
				break;		
			}
		}
		if(it==-1){
			ff(0,m,i)printf("%d",a[i]|b[i]);
			return 0;
		}
		it++;
		while(a[it+1]||b[it+1])it++;
		if(it>m-1){
			puts("-1");
			return 0;
		}
		int fl=0;
		f_(it,1,i){
			if(a[i]<b[i]){
				fl=1;
				break;
			}
			if(a[i]>b[i]){
				fl=2;
				break;
			}
		}
//		cout<<it<<endl;
		ff_(m-1,it,i)ans[i]=a[i]|b[i];
		ans[it]=1;
		f_(it-1,0,i)ans[i]=fl==1?a[i]:b[i];
		ff(0,m,i)printf("%d",ans[i]);
		return 0;
	}
}

namespace sub2{
	int a[15];
	int b[15];
	int mx;
	int ans=INF;
	In void dfs(int pos){
		if(pos>n){
			int sum=0;
			f(1,n,i)sum|=b[i];
			ans=min(ans,sum);
			return;
		}
		f(a[pos],mx,i){
			int fl=0;
			ff(1,pos,j){
				if(b[j]&i){
					fl=1;
					break;
				}
			}
			if(fl)continue;
			b[pos]=i;
			dfs(pos+1);
		}
	}

	int Main(){
		f(1,n,i)for(auto x:p[i])a[i]+=(1<<x);
//		f(1,n,i)cout<<a[i]<<endl;
		mx=(1<<m)-1;
		dfs(1);
		if(ans==INF)puts("-1");
		else{
			ff(0,m,i)printf("%d",ans>>i&1);		
		}
		return 0;
	}
}

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	read(n,m);
	f(1,n,i){
		int k,x;
		read(k);
		f(1,k,j){
			read(x);
			p[i].emplace_back(x);
		}
	}
	if(n==2)sub1::Main();
	else{
		sub2::Main();
	}
	return 0;
}

