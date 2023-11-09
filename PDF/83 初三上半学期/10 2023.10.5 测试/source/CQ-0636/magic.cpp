#include<bits/stdc++.h>
#define  Int  long long int
#define  Pub  public
using std::min;using std::max;

int n;
Int ans;
class Ball{
Pub:int id,l,r;
    Int c,t;
    bool f;
}a[1005];
bool operator <(Ball x,Ball y){
    if(x.t!=y.t)return x.t>y.t;
    else return x.id<y.id;
}
std::set<Ball> s;

int main(){
    freopen("magic.in","r",stdin);
    freopen("magic.out","w",stdout);
    
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d%d%lld",&a[i].l,&a[i].r,&a[i].c);
        a[i].id=i;
        for(int j=a[i].l;j<=a[i].r;++j)
            if(j!=i)a[i].t+=a[i].c;
        s.emplace(a[i]);
    }
    
    while(s.begin()->t>0){
        int x=s.begin()->id;
        ans+=a[x].t;
        s.erase(a[x]);
        a[x].f=1,a[x].t=0;
        s.emplace(a[x]);
        for(int i=a[x].l;i<=a[x].r;++i){
            if(i!=x&&a[i].f){
                s.erase(a[i]);
                a[i].t+=a[x].c;
                s.emplace(a[i]);
            }
        }
        for(int i=1;i<=n;++i){
            if(i!=x&&a[i].l<=x&&x<=a[i].r){
                s.erase(a[i]);
                a[i].t-=a[i].c;
                s.emplace(a[i]);
            }
        }
    }
    
    printf("%lld",ans);
    return 0;
}
