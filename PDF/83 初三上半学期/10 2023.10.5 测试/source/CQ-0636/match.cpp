#include<bits/stdc++.h>
#define  Int  long long int
#define  Pub  public
using std::min;using std::max;

int T,n,m;
int d[1000005],fa[1000005],size[1000005],ring[1000005];
int FA(int x){
    if(fa[x]!=x)fa[x]=FA(fa[x]);
    return fa[x];
}

int main(){
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    
    for(scanf("%d",&T);T;--T){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i)
            d[i]=0,fa[i]=i,size[i]=1,ring[i]=0;
        for(int i=1,x,y;i<=m;++i){
            scanf("%d%d",&x,&y);
            ++d[x],++d[y];
            x=FA(x),y=FA(y);
            if(x!=y)fa[x]=y,size[y]+=size[x];
            else ring[y]=1;
        }
        int ans=0;
        for(int i=1;i<=n;++i)ans=max(ans,d[i]);
        if(ans<3)for(int i=1;i<=n;++i)
            if(size[i]==3&&ring[i])ans=3;
        printf("%d\n",ans);
    }
    return 0;
}
