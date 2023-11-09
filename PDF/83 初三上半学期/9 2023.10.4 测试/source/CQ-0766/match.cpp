/* 
开始慌了
来打暴力
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
	void write(char ch){putchar(ch);}
}
template<typename ...Args>
void read(Args &...args){(void)std::initializer_list<int>{(IO::read(args),0)...};}
template<typename ...Args>
void write(Args ...args){(void)std::initializer_list<int>{(IO::write(args),0)...};}
namespace MAIN{
    constexpr int N=2e5+5;
    int k,q,n;
    char txt[N];
    int calc1(char *pat,int l){
        int ret=0;
        for(int st=1,ed=l;ed<=n;++st,++ed){
            int x=1,y=l;
            for(;x<=l&&pat[x]==txt[st+x-1];++x);
            for(;y>=x&&pat[y]==txt[st+y-1];--y);
            if(y-x<k) ++ret;
        }
        return ret;
    }
    using ull=unsigned long long;
    constexpr ull P=131;
    ull hash[N],pw[N];
    ull hs[N];
    template<ull *hash>
    ull sub(int l,int r){return hash[r]-hash[l-1]*pw[r-l+1];}
    int calc2(char *pat,int l){
        int ret=0;
        for(int i=1;i<=l;++i) hs[i]=hs[i-1]*P+pat[i];
        for(int st=1,ed=l;ed<=n;++st,++ed){
            int x,y,L=0,R=l;
            for(int mid;L<R;){
                mid=(L+R+1)>>1;
                if(sub<hash>(st,st+mid-1)==sub<hs>(1,mid)) L=mid;
                else R=mid-1;
            }
            x=L+1,L=0,R=l;
            for(int mid;L<R;){
                mid=(L+R+1)>>1;
                if(sub<hash>(ed-mid+1,ed)==sub<hs>(l-mid+1,l)) L=mid;
                else R=mid-1;
            }
            y=l-L;
            if(y-x<k) ++ret;
        }
        return ret;
    }
	void _main_(){
        std::scanf("%d%s%d",&k,txt+1,&q),n=std::strlen(txt+1);
        pw[0]=1;
        for(int i=1;i<=n;++i) hash[i]=hash[i-1]*P+txt[i],pw[i]=pw[i-1]*P;
        for(int l;q--;){
            static char pat[N];
            std::scanf("%s",pat+1);
            if((l=std::strlen(pat+1))<=300) std::printf("%d\n",calc1(pat,l));
            else std::printf("%d\n",calc2(pat,l));
        }
		return;
	}
}
signed main(){
	_fre_("match",1,1);
	return MAIN::_main_(),0;
}
/* 
g++ -std=c++14 -O2 -Wall -Wextra -fsanitize=address,undefined match.cpp -o match
./match < "/mnt/hgfs/win_d/CQ-0766/match_data/ex_match1.in"
 */