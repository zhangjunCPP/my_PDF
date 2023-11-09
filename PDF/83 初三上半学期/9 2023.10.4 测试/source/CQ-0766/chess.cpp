/* 
构造？看性质。
k=1 只能放一组。
p=2 一组就是一对。
k=2 是什么？
他个黑心题目没有大样例，气人。
p is prime？不理解用处。
且过且过。
后面的大概是更难蚌了，回。
没有大样例很怪异，切回windows写个暴力看看。
我回来了！
共 p^k(p^k-1)/2 对，每组有 p(p-1)/2 对。
上界是 (p^k(p^k-1))/(p(p-1)) 才是。
所以我打的暴力甚至跑不出一个上界……
先顺着写过去，然后斜着依次取即可。
然后发现这TM是k=2的做法，没有自己期望的那么牛逼。
三次是对于初始行这么做来划分，然后每行组内这么做。
然后发现深究下去，这是个非常牛逼的递归问题。
 */
#include<bits/stdc++.h>
namespace IO{
	#define _fre_(file,in,out) { \
		if(in) std::freopen(file".in","r",stdin); \
		if(out) std::freopen(file".out","w",stdout); \
	}
	template<typename _Tp>
	void read(_Tp &x){
		x=0;bool sign=false;char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()) sign|=ch=='-';
		for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+(sign?-(ch&15):(ch&15));
	}
	template<typename _Tp>
	void write(_Tp x){
		if(x<0) putchar('-'),x=-x;
		if(x>9) write(x/10);
		putchar((x%10)|48);
	}
    void write(const char *str){std::printf("%s",str);}
    void write(char *str){std::printf("%s",str);}
	void write(char ch){putchar(ch);}
}
template<typename ...Args>
void read(Args &...args){(void)std::initializer_list<int>{(IO::read(args),0)...};}
template<typename ...Args>
void write(Args ...args){(void)std::initializer_list<int>{(IO::write(args),0)...};}
namespace MAIN{
    constexpr int N=2e3+5;
	int k,p,n;
    int qpow(int a,int x){int ret=1;for(;x;x>>=1,a*=a) if(x&1) ret*=a;return ret;}
	std::vector<int> c[N];
	void _main_(){
        read(p,k),n=qpow(p,k);
        if(k==1){
            write("1");
            for(int i=0;i<n;++i) write(i,'\n');
            return;
        }
        if(p==2){
            write((n-1)*n/2,'\n');
            for(int i=1;i<n;++i)
                for(int j=0;j<i;++j)
                    write(j,' ',i,'\n');
            return;
        }
		if(k==2){
			int all=n*(n-1)/p/(p-1);
			int ZeroTwo=0;
			std::printf("%d\n",all);
			int t=n/p;
			for(int i=1;i<=t;++i){
				static int tot=0;
				c[i].reserve(p);
				for(int j=0;j<p;++j) c[i][j]=tot++;
				for(int j=0;j<p;++j) write(c[i][j],' ');
				write('\n'),++ZeroTwo;
			}
			for(int s=0;s<p;++s){
				for(int i=0;i<p;++i){
					write(c[1][s]);
					for(int j=2,x=i-s;j<=t;++j)
						write(' ',c[j][(x+=s)>=p?(x-=p):x]);
					write('\n'),++ZeroTwo;
				}
			}
			if(ZeroTwo!=all) std::puts("What a joker I am!");
			assert(ZeroTwo==all);
			return;
		}
		int all=n*(n-1)/p/(p-1);
		int ZeroTwo=0;
		std::printf("%d\n",all);
		std::vector<int> niu;
		static std::vector<std::vector<int>> vc;
		for(int i=0;i<n;++i) niu.emplace_back(i);
		vc.resize(niu.size(),std::vector<int>());
		for(;int(niu.size())>p;){
			int t=niu.size()/p;
			std::vector<int> tmp;
			int cur=vc.size();
			for(int s=0;s<t;++s){
				tmp.clear();
				for(int i=0;i<p;++i) tmp.emplace_back(niu[i+s]);
				vc.emplace_back(tmp);
			}
			niu.clear();
			for(;cur!=int(vc.size());++cur) niu.emplace_back(cur);
		}
		vc.emplace_back(niu);
		std::function<void(int)> dfs=[&dfs,&ZeroTwo](int id){
			if(vc[id].back()<n){
				for(int it:vc[id]) write(it,' ');
				write('\n'),++ZeroTwo;
				return;
			}
			for(int it:vc[id]) dfs(it);
			std::vector<int> tmp;
			for(int s=0;s<p;++s){
				for(int i=0;i<p;++i){
					tmp.clear();
					tmp.emplace_back(vc[vc[id][0]][s]);
					for(int j=1,x=i-s;j<p;++j)
						tmp.emplace_back(vc[vc[id][j]][(x+=s)>=p?(x-=p):x]);
					vc.emplace_back(tmp);
					dfs(vc.size()-1);
					vc.pop_back();
				}
			}
		};
		dfs(vc.size()-1);
		if(ZeroTwo!=all) std::printf("What a joker I am! %d %d",all,ZeroTwo);
		assert(ZeroTwo==all);
		return;
	}
}
signed main(){
	_fre_("chess",1,1);
	return MAIN::_main_(),0;
}
/* 
g++ -std=c++14 -O2 -Wall -Wextra -fsanitize=address,undefined chess.cpp -o chess
./chess < "/mnt/hgfs/win_d/CQ-0766/chess_data/ex_chess1.in"
 */