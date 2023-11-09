/* 
a[i]>=b[i]，则要求当 b[i][k] 为 1，a[i][k] 必须为 1 或前面冤大头。
a[i]&a[j]=0，则要求不存在 i,j,k 使得 a[i][k]=a[j][k]=1。
最小化，那么我们尽量能 0 则 0。
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
    constexpr int N=1e6+5;
    int n,m;
    std::vector<int> ap[N];
    int ans[N]={};
    void output(){ for(int i=m;i;--i) std::putchar(ans[i]|48);}
    namespace solve1{
        void _main_(){
            if(n==1){
                for(int it:ap[1]) ans[it]=1;
                return output();
            }
            std::vector<int> v[3]={},c[3]={};
            for(int t:{1,2}){
                v[t].resize(m+1,0),c[t].resize(m+1,0);
                for(int it:ap[t]) v[t][it]=1;
            }
            int ok[3]={};
            for(int i=m;i;--i){
                static int sta[N],top;
                static auto run=[&](int t,int i){
                    for(;top;--top) if(!ans[sta[top]]) break;
                    if(!top) std::puts("-1"),std::exit(0);
                    i=sta[top--],ans[i]=c[t][i]=ok[i]=1;
                };
                for(int t:{1,2}) if(!ok[t]) c[t][i]=v[t][i];
                if(c[1][i]&&c[2][i]) run((ok[1]?2:1),i);
                if(!(ans[i]=c[1][i]|c[2][i])) sta[++top]=i;
            }
            return output();
        }
    }
    namespace solve2{
        void _main_(){
            std::vector<std::vector<int>> v={},c={},st={};
            v.resize(n+1,std::vector<int>(m+1,0));
            c.resize(n+1,std::vector<int>(m+1,0));
            st.resize(n+1);
            for(int t=1;t<=n;++t)
                for(int it:(st[t]=ap[t])) v[t][it]=1;
            static int ok[N]={};
            for(int i=m;i;--i){
                static int sta[N],top;
                static auto check=[&](int i){
                    bool found=false;
                    for(int t=1;t<=n;++t){
                        if(found&&c[t][i]) return false;
                        found|=c[t][i];
                    }
                    return true;
                };
                static auto find=[&](){
                    int t=1;
                    for(int q=2;q<=n;++q)
                        if(!ok[q]&&(ok[t]||(st[t].empty()||(!st[q].empty()&&st[q].back()>st[t].back())))) t=q;
                    return t;
                };
                static auto work=[&](int i){
                    for(int t=1;t<=n;++t){
                        assert(st[t].empty()||st[t].back()<=i);
                        if(!st[t].empty()&&st[t].back()==i) st[t].pop_back();
                        assert(st[t].empty()||st[t].back()<i);
                    }
                };
                static auto run=[&](int t,int i){
                    for(;top;--top) if(!ans[sta[top]]) break;
                    if(!top) std::puts("-1"),std::exit(0);
                    i=sta[top--],ans[i]=c[t][i]=ok[i]=1;
                };
                static auto calc=[&](int i){
                    for(int t=1;t<=n;++t) if(c[t][i]) return 1;
                    return 0;
                };
                for(int t=1;t<=n;++t) if(!ok[t]) c[t][i]=v[t][i];
                if(!check(i)) run(find(),i);
                if(!(ans[i]=calc(i))) sta[++top]=i;
                work(i);
            }
            return output();
        }
    }
    void _main_(){
        read(n,m);
        for(int i=1,k;i<=n;++i){
            read(k),ap[i].reserve(k);
            for(int x;k--;) read(x),ap[i].emplace_back(x);
        }
        if(n<=2) return solve1::_main_();
        else if(1ll*n*m<=1000000ll) return solve2::_main_();
        return;
    }
}
signed main(){
    _fre_("match",1,1);
    return MAIN::_main_(),0;
}