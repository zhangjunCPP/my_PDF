/*
谢谢他想好了算法。
k 个 (x,t) 对： 
- 找到 (?,t)，t 是最小。
- 覆盖单点为 (x,t')。
- 覆盖单点为 (x',t')，++cnt。
暴力，单次 O(m)，共 O(nm)，但没有前途。
只关心 cnt。
又或者，考虑基于上一种算这一种。
又或是，优化这个过程。
只关心最后 k 个不同的。
一个无用的操作是，把相邻且相同的缩在一起。
集合的扩展很难优化，因为 m 个位置必须，而 1~n 的大小也是必须的。
需要进行问题的转换。
不妨考虑什么时候不会 ++cnt，那也就是前 k 个不同的数字包含自己。
考虑二分这个 k，得到最后一个不包含自己的。
然后这前面的都 --，这后面的都 ++，离线区间加单点查，乱做。
怎么得到这个 k？已经 O(m lg n) 了。
可以动态维护前面所有不同的数字，然后按加入进来的时间再二分找。
复杂度是 O(m lg^2n)，可以过。
暴力 ready，链表无锅。
开始正解。
等一下我链表好像不能求最后 k 个元素是否包含那个啥？
也不是，反正值域摆在那，好像也……不能统计。
讨论一下，删除和插入都是在开头结尾，完全可以再开一个队列，链表留着判存在。
得到 a[i] 在队列里的位置，然后就拿去直接算。
错了错了。
受不了了，简单无脑，块链！
不对，维护时间，当前减去需要。
也不行。
算了先走，最后半小时回来再说块链不块链的事。
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
	constexpr int N=5e5+5;
	int n,m,a[N];
	struct List{
		int pre[N],nxt[N],siz;
		void erase(int x){nxt[pre[x]]=nxt[x],pre[nxt[x]]=pre[x],--siz,pre[x]=nxt[x]=-1;}
		void insert(int x,int y){nxt[pre[x]=pre[y]]=x,nxt[pre[y]=x]=y,++siz;}
		bool in(int x)const{return ~pre[x]&&~nxt[x];}
		int prev(int x)const{return pre[x];}
		int next(int x)const{return nxt[x];}
		int size()const{return siz;}
		void clear(){
			memset(pre,-1,sizeof(pre[0])*(n+2)),memset(nxt,-1,sizeof(nxt[0]*(n+2)));
			pre[n+1]=0,nxt[0]=n+1,siz=0;
		}
	};
	List L;
	namespace solve1{
		int calc(int k){
			int ret=0;
			L.clear();
			for(int i=1;i<=m;++i){
				if(!L.in(a[i])){
					if(L.size()<k) L.insert(a[i],n+1);
					else L.erase(L.next(0)),L.insert(a[i],n+1);
					++ret;
				}
				else L.erase(a[i]),L.insert(a[i],n+1);
			}
			return ret;
		}
		void solve_main(){
			for(int k=1;k<=n;++k) write(calc(k),' ');
		}
	}
	namespace solve2{
//		using ll=long long;
//		ll sum[N*4],tag[N*4];
//		void push(int p,int l,int mid,int r){
//			if(tag[p]){
//				tag[p<<1]+=tag[p],sum[p<<1]+=(mid-l+1)*tag[p];
//				tag[p<<1|1]+=tag[p],sum[p<<1|1]+=(r-mid)*tag[p];
//				tag[p]=0;
//			}
//		}
//		void modify(int p,int l,int r,int L,int R,int V){
//			if(L<=l&&r<=R) return sum[p]+=(r-l+1)*V,tag[p]+=V,void();
//			int mid=(l+r)>>1;
//			push(p,l,mid,r);
//			if(L<=mid) modify(p<<1,l,mid,L,R,V);
//			if(R>mid) modify(p<<1|1,mid+1,r,L,R,V);
//			sum[p]=sum[p<<1]+sum[p<<1|1];
//		}
//		int query(int p,int l,int r,int L,int R){
//			if(L<=l&&r<=R) return sum[p];
//			int mid=(l+r)>>1;
//			push(p,l,mid,r);
//			if(L<=mid&&R>mid) return query(p<<1,l,mid,L,R)+query(p<<1|1,mid+1,r,L,R);
//			else return L<=mid?query(p<<1,l,mid,L,R):query(p<<1|1,mid+1,r,L,R);
//		}
		struct BIT{
			int c[N];
			void upd(int x,int v){for(;x<=m;x+=x&-x) c[x]+=v;}
			int qry(int x){int ret=1;for(;x;x^=x&-x) ret+=c[x];return ret;}
			int qry(int l,int r){return qry(r)-qry(l-1);}
		};
		BIT T;
		int ans[N];
		void solve_main(){
			L.clear();
			ans[1]=m;
			for(int i=1;i<=m;++i){
				static int ap[N];
				if(!L.in(a[i])) L.insert(a[i],n+1),T.upd(ap[a[i]]=i,1);
				else{
					--ans[T.qry(ap[a[i]],i)],T.upd(ap[a[i]],-1);
					T.upd(ap[a[i]]=i,1),L.erase(a[i]),L.insert(a[i],n+1);
				}
			}
			for(int i=1;i<=n;++i) write(ans[i]+=ans[i-1],' ');
		}
	}
	void _main_(){
		read(n,m);
		for(int i=1;i<=m;++i) read(a[i]);
//		return solve2::solve_main();
		if(n<=10000&&m<=10000) return solve1::solve_main();
		else return solve2::solve_main();
	}
}
signed main(){
	_fre_("manage",1,1);
	return MAIN::_main_(),0;
}
