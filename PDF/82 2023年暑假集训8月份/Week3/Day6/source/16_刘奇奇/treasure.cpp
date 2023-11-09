#include<bits/stdc++.h>
using namespace std;
namespace IO{
	template<typename T> void Read(T &x){
		x=0; bool f=0; char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
		for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
		if(f) x=-x;
	}
	template<typename T,typename ...Args> void Read(T &x,Args &...args){
		Read(x),Read(args...);
	}
	void Write(char x){ putchar(x); }
	template<typename T> void Write(T x){
		if(x<0) x=-x,putchar('-');
		int stk[50],top=0;
		do stk[++top]=x%10,x/=10; while(x);
		for(;top;top--) putchar(stk[top]^48);
	}
	template<typename T,typename ...Args> void Write(T x,Args ...args){
		Write(x),Write(args...);
	}
}
const int N=30;
int n,a[N];
namespace sub_1_2{
	bool check(){ return n<=15; }
	int bl[N],minn=INT_MAX;
	int sum[5],st[N];
	int calc(){
		memset(sum,0,sizeof sum);
		for(int i=1;i<=n;i++) sum[st[i]]+=a[i];
		sort(sum+1,sum+3+1);
		return sum[3]-sum[1];
	}
	void dfs(const int &step){
		if(step==n+1){
			int tmp=calc();
			if(tmp<minn){
				minn=tmp;
				for(int i=1;i<=n;i++) bl[i]=st[i];
			}
			return ;
		}
		for(int i=1;i<=3;i++) st[step]=i,dfs(step+1);
	}
	void work(){
		dfs(1);
		for(int i=1;i<=n;i++) IO::Write(bl[i],' ');
	}
}
namespace sub3{
	int bl[N];
	int lim;
	void dfs(const int &step,const int &x,const int &y,const int &z){
		if(step==n+1){
			for(int i=1;i<=n;i++) IO::Write(bl[i],' ');
			exit(0);
		}
		if(x+a[step]<=lim) bl[step]=1,dfs(step+1,x+a[step],y,z);
		if(y+a[step]<=lim) bl[step]=2,dfs(step+1,x,y+a[step],z);
		if(z+a[step]<=lim) bl[step]=3,dfs(step+1,x,y,z+a[step]);
	}
	void work(){
		for(int i=1;i<=n;i++) lim+=a[i];
		lim/=3;
		dfs(1,0,0,0);
	}
}
int main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	IO::Read(n);
	for(int i=1;i<=n;i++) IO::Read(a[i]);
	if(sub_1_2::check()) sub_1_2::work();
	else sub3::work();
	return 0;
}
