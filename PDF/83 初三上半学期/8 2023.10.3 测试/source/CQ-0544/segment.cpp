/* 
猜测是二分或dp
上一个极差写树上dp的已经变成65pts了，那么猜测是二分
若 d1 可行，则 d2>d1 亦可行？
若最小是两个，那么可以拆开变得更小；若最大是一个，可以接上变大。
那么若最大是合并，而最小是单个，d2>d1 是否可行？
好像极差不能变大了，这是一个上界，下界不确定。
即上界：和最大的两个数减去值最小的数，不存在值最小的被包含在内，除非 n=2（此时答案为 0）。
那么在上界以下，都可以把和换大或者最小值弄小，单调性有了。
考虑 check，发现不好做。
贪心地想，肯定最小的要和旁边的合并，以此变大。
不妨：a,b,c 中 b 是最小的，且 a>c，则 b,c 合并？
不一定，也可能存在：a,b,c,d 且 a>c 而 c+d>a，然后 a,b 合并，c,d 合并。
考虑反悔贪心一类的东西，我 a,b,c,d -> a,b+c,d，此时有 c+d>a,a>c -> ...也不好做。
那么考虑一下 corner？不好弄，南蚌。
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
void read(Args &...args){(void)(std::initializer_list<int>{(IO::read(args),0)...});}
namespace MAIN{
    constexpr int N=2e5+5;
    int n,a[N];
    bool used[N];
    int tmp[N];
    namespace solve1{
        bool alive[N];
        int ans=0x3f3f3f3f;
        void dfs(int p,int mi,int ma){
            if(ans==0) return;
            if(p==n+1){
                ans=std::min(ans,ma-mi);
                return;
            }
            dfs(p+1,std::min(mi,a[p]),std::max(ma,a[p]));
            if(p<n) dfs(p+2,std::min(mi,a[p]+a[p+1]),std::max(ma,a[p]+a[p+1]));
        }
        void _main_(){
            dfs(1,0x3f3f3f3f,0);
            std::printf("%d",ans);
        }
    }
    namespace solve2{
        bool pre_check(){
            for(int i=1;i<=n;++i) if(a[i]>10) return false;
            return true;
        }
        bool check(int mi,int ma){
            for(int i=1;i<=n;++i){
                if(used[i]) continue;
                if(tmp[i]<mi){
                    if(i!=1&&!used[i-1]&&tmp[i]+tmp[i-1]>=mi&&tmp[i]+tmp[i-1]<=ma){
                        used[i-1]=used[i]=true;
                        tmp[i]+=tmp[i-1];
                    }
                    else if(i!=n){
                        tmp[i]+=tmp[i+1];
                        used[i]=used[i+1]=true;
                    }
                    else return false;
                }
                if(tmp[i]<mi) return false;
                else if(tmp[i]>ma) return false;
            }
            return true;
        }
        void _main_(){
            for(int d=0;d<=100;++d){
                bool flag=false;
                for(int mi=1;mi<=100&&!flag;++mi){
                    for(int i=1;i<=n;++i) used[i]=0,tmp[i]=a[i];
                    flag|=check(mi,mi+d);
                }
                if(flag) return std::printf("%d",d),void();
            }
            return;
        }
    }
    namespace solve3{
        bool check(int mi,int ma){return solve2::check(mi,ma);}
        void _main_(){
            int ans=0x3f3f3f3f;
            for(int i=1;i<n;++i){
                int ma=a[i]+a[i+1];
                for(int j=1;j<=n;++j)
                    if((j!=i)&&(j!=i+1)&&(a[j]<=ma)&&(ma-a[j]<=ans)){
                        for(int i=1;i<=n;++i) used[i]=0,tmp[i]=a[i];
                        used[i]=used[i+1]=used[j]=1;
                        if(check(a[j],ma)) ans=ma-a[j];
                    }
            }
            for(int i=1;i<n;++i){
                int ma=a[i]+a[i+1];
                for(int j=1;j<n;++j)
                    if((j!=i)&&(j!=i+1)&&(j+1!=i)&&(a[j]+a[j+1]<=ma)&&(ma-(a[j]+a[j+1])<=ans)){
                        for(int i=1;i<=n;++i) used[i]=0,tmp[i]=a[i];
                        used[i]=used[i+1]=used[j]=used[j+1]=1;
                        if(check(a[j]+a[j+1],ma)) ans=ma-(a[j]+a[j+1]);
                    }
            }
            for(int i=1;i<=n;++i){
                int ma=a[i];
                for(int j=1;j<n;++j)
                    if((j!=i)&&(j+1!=i)&&(a[j]+a[j+1]<=ma)&&(ma-(a[j]+a[j+1])<=ans)){
                        for(int i=1;i<=n;++i) used[i]=0,tmp[i]=a[i];
                        used[i]=used[j]=used[j+1]=1;
                        if(check(a[j]+a[j+1],ma)) ans=ma-(a[j]+a[j+1]);
                    }
            }
            for(int i=1;i<=n;++i){
                int ma=a[i];
                for(int j=1;j<=n;++j)
                    if((j!=i)&&(a[j]<=ma)&&(ma-a[j]<=ans)){
                        for(int i=1;i<=n;++i) used[i]=0,tmp[i]=a[i];
                        used[i]=used[j]=1;
                        if(check(a[j],ma)) ans=ma-a[j];
                    }
            }
            std::printf("%d",ans);
            return;
        }
    }
    void _main_(){
        read(n);
        for(int i=1;i<=n;++i) read(a[i]);
        if(n<=2) return std::putchar('0'),void();
        if(n<=18) return solve1::_main_();
        else if(solve2::pre_check()) return solve2::_main_();
        else return solve3::_main_();
        return;
    }
}
signed main(){
    _fre_("segment",1,1);
    return MAIN::_main_(),0;
}