#include<bits/stdc++.h>
#define _fre_(f,x,y) \
{ \
	if(x) std::freopen(f".in","r",stdin); \
	if(y) std::freopen(f".out","w",stdout); \
}
namespace IO{
	static constexpr unsigned SIZE=1<<20;
	char buf[SIZE],*p1=buf,*p2=buf,obuf[SIZE],*p3=obuf;
	char getch(){
		if(__builtin_expect(p1==p2,0)) p2=(p1=buf)+std::fread(buf,1,SIZE,stdin);
		return *p1++;
	}
	void putch(char ch){
		if(__builtin_expect(p3-obuf==SIZE,0)) std::fwrite(obuf,1,SIZE,stdout);
		*p3++=ch;
	}
	struct _IO_flusher_{
		~_IO_flusher_(){
			std::fwrite(obuf,1,p3-obuf,stdout);
		}
	}io;
	template<typename _Tp,
	typename std::enable_if<std::is_integral<_Tp>::value>::type* =nullptr>
	void _read_(_Tp &x){
		x=0;
		char ch=getch();
		for(;ch<'0'||ch>'9';ch=getch());
		for(;ch>='0'&&ch<='9';ch=getch()) x=x*10+(ch&15);
	}
	template<typename ...Args>
	void read(Args &...args){
		void(std::initializer_list<unsigned>{(_read_(args),0u)...});
	}
	template<typename _Tp,
	typename std::enable_if<std::is_integral<_Tp>::value>::type* =nullptr>
	void _write_(_Tp x){
		if(x<0) putch('-'),x=-x;
		if(x>9) _write_(x/10);
		putch((x%10)|48);
	}
	template<typename ...Args>
	void write(Args &&...args){
		void(std::initializer_list<unsigned>{(_write_(args),0u)...});
		putch('\n');
	}
}
using namespace IO;
namespace QL{
	constexpr int N=5e5+5,M=5e5+5,Sqrt=710;
	int n,m,q;
	struct Edge{
		int u,v;
	};
	Edge Ed[M];
	std::array<std::vector<std::pair<int,int>>,N> G,pr;
	void predfs(int u,int p,std::vector<std::pair<int,int>> &v){
		if(p>Sqrt) return;
		if(p!=1) v.emplace_back(u,p);
		for(auto e:G[u]) predfs(e.first,p*e.second,v);
	}
	void prework(){
		for(int s=1;s<=n;++s){
			predfs(s,1,pr[s]);
			std::sort(pr[s].begin(),pr[s].end());
			pr[s].erase(std::unique(pr[s].begin(),pr[s].end()),pr[s].end());
		}
	}
	int query(int s,int t){
		static std::queue<std::pair<int,int>> q;
		q.emplace(s,1);
		int ans=-1;
		auto work=[&ans,&t](auto &q){
			if(q.empty()) return false;
			auto u=q.front();
			if(u.first==t)
				ans=std::max(ans,u.second);
			q.pop();
			for(auto e:G[u.first]){
				if(e.second*u.second>m) continue;
				else if(e.second*u.second<=Sqrt) q.emplace(e.first,e.second*u.second);
				else{
					auto l=std::lower_bound(pr[e.first].begin(),pr[e.first].end(),std::pair<int,int>(t,0));
					if(l==pr[e.first].end()) continue;
					auto r=std::upper_bound(pr[e.first].begin(),pr[e.first].end(),std::pair<int,int>(t,0));
					auto itr=std::upper_bound(l,r,std::pair<int,int>(t,m/(e.second*u.second)));
					if(itr==l) continue;
					--itr;
					ans=std::max(ans,itr->second*e.second*u.second);
				}
			}
			return true;
		};
		while(work(q));
		return ans;
	}
	signed _main_(){
		read(n,m,q);
		std::fill_n(G.begin()+1,n,std::vector<std::pair<int,int>>());
		std::fill_n(pr.begin()+1,n,std::vector<std::pair<int,int>>());
		for(int i=2;i<=m;++i){
			read(Ed[i].u,Ed[i].v);
			G[Ed[i].u].emplace_back(Ed[i].v,i);
			G[Ed[i].v].emplace_back(Ed[i].u,i);
		}
		prework();
		for(int i=1,s,t;i<=q;++i){
			read(s,t);
			write(query(s,t));
		}
		return 0;
	}
}
signed main(){
	 _fre_("tour",1,1);
	return QL::_main_();
}
/*
IO优化可还行（大乐 ） 
模板没给可还行（更乐） 
不如手写（？？？） 
置换？看不懂 
复杂度似乎跟路径权值有关 
不存在1，也就是说只要走了就会增大
然后我们直接双向广搜，发现这边一个x，那边都大于floor(m/x)，这个x就没得玩
考虑一下，乘个10次我们就炸1e5了，所以……真就暴力是吧 
维护两侧走到点的最小值，然后扩展时发现没法走就截断。
能走的边其实相当少，不然就非常短。
有根号分治的既视感。
>sqrt(m),goto <sqrt(m) ,prework for <sqrt(m)
<sqrt(m),go until >sqrt(m)
直观算一算非常短。
要求路径最长/最短/都可？
不知道，似乎都需要。
跳 
做完了，但复杂度存疑
还没加剪枝，大样例倒先过了……氵是吧 
这个题啊，我还得构造，随机数据根本卡不掉，开满了都卡不掉…… 
双向不好写欸……不想写了qaq
直接信仰吧 
*/ 
