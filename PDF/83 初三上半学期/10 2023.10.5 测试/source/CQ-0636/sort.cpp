#include<bits/stdc++.h>
#define  Int  long long int
#define  Pub  public
using std::min;using std::max;

int n,a[700005],b[700005];
Int ans;

void Sort(int l,int r){
    if(l>=r)return;
    else ans+=r-l+1;
    int p=a[(l+r)/2],q,cnt=0;
    for(int i=l;i<=r;++i)
        if(a[i]<p)b[l+cnt]=a[i],++cnt;
    b[q=l+cnt]=p,++cnt;
    for(int i=l;i<=r;++i)
        if(a[i]>p)b[l+cnt]=a[i],++cnt;
    for(int i=l;i<=r;++i)a[i]=b[i];
    Sort(l,q-1),Sort(q+1,r);
}

int main(){
    freopen("sort.in","r",stdin);
    freopen("sort.out","w",stdout);
    
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    Sort(1,n);
    printf("%lld",ans);
    return 0;
}
