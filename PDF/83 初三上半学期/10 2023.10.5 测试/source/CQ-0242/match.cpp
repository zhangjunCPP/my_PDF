/* 
(a,b) 和 (b,c) 在边集内，那么再添加的边，必须有一段是 a/b/c。
不止，限制死了为 (a,c) 或 (b,*)，因为没有重边。
b 为根的菊花，是一种； (a,b),(b,c),(a,c) 三元环，是一种。
菊花的叶子上再加边，则不合法或是只能为三元环。
所以答案是 max(d,f?3:0)，d 是度数。
三元环计数？hzl /bx/bx/bx
虽然很想要 std::bitset 艹过去，但是数据开到了 1e6
但是如果度数大于 3 没必要 check，所以可以直接暴力的说？
 */
#include<bits/stdc++.h>
namespace IO{
	template<typename _Tp>
	void read(_Tp &x){
		x=0;bool sign=false;char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') sign=true;
		for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+(sign?-(ch&15):ch&15);
	}
	template<typename _Tp>
	void uwrite(_Tp x){
		if(x>9) uwrite(x/10);
		putchar((x%10)|48);
	}
	template<typename _Tp>
	void write(_Tp x){x<0&&(putchar('-'),x=-x),uwrite(x);}
	void write(char ch){putchar(ch);}
	void write(char *str){printf("%s",str);}
	void write(const char *str){printf("%s",str);}
}
#define _fre_(file,in,out) { \
	if(in) std::freopen(file".in","r",stdin); \
	if(out) std::freopen(file".out","w",stdout); \
}
template<typename ...Args>
void read(Args &...args){(void)std::initializer_list<int>{(IO::read(args),0)...};}
template<typename ...Args>
void write(Args ...args){(void)std::initializer_list<int>{(IO::write(args),0)...};}
namespace MAIN{
    constexpr int N=1e6+5;
    int n,m;
    std::vector<int> G[N];
	void _main_(){
        read(n,m);
        for(int i=1;i<=n;++i) G[i].clear();
        for(int i=1,u,v;i<=m;++i)
            read(u,v),G[u].emplace_back(v),G[v].emplace_back(u);
        int ans=0;
        for(int i=1;i<=n;++i) ans=std::max(ans,int(G[i].size()));
        if(ans>=3) return write(ans,'\n');
        bool found=false;
        for(int a=1;a<=n;++a){
            for(int b:G[a]){
                for(int c:G[b]){
                    if(a==c) continue;
                    for(int d:G[c])
                        if(a==d){
                            found=true;
                            break;
                        }
                    if(found) break;
                }
                if(found) break;
            }
            if(found) break;
        }
        if(found) return write("3\n");
        else return write(ans,'\n');
	}
}
signed main(){
#ifndef FRANXX
	_fre_("match",1,1);
#endif
	int T;
    read(T);
    while(--T) MAIN::_main_();
    return MAIN::_main_(),0;
}
/* 
g++ -std=c++14 -O2 -Wall -Wextra -fsanitize=address,undefined -DFRANXX -o code match.cpp
./code < "match/match1.in"
 */