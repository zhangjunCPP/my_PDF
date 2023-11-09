#include<bits/stdc++.h>
using namespace std;
namespace io{
	template<typename T> void read(T &x){
		x=0; bool f=0; char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()){
			if(ch=='-'){
				f=1;
			}
		}
		for(;ch>='0'&&ch<='9';ch=getchar()){
			x=(x<<1)+(x<<3)+(ch^48);
		}
		x=f?-x:x;
	}
	template<typename T> void write(T x){
		if(x<0){
			x=-x,putchar('-');
		}
		if(x>9){
			write(x/10);
		}
		putchar(x%10+'0');
	}
}
const int N=5e5+5;
int n,a[N];

namespace n_100{
	int ans;
	bool tag[N];
	int st[N];
	void init(){
		for(int i=1;i<=n-3;i++){
			if(a[i]==a[i+2]&&a[i+1]==a[i+3]){
				tag[i]=1;
			}
		}
	}
	void dfs(int _,int cnt){
		if(_==n+1){
			ans=max(ans,cnt*4);
			return ;
		}
		dfs(_+1,cnt);
		if(tag[_]){
			st[cnt+1]=_;
			dfs(_+4,cnt+1);
		}
	}
}
int main(){
	freopen("comb.in","r",stdin);
	freopen("comb.out","w",stdout);
	io::read(n);
	for(int i=1;i<=n;i++){
		io::read(a[i]);
	}
	n_100::init();
	n_100::dfs(1,0);
	io::write(n_100::ans);
	
	return 0;
}
/*
8
1 2 1 2 1 2 1 2
*/
