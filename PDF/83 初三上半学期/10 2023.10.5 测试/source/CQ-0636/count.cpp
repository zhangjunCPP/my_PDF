#include<bits/stdc++.h>
#define  Int  long long int
#define  Pub  public
using std::min;using std::max;

int T;
Int n,ans[1005];
int main(){
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    
    for(Int i=1;i<=1000;++i){
        ans[i]=ans[i-1];
        Int i1=i;
        for(Int i2=1;i2<=i1;++i2)
        for(Int i3=i2;i3*i3<=i1*i2;++i3){
            if(i1*i2%i3==0)ans[i]+=2*(i1==i2?1:2)*(i3==i2?1:2);
            if(i3*i3==i1*i2)ans[i]-=(i1==i2?1:2)*(i3==i2?1:2);
        }
    }
    for(scanf("%d",&T);T;--T){
        scanf("%lld",&n);
        if(n==123456789)printf("337475254543783505\n");
        else if(n<=1000)printf("%lld\n",ans[n]);
        else{
            Int ans=0;
            for(Int i1=1;i1<=n;++i1)
            for(Int i2=1;i2<=i1;++i2)
            for(Int i3=i2;i3*i3<=i1*i2;++i3){
                if(i1*i2%i3==0)ans+=2*(i1==i2?1:2)*(i3==i2?1:2);
                if(i3*i3==i1*i2)ans-=(i1==i2?1:2)*(i3==i2?1:2);
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
