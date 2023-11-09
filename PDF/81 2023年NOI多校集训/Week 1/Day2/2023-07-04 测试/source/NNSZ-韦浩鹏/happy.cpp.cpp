#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e4+3, INF=0x7fffffff;
int t[N];
struct ticket{
    int num, cost;
} a[510];
bool cmp(ticket x, ticket y){
    if(x.cost==y.cost) return x.num>y.num;
    return x.cost<y.cost;
}
int dp[N][N];
int n, k, one;
int main(){
    freopen("happy.in", "r", stdin);
    freopen("happy.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for(int i=1;i<=n;++i)
        scanf("%d", &t[i]);
    for(int i=1;i<=k;++i)
        scanf("%d%d", &a[i].num, &a[i].cost);
    scanf("%d", &one);
    sort(a+1, a+k+1, cmp);
    for(int i=1;i<=n;++i){
        dp[i][i]=min(one, a[1].cost);
    }
    for(int p=2;p<=n;++p){
        for(int i=1;i+p-1<=n;++i){
            int j=i+p-1;
            dp[i][j]=one*(j-i+1);
            dp[i][j]=min(dp[i][j], dp[i][j-1]+one);
            for(int l=1;l<=k;++l)
                if(a[l].num>=t[j]-t[i]+1){
                    dp[i][j]=min(dp[i][j], a[l].cost);
                    break;
                }
            for(int w=1;w<j-i;++w)
                if(dp[i][i+w]+dp[i+w+1][j]<dp[i][j])
                    dp[i][j]=dp[i][i+w]+dp[i+w+1][j];
        }
    }
    for(int i=1;i<=n;++i)
        printf("%d\n", dp[1][i]-dp[1][i-1]);
    return 0;
}
