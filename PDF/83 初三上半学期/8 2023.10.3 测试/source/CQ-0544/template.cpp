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
    void _main_(){
        return;
    }
}
signed main(){
    _fre_("",0,0);
    return MAIN::_main_(),0;
}