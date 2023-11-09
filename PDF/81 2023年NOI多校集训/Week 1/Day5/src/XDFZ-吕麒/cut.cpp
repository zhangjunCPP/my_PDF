#include<iostream>
#include<cassert>
class IO{
protected:
	using reader=std::istream;
	using writer=std::ostream;
	using LIST=std::initializer_list<int>;
	reader&in;
	writer&out,&err;
public:
	IO():in{std::cin},out{std::cout},err{std::cerr}{
		in.tie(nullptr)->sync_with_stdio(false);
		out.tie(nullptr)->sync_with_stdio(false);
	}
	IO(reader&In,writer&Out,writer&Err):in{In},out{Out},err{Err}{
		in.tie(nullptr)->sync_with_stdio(false);
		out.tie(nullptr)->sync_with_stdio(false);
	}
	~IO(){}
	template<typename...Args>
	void read(Args&...args){void(LIST{(in>>args,0)...});}
	template<typename...Args>
	void write(Args&&...args){void(LIST{(out<<args,0)...});}
	template<typename...Args>
	void error(Args&&...args){void(LIST{(err<<args,0)...});}
	template<typename...Args>
	void writeln(Args&&...args){void(LIST{(out<<args,0)...}),out.put('\n');}
	template<typename...Args>
	void errorln(Args&&...args){void(LIST{(err<<args,0)...}),err.put('\n');}
}io;
#define _fre(s) {freopen(s".in","r",stdin),freopen(s".out","w",stdout);}
constexpr int N=5e5+5,K=25;
int n,up,a[N],f[N],fr[N],cnt[N][K];
auto chk=[](int l,int r,int x){
	for(int k=0;k<x;++k)
		if(cnt[r][k]<=cnt[l-1][k]) return false;
	return true;
};
signed main(){
#ifndef LOCAL
	_fre("cut");
#endif
	io.read(n);
	for(int i=1;i<=n;++i)
		io.read(a[i]),up=std::max(up,a[i]),++cnt[i][a[i]];
	++up;
	for(int i=2;i<=n;++i)
		for(int k=0;k<up;++k) cnt[i][k]+=cnt[i-1][k];
	for(int i=1;i<=n;++i){
		for(int x=0;x<=up;++x){
			int l=1,r=i;
			for(int mid;l<r;){
				mid=(l+r+1)>>1;
				if(chk(mid,i,x)) l=mid;
				else r=mid-1;
			}
			if(chk(l,i,x)&&f[l-1]+x>f[i]){
				f[i]=f[l-1]+x,fr[i]=l;
			}
		}
	}
	static int sta[N],top;
	for(int x=n;fr[x];x=fr[x]-1) sta[++top]=fr[x];
	io.writeln(f[n],' ',top);
	for(;top;) io.write(sta[top--],' ');
	return 0;
}
/*
你看这玩意儿就很dp
n^3的先走起
然而方案锅了……
我们回来磕T2吧
T3没思路，没暴力思路
T4不会lcm，有点意思啊/kk
看见了吗？那个a[i]灰常滴小
肯定不只是方便我们求mex的，而且还有性质分
对于那个10pts啊，我们发现0肯定尽量单独分
但是呢，若个旁边有1，可以连起来得到2
就每找到1的段，就把开头前那个0弄进来，这是O(n)，可能还得正反各跑一次
然后呢？好像也没啥……
考虑以i结尾的段mex为x，那可以二分找到最后一个使之为x的开头j
那f[i]=std::max(f[i],f[j-1]+x)
x只有21
我们可以跑！
嘿嘿，跑出来了
cpeditor的输出有上限，多了会曝RE……吓死个LQ
前三个样例的方案都刚好一样，针不戳
*/
