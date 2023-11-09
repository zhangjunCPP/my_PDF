#include<bits/stdc++.h>
#define  Int  long long int
#define  Pub  public
using std::min;using std::max;
const Int mod=1000000007;

Int qpow(Int a,int b){
    Int A=1;
    for(b;b;b>>=1){
        if(b&1)A=A*a%mod;
        a=a*a%mod;
    }
    return A;
}

int T,n,m;
Int cnt;
class Edge{
Pub:int to,next;
    Int diff,same;
}e[205];int cntE;
class Node{
Pub:int fir,fa;
    Int dp;
}p[105];
void addEdge(int x,int y,Int d,Int s){
    e[++cntE]=(Edge){y,p[x].fir,d,s};
    p[x].fir=cntE;
}

namespace ty{
    Int ans;
    int a[105];
    void add(){
        Int A=1;
        for(int x=1;x<=n;++x){
            for(int i=p[x].fir;i;i=e[i].next){
                int y=e[i].to;
                if(x<y){
                    if(a[x]==a[y])A=A*e[i].same%mod;
                    else A=A*e[i].diff%mod;
                }
            }
        }
        ans=(ans+A)%mod;
    }
    void dfs(int c){
        if(c>n){
            add();
            return;
        }
        for(int i=1;i<=cnt;++i){
            a[c]=i;
            dfs(c+1);
        }
    }
    Int calc(){
        ans=0;
        dfs(1);
        return ans;
    }
}
namespace Endt{
    Int ans;
    void dfs(int x){
        p[x].dp=1;
        for(int i=p[x].fir;i;i=e[i].next){
            int y=e[i].to;
            if(y==p[x].fa)continue;
            else{
                p[y].fa=x;
                dfs(y);
                p[x].dp=p[x].dp*((p[y].dp*(cnt-1)%mod*e[i].diff%mod)*(p[y].dp*e[i].same%mod)%mod)%mod;
            }
        }
    }
    Int calc(){
        dfs(1);
        return p[1].dp*cnt%mod;
    }
}

int main(){
    freopen("trans.in","r",stdin);
    freopen("trans.out","w",stdout);
    
    for(scanf("%d",&T);T;--T){
        scanf("%d%d%lld",&n,&m,&cnt);
        for(int i=1,x,y;i<=m;++i){
            Int d,s;
            scanf("%d%d%lld%lld",&x,&y,&d,&s);
            addEdge(x,y,d,s),addEdge(y,x,d,s);
        }
        Int ans=0;
        if(n<=12)ans=(ans+ty::calc())%mod;
        else if(m==n-1)ans=(ans+Endt::calc())%mod;
        else while(1);
        printf("%lld\n",ans);
        
        cntE=0;
        for(int i=1;i<=n;++i)p[i].fir=p[i].fa=0;
    }
    return 0;
}
