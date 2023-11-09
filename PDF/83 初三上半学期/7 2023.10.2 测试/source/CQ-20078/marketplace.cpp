#include<bits/stdc++.h>
#define _fre_(file,in,out) { \
	if(in) std::freopen(file".in","r",stdin); \
	if(out) std::freopen(file".out","w",stdout); \
}
namespace IO{
	template<typename _Tp>
	void read(_Tp &x){
		x=0;bool sign=false;char ch=getchar();
		for(;ch<'0'&&ch>'9';ch=getchar()) sign|=ch=='-';
		for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+(ch&15);
	}
}
template<typename ...Args>
void read(Args &...args){(void)std::initializer_list<int>{(IO::read(args),0)...};}
namespace MAIN{
	constexpr int N=1e5+5;
	int n,m,a[N],b[N],ans[N];
	int pl[N*2],tot;
	bool used[N*10];
	int calc(int x){
		for(int i=1;i<=tot;++i) used[pl[i]]=false;
		used[x]=true;
		while(1){
			for(int i=1;i<=n;++i){
				if(!used[a[i]]){
					used[a[i]]=true;
				}
				else if(!used[b[i]]){
					used[b[i]]=true;
				}
				else return i;
			}
		}
	}
	void _main_(){
		read(n,m);
		for(int i=1;i<=n;++i) read(a[i],b[i]),pl[++tot]=a[i],pl[++tot]=b[i];
		std::sort(pl+1,pl+tot+1);
		tot=std::unique(pl+1,pl+tot+1)-pl-1;
		for(int i=1;i<=tot;++i)
			++ans[calc(pl[i])];
		ans[calc(0)]+=m-tot;
		for(int i=1;i<=n;++i) std::printf("%d\n",ans[i]);
		return;
	}
}
signed main(){
	_fre_("marketplace",1,1);
	return MAIN::_main_(),0;
}
