/* 
甚至字符串，八百年没碰过了
O(n^2) 暴力很好做，弄出哈希，然后对于每个后缀我们再枚举它一个后缀，判断能不能搞出那三个 A。                                                                  （这 TM 甚至有 70pts……）
然后我想再贪一点。
B是不重要的，非空即可，所以重点是这个重复出现的 A。
先不管中间那个 CF，发现 C__C 这里有一个公共前后缀，好像叫 border 的说。
能不能求出后缀 border？以及 border 的数量级？然后来做这个？
不好说。
这个题可以放 nlog^2n 的东西过去，我们看一下后缀数组（是的我不会写倍增求后缀数组）。
然后发现满足条件的好像是这样一个东西：
C C...C C...C
然后其中啊，有几部分是这样的
C ... CC...C CC...C ...
中间那些全都合法
我们可以对于后缀 C，往后二分出 CC 的区间，然后就是 C 的答案。
并且注意判断是否存在 CCC，存在要去掉。
哈？完啦？就这？
怪，分段走上。
错啦错啦，我们找到的是 C 的贡献区间。
所以变成了 区间修改+单点查询 问题，bit 维护。
二分在 rk 上执行，用 sa 定位。
暂时不写了，想看一下另外的题目。
 */
#include<bits/stdc++.h>
namespace IO{
    #define _fre_(file,in,out) { \
        if(in) freopen(file".in","r",stdin); \
        if(out) freopen(file".out","w",stdout); \
    }
    void read(int &x){
        x=0;bool sign=false;char ch=getchar();
        for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') sign=true;
        for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+(sign?-(ch&15):(ch&15));
    }
}
template<typename ...Args>
void read(Args &&...args){(void)(std::initializer_list<int>{(IO::read(args),0)...});}
namespace MAIN{
    constexpr int N=1e5+5;
    using ull=unsigned long long;
    char s[N];
    int n;
    template<char *s,ull MOD,ull P>
    struct Hash_Table{
        ull hash[N],pw[N];
        void init(int n){
            hash[0]=0,pw[0]=1;
            for(int i=1;i<=n;++i) hash[i]=(hash[i-1]*P+s[i])%MOD,pw[i]=pw[i-1]*P%MOD;
        }
        ull calc(int l,int r){return (hash[r]+MOD-hash[l-1]*pw[r-l+1]%MOD)%MOD;}
        ull merge(int l1,int r1,int l2,int r2){return (calc(l1,r1)*pw[r2-l2+1]+calc(l2,r2))%MOD;}
        bool is_same(int l1,int r1,int l2,int r2){return calc(l1,r1)==calc(l2,r2);}
    };
    Hash_Table<s,998244353,131> h1;
    Hash_Table<s,1000000007,171> h2;
    bool is_same(int l1,int r1,int l2,int r2){return h1.is_same(l1,r1,l2,r2)&&h2.is_same(l1,r1,l2,r2);}
    namespace solve1{
        void _main_(){
            for(int i=1;i<=n;++i){
                int len=(n-i+1)/3,ans=0;
                if(len*3==n-i+1) --len;
                for(int j=1;j<=len;++j){
                    int a=i,b=i+j-1,c=i+j+j-1,d=n-j+1;
                    assert(a<=b&&b<=c&&c<d);
                    if(is_same(a,b,b+1,c)&&is_same(b+1,c,d,n)) ++ans;
                }
                std::printf("%d ",ans);
            }
            return;
        }
    }
    namespace solve2{
        int sa[N],rk[N];//sa[i]:i's rk.   rk[i]:rk i is who.
        void _main_(){
            for(int i=1;i<=n;++i) rk[i]=i;
            std::sort(rk+1,rk+n+1,[](int x,int y){
                int l=1,r=n-std::max(x,y)+1;
                if(y<x&&is_same(x,n,y,y+(n-x+1)-1)) return true;
                else if(x<y&&is_same(x,x+(n-y+1)-1,y,n)) return false;
                for(int mid;l<r;){
                    mid=(l+r+1)>>1;
                    if(!is_same(x,x+mid-1,y,y+mid-1)) r=mid-1;
                    else l=mid;
                }
                assert(l<=n-std::max(x,y)+1);
                return s[x+l-1]<s[y+l-1];
            });
            for(int i=1;i<=n;++i) sa[rk[i]]=i;
            for(int i=1;i<=n;++i){
            }
            // for(int i=1;i<=n;++i) std::printf("%d ",rk[i]);
            return;
        }
    }
    void _main_(){
        std::scanf("%s",s+1),n=std::strlen(s+1);
        h1.init(n),h2.init(n);
        // solve2::_main_();
        if(n<=1000) return solve1::_main_();
        else return solve2::_main_();
        return;
    }
}
signed main(){
    _fre_("ccfc",1,1);
    return MAIN::_main_(),0;
}