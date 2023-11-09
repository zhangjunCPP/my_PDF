#include<bits/stdc++.h>
using namespace std;
namespace my_IO{
    #define ll long long
    #define ull unsigned long long
    #define ld long double
    template<class T>
    void read(T &num){
        T x=0,f=1;
        char c=getchar();
        while(!isdigit(c)){
            if(c=='-') f=-1;
            c=getchar();
        }
        while(isdigit(c)){
            x=(x<<3)+(x<<1)+c-48;
            c=getchar();
        }
        num=f*x;
    }
    template<class T>
    void write(T x){
        static char buf[40];
        static int len=-1;
        if(x<0) putchar('-'),x=-x;
        do{
            buf[++len]=x%10+48;
            x/=10;
        }while(x);
        while(len>=0) putchar(buf[len--]);
    }
}
using namespace my_IO;
const ll maxn=1e7+10;
ll n,mod,f[maxn],fi[maxn],ans;
void solve(){
    read(n),read(mod);
    fi[0]=1;
    for(ll i=1;i<=n;i++) fi[i]=fi[i-1]*i%mod;
    for(ll i=3;i<=n;i++){
        f[i]=(f[i-1]+(i-1)*f[i-2]%mod)%mod;
        for(ll j=2;j<=i;j++) f[i]=(f[i]+(i-j)*fi[i-2]%mod)%mod;
    }
    for(ll i=1;i<=n;i++) ans^=f[i];
    write(ans);
}
int main(){
    freopen("perm.in","r",stdin);
    freopen("perm.out","w",stdout);
    int t=1;
    while(t--) solve();
}