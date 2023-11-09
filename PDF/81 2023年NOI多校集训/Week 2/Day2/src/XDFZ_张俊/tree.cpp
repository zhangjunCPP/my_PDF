#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod=1e9+7;
const int N=1e6+10;
struct node{
    int v,nex;
}a[N*2];
int first[N],cnt;
void add(int u,int v){
    a[++cnt]={v,first[u]};
    first[u]=cnt;
}

int qpow(int x,int y){
    int ans=1;
    while (y){
        if(y&1) ans=(ans*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return ans%mod;
}

int n;

/*第一档*/

int dis[105][105];
bool f[105][105];
int tmp[105];
int ans=0;
void bf1(int x){
    if(x>n){
        int MAX=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j&&tmp[i]==tmp[j]){
                   MAX=max(MAX,dis[i][j]);
                }
            }
        }
        ans=(ans+MAX)%mod;
        return;
    }
    tmp[x]=1;
    bf1(x+1);
    tmp[x]=0;
    bf1(x+1);
    return;
}


signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    if(n<=10){
        memset(dis,0x3f,sizeof dis);
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            dis[u][v]=dis[v][u]=1;
        }
        for(int i=1;i<=n;i++)dis[i][i]=0;
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);

                }
            }
        }
        bf1(1);
        cout<<ans;
        return 0;
    }
}