#include <cstdio>
#include <initializer_list>
#include <bitset>
constexpr int N=2010;
int Ch,ans,a[N],v[N],p,k,n;
std::bitset<N>f[N];
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
template<typename...Ar>
inline void r(Ar&&...x){std::initializer_list<int>{(r(x),0)...};}
template<typename T>
void w(T&&x){
	if(9<x)w(x/10);
	putchar(x%10|48);
}
void BF(const int&x){
    if(x>p){
        ans++;
        int i;
        for(i=1;i<x;i++)f[ans].set(a[i]);
        for(i=1;i<ans;i++){
            if((f[ans]&f[i]).count()>1){
                f[ans--].reset();
                break;
            }
        }
    }
    for(int i=a[x-1]+1;i<n;i++)
        if(!v[i]){
            a[x]=i;
            v[i]=true;
            BF(x+1);
            v[i]=false;
        }
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
    r(p,k);
    n=1;
	*a=-1;
    int i=k,j;
    while(i--)n*=p;
    if(p==2){
        w(n*(n-1)>>1);
        for(i=1;i<n;i++){
            for(j=i+1;j<=n;j++){
                putchar(10);
                w(i);
                putchar(32);
                w(j);
            }
        }
        return 0;
    }
    BF(1);
    w(ans);
    for(i=1;i<=ans;i++){
        putchar(10);
        for(j=0;j<n;j++){
            if(f[i][j]){
                w(j);
                putchar(32);
            }
        }
    }
	return 0;
}