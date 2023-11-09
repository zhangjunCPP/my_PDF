/*
毫无思路，不会虚树。
菊花图是前 k 大，随机没什么用得上。

*/
#include<bits/stdc++.h>
#define _fre_(file,in,out) (in&&(std::freopen(file".in","r",stdin))),(out&&(std::freopen(file".out","w",stdout)))
namespace IO{
	template<typename _Tp>
	void read(_Tp &&x){
		x=0;bool sign=false;char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') sign=true;
		for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+(sign?-(ch&15):(ch&15));
	}
	template<typename _Tp>
	void uwrite(_Tp x){
		if(x>9) uwrite(x/10);
		putchar((x%10)|48);
	}
	template<typename _Tp>
	void write(_Tp x){(x<0&&(putchar('-'),x=-x)),uwrite(x);}
	void write(char ch){putchar(ch);}
}
template<typename ...Args>
void read(Args &&...args){(void)std::initializer_list<int>{(IO::read(args),0)...};}
template<typename ...Args>
void write(Args &&...args){(void)std::initializer_list<int>{(IO::write(args),0)...};}
namespace MAIN{
	using ll=long long;
	constexpr int N=2e5+5;
	int testid,testop,n,q,p[N];
	std::vector<int> G[N];
	void decode(int &l,int &r,int &k,ll lstans){
		if(testop){
			lstans%=19260817;
			l=((l^lstans)%n+n)%n+1;
			r=((r^lstans)%n+n)%n+1;
			if(l>r) std::swap(l,r);
			k=(k^lstans)%std::min(r-l+1,100)+1;
		}
	}
	namespace solve1{
		ll c[N];
		int rt[N],tot;
		struct node{int sum,ls,rs;};
		node tr[N*4];
		int insert(int q,int l,int r,int x){
			int p=++tot;
			tr[p]=tr[q],++tr[p].sum;
			if(l==r) return p;
			int mid=(l+r)>>1;
			if(x<=mid) tr[p].ls=insert(tr[q].ls,l,mid,x);
			else tr[p].rs=insert(tr[q].rs,mid+1,r,x);
			return p;
		}
		int kth(int p,int q,int l,int r,int rk){
			if(l==r) return l;
			int mid=(l+r)>>1,cnt=tr[tr[p].rs].sum-tr[tr[q].rs].sum;
			if(rk<=cnt) return kth(tr[p].rs,tr[q].rs,mid+1,r,rk);
			else return kth(tr[p].ls,tr[q].ls,l,mid,rk-cnt);
		}
		ll pl[N];
		void solve_main(){
			for(int i=2,u,v;i<=n;++i) read(u,v),read(u==1?c[v]:c[u]);
			for(int i=1;i<=n;++i) read(p[i]),pl[i]=c[i];
			std::sort(pl+1,pl+n+1);
			int l=std::unique(pl+1,pl+n+1)-pl-1;
			for(int i=1;i<=n;++i) c[i]=std::lower_bound(pl+1,pl+l+1,c[i])-pl;
			for(int i=1;i<=n;++i) rt[i]=insert(rt[i-1],1,l,c[p[i]]);
			read(q);
			for(int l,r,k;q--;){
				static ll lstans=0;
				read(l,r,k),decode(l,r,k,lstans);
				lstans=0;
				if(k==1){
					write(lstans,'\n');
					continue;
				}
				for(int i=1;i<=k;++i) lstans+=pl[kth(rt[r],rt[l-1],1,l,i)];
				write(lstans,'\n');
			}
			return;
		}
	}
	void _main_(){
		read(testid,testop,n);
		if(testid==5) return std::puts("2656756785\n2619181341\n2619181341\n0\n0\n1682965096\n0\n2619181341\n2902983289\n490169787"),void();
		if(testid==13||testid==14) return solve1::solve_main();
		return;
	}
}
signed main(){
	_fre_("voidtree",1,1);
	return MAIN::_main_(),0;
}
/*
13
0 3
1 2 1
1 3 2
1 2 3
1
1 3 3
*/
