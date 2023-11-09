/*
лл��������㷨��
k �� (x,t) �ԣ� 
- �ҵ� (?,t)��t ����С��
- ���ǵ���Ϊ (x,t')��
- ���ǵ���Ϊ (x',t')��++cnt��
���������� O(m)���� O(nm)����û��ǰ;��
ֻ���� cnt��
�ֻ��ߣ����ǻ�����һ������һ�֡�
�ֻ��ǣ��Ż�������̡�
ֻ������� k ����ͬ�ġ�
һ�����õĲ����ǣ�����������ͬ������һ��
���ϵ���չ�����Ż�����Ϊ m ��λ�ñ��룬�� 1~n �Ĵ�СҲ�Ǳ���ġ�
��Ҫ���������ת����
��������ʲôʱ�򲻻� ++cnt����Ҳ����ǰ k ����ͬ�����ְ����Լ���
���Ƕ������ k���õ����һ���������Լ��ġ�
Ȼ����ǰ��Ķ� --�������Ķ� ++����������ӵ���飬������
��ô�õ���� k���Ѿ� O(m lg n) �ˡ�
���Զ�̬ά��ǰ�����в�ͬ�����֣�Ȼ�󰴼��������ʱ���ٶ����ҡ�
���Ӷ��� O(m lg^2n)�����Թ���
���� ready�������޹���
��ʼ���⡣
��һ������������������ k ��Ԫ���Ƿ�����Ǹ�ɶ��
Ҳ���ǣ�����ֵ������ǣ�����Ҳ��������ͳ�ơ�
����һ�£�ɾ���Ͳ��붼���ڿ�ͷ��β����ȫ�����ٿ�һ�����У����������д��ڡ�
�õ� a[i] �ڶ������λ�ã�Ȼ�����ȥֱ���㡣
���˴��ˡ�
�ܲ����ˣ������ԣ�������
���ԣ�ά��ʱ�䣬��ǰ��ȥ��Ҫ��
Ҳ���С�
�������ߣ�����Сʱ������˵�������������¡�
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
