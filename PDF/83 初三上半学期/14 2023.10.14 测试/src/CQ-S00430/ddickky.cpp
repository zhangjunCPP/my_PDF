#include<bits/stdc++.h>
#define  Int  long long int
#define  Pub  public
using std::min;using std::max;
const Int mod=998244353,T=450;
Int qpow(Int a,Int b){
    Int A=1;
    for(b;b;b>>=1){
        if(b&1)A=A*a%mod;
        a=a*a%mod;
    }
    return A;
}

int n,m;
class Q{
Pub:int l,r,id;
    Int ans;
}q[200005];
bool operator <(Q x,Q y){
    if(x.l/T!=y.l/T)return x.l/T<y.l/T;
    else if((x.l/T)&1)return x.r<y.r;
    else return x.r>y.r;
}

Int a[200005],sum[200005][225],cnt[200005];
std::vector<Int> POW[200005],WOP[200005];
int notp[455],cntp;
Int p[225];

int main(){
    freopen("ddickky.in","r",stdin);
    freopen("ddickky.out","w",stdout);
    
    for(Int i=2;i<=T;++i){
        if(!notp[i]){
            for(Int j=1;i*j<=T;++j)notp[i*j]=1;
            for(Int j=i;j<=200000;j*=i)p[++cntp]=i;
        }
    }
    
    Int ans=1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
        for(int j=1;j<=cntp;++j){
            if(a[i]%p[j]==0){
                ++sum[i][j];
                a[i]/=p[j];
            }
        }
        if(a[i]!=1){
            Int t=qpow(a[i],qpow(2,cnt[a[i]]));
            ans=ans*t%mod;
            POW[a[i]].emplace_back(t);
            WOP[a[i]].emplace_back(qpow(t,mod-2));
            ++cnt[a[i]];
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=cntp;++j)
            sum[i][j]+=sum[i-1][j];
    
    for(int i=1;i<=m;++i){
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].id=i,q[i].ans=1;
        for(int j=1;j<=cntp;++j)
            q[i].ans=q[i].ans*qpow(p[j],qpow(2,sum[q[i].r][j]-sum[q[i].l-1][j])-1)%mod;
    }
    std::sort(q+1,q+m+1);
    int L=1,R=n;
    for(int i=1;i<=m;++i){
        while(L>q[i].l){
            --L;
            if(a[L]!=1){
                ans=ans*POW[a[L]][cnt[a[L]]]%mod;
                ++cnt[a[L]];
            }
        }
        while(R<q[i].r){
            ++R;
            if(a[R]!=1){
                ans=ans*POW[a[R]][cnt[a[R]]]%mod;
                ++cnt[a[R]];
            }
        }
        while(L<q[i].l){
            if(a[L]!=1){
                --cnt[a[L]];
                ans=ans*WOP[a[L]][cnt[a[L]]]%mod;
            }
            ++L;
        }
        while(R>q[i].r){
            if(a[R]!=1){
                --cnt[a[R]];
                ans=ans*WOP[a[R]][cnt[a[R]]]%mod;
            }
            --R;
        }
        q[i].ans=q[i].ans*ans%mod;
    }
    
    std::sort(q+1,q+m+1,[](Q x,Q y)->bool{return x.id<y.id;});
    for(int i=1;i<=m;++i)
        printf("%lld\n",q[i].ans);
    
    return 0;
}
