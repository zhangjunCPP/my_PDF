#include<bits/stdc++.h>
using namespace std;
namespace IO{
	template<typename T> void read(T &x){
		x=0; bool f=0; char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
		for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
		if(f) x=-x;
	}
	template<typename T,typename ...Args> void read(T &x,Args &...args){
		read(x),read(args...);
	}
	template<typename T> void write(T x){
		if(x<0) putchar('-'),x=-x;
		short stk[50],top=0;
		do stk[++top]=x%10,x/=10; while(x);
		for(;top;top--) putchar(stk[top]^48);
	}
	void write(char x){ putchar(x); }
	template<typename T,typename ...Args> void write(T x,Args ...args){
		write(x),write(args...);
	}
}
const int N=1e5+5;
int n,q;
int a[N];
int cnt[N];
int main(){
	freopen("maxmex.in","r",stdin);
	freopen("maxmex.out","w",stdout);
	IO::read(n);
	for(int i=1;i<=n;i++) IO::read(a[i]);
	IO::read(q);
	for(;q--;){
		int len; IO::read(len);
		memset(cnt,0,sizeof(int)*(n+1));
		for(int i=1;i<=len;i++) cnt[a[i]]++;
		int ans;
		for(ans=0;;ans++) if(!cnt[ans]) break;
		for(int i=2;i+len-1<=n;i++){
			cnt[a[i-1]]--;
			cnt[a[i+len-1]]++;
			int f;
			for(f=0;;f++) if(!cnt[f]) break;
			ans=max(ans,f); 
		}
		IO::write(ans,'\n');
	}
	return 0;
} 
