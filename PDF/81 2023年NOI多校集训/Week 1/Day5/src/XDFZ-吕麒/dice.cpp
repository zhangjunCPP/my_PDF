#include<iostream>
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
constexpr int N=105,D=65,MAX=1e6,DICE=10;
int n,d;
int a[DICE];
bool dfs(int x){
	if(x==7) return true;
	for(int i=0;i<=1000000;i+=x){
		bool f=1;
		for(int j=1;j<x&&f;++j) if(i==a[j]||(a[j]^i)%d!=0) f=0;
		if(f){
			a[x]=i;
			if(dfs(x+1)) return true;
		}
	}
	return false;
}
signed main(){
#ifndef LOCAL
	_fre("dice");
#endif
	io.read(n,d);
	if(n==1){
		io.writeln("Yes");
		for(int i=0;i<6;++i) io.write(d*i,' ');
		return 0;
	}
	else if(d==2){
		io.writeln("Yes");
		for(int i=1;i<=n;++i)
			io.writeln("0 2 4 6 8 10");
		return 0;
	}
	dfs(1);
	io.writeln("Yes");
	for(int i=1;i<=n;++i){
		for(int j=1;j<=6;++j) io.write(a[j],' ');
		io.write('\n');
	}
	return 0;
}
/*
哇，T1是构造
我们看下这个性质，发现d=2很有趣
这要求异或和为偶数，进而只能有偶数个骰子带有奇数并全是奇数（才能消掉）
你可以直接全偶数跑过去
那如果d=3？
首先这个倍数不会那么多，350000左右
欸等下，2可以全偶数跑过去，3呢？
手模一下，只有每次<<2，就可以异或了仍是3的倍数，因为这样相当于做加法
对于60，最多到61400，可以过！
好耶！
啊不是，60好像不是<<2……
那么就超出上限了，额……
WTF？？？我硬DFS能找出来？？？
1~60都是秒出，谔谔
等我打会儿后面暴力再回来拍
小打了个表，感觉是对的
因为这样都是同一个骰子，而这个骰子的6面本身怎样异或都是正确的，这样的话多异或几次也会因为自反律去掉影响
不管了，就这样
（话说这个DFS跑的出来真是离谱）
*/