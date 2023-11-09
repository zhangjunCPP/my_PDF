/* 
即比较字符串，先逐位再长度，求次数。
也就是，S 出现在 s[n]，则答案为：
sum{i<=n}{lcp(s[i],S)+1}
单个字符串很短。
大力哈希什么的显然不行了，后缀数组也悬。
扔上 AC自动机？
可以很容易地找到查询串出现位置。
答案似乎是前缀上 trie 的子树和。
不想写什么弱智 cjh。
干脆点就做两次，第一次确定位置，第二次算答案。
离线万岁！
过了，不用保龄了！
等一下很奇怪！
这个空间是不是不太对？
存下所有的字符串只需要 4mb
存下这颗 trie 需要…… 300mb???
《内存限制：32mb》
你玩我呢？
不难发现，问题在于 trie 实在是太浪费空间了。
但是即使去掉 trie 的空间常数，也非常地紧凑。
不如用一些怪异的方法。
考虑 bitset 存每一层 26 个字符，共 30 层。
这样也就 1mb。
然后我们逐层交起来，得到一个 new bitset。
这个 bitset 中的第一个 1 就是我们停止的位置。
然后需要算前面的贡献。
从第 i 层消失的一个串，贡献是 i。
然后就是 bitset 里面某一个位置前 1 的个数。
那么时间 O(q*30*n/64)，当 n=q=100000 时跑不过。
其实找字符串出现我是不是可以暴力二分？
然后相当于是一个前缀和，逐位算？
emm……
不甚对。
空间被卡了，最神秘的一次。
横竖过不去，指针动态冲。
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
	void read(char *str){
		for(;(*str=getchar())==' '||*str=='\n';);
		for(;(*++str=getchar())!=' '&&*str!='\n';);
		*str='\0';
	}
}
template<typename ...Args>
void read(Args &&...args){(void)std::initializer_list<int>{(IO::read(args),0)...};}
constexpr int N=1e5+1;
int n,q;
struct string{
	char s[33];
	char &operator[](int x){return s[x];}
	char operator[](int x)const{return s[x];}
	bool operator<(const string &t)const{
		int i;
		for(i=0;s[i]&&t[i];++i)
			if(s[i]<t[i]) return true;
			else if(s[i]>t[i]) return false;
		if(s[i]&&t[i]) return s[i]<t[i];
		else if(!s[i]&&t[i]) return true;
		else return false;
	}
	bool operator!=(const string &t)const{
		int i;
		for(i=0;s[i]&&t[i];++i)
			if(s[i]!=t[i]) return true;
		return s[i]||t[i];
	}
};
string txt[N],pat[N];
struct node{
	node():L{},sum{0},id{0}{}
	std::list<std::pair<char,node*>> L;
	int sum,id;
	node *find(char c){
		for(auto it:L) if(it.first==c) return it.second;
		return nullptr;
	}
	node *get(char c){
		node *p=find(c);
		if(p) return p;
		else p=new node{};
		L.insert(L.begin(),{c,p});
		return p;
	}
};
node *rt=new node();
void insert(char *str,int id){
	node *p=rt;
	++p->sum;
	for(;*str;++str)
		p=p->get(*str),++p->sum;
	p->id=id;
}
int find(char *str){
	node *p=rt;
	for(node *q;*str;p=q,++str)
		if(!(q=p->find(*str))) return -1;
	return p->id;
}
int calc(char *str){
	node *p=rt;
	int ret=p->sum;
	// std::fprintf(stderr, "%d\n", ret);
	for(node *q;*str;++str){
		if(!(q=p->find(*str))) return ret;
		ret+=(p=q)->sum;
	}
	return ret;
}
void clear(node *p=rt){
	for(auto it:p->L)
		clear(it.second);
	delete p;
}
std::vector<int> ap[N];
int ans[N];
signed main(){
	_fre_("lihua",1,1);
	read(n);
	for(int i=1;i<=n;++i) read(txt[i].s),insert(txt[i].s,i);
	read(q);
	for(int i=1;i<=q;++i){
		read(pat[i].s);
		int t=find(pat[i].s);
		if(~t) ap[t].emplace_back(i);
		else ans[i]=calc(pat[i].s);//,std::printf("%d %d\n",i,ans[i]);
		// int ans=0;
		// for(int j=1;j<=n;++j){
		// 	int k;
		// 	for(k=0;pat[i][k]&&txt[j][k];++k)
		// 		if(pat[i][k]!=txt[j][k]) break;
		// 	ans+=k+1;
		// 	if(!pat[i][k]&&!txt[j][k]) break;
		// }
		// std::printf("%d\n",ans);
	}
	clear(),rt=new node();
	for(int i=1;i<=n;++i){
		insert(txt[i].s,i);
		for(int it:ap[i]) ans[it]=calc(pat[it].s);
	}
	for(int i=1;i<=q;++i) std::printf("%d\n",ans[i]);
	return 0;
}
/*
g++ -std=c++14 -O2 -o code -Wall -Wextra -fsanitize=address,undefined lihua.cpp
./code < lihua/ex_lihua1.in
*/