#include<bits/stdc++.h>
#define  Int  long long int
#define  Pub  public
using std::min;using std::max;

int n,m,k[1000005],id[1000005];
std::vector<int> p[1000005],ans;
int t[1000005],bit;

bool cmp(int x,int y){
    for(int i=k[x]-1,j=k[y]-1;;--i,--j){
        while(i>=0&&p[x][i]>bit)--i;
        while(j>=0&&p[y][j]>bit)--j;
        if(i<0||j<0)return i<=j;
        if(p[x][i]!=p[y][i])return p[x][i]<p[y][i];
    }
}

int main(){
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        id[i]=i;
        scanf("%d",&k[i]);
        for(int j=0,x;j<k[i];++j){
            scanf("%d",&x);
            p[i].emplace_back(x);
        }
    }
    
    for(bit=m;bit>=1;--bit){
        std::sort(id+1,id+n+1,cmp);
        bool flag=1;
        for(int I=1,i;I<=n;++I){
            i=id[I];
            for(int j=k[i]-1;j>=0;--j){
                while(j>=0&&p[i][j]>bit)--j;
                if(j<0)break;
                int A=p[i][j];
                if(A==bit)flag=0;
                if(t[A]){
                    while(t[A])++A;
                    if(A>bit){
                        printf("-1");
                        return 0;
                    }
                    t[A]=1;
                    break;
                }else t[A]=1;
            }
        }
        if(t[bit]){
            ans.emplace_back(1);
            if(flag)k[id[n]]=0,p[id[n]].clear();
        }else ans.emplace_back(0);
        for(int i=1;i<=bit;++i)t[i]=0;
    }
    for(int i:ans)printf("%d",i);
    return 0;
}
