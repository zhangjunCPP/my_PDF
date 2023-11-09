#include<bits/stdc++.h>
#define  Int  long long int
#define  Pub  public
using std::min;using std::max;
const int SuperBig=2000000005;

int n,a[200005],ans=SuperBig;
int dp[200005][2];
void DP(int m){
    for(int i=1;i<=n;++i)dp[i][0]=dp[i][1]=SuperBig;
    if(a[1]>=m)dp[1][0]=a[1];
    for(int i=2;i<=n;++i){
        if(a[i-1]+a[i]>=m)dp[i][1]=max(min(dp[i-2][0],dp[i-2][1]),a[i-1]+a[i]);
        if(a[i]>=m)dp[i][0]=max(min(dp[i-1][0],dp[i-1][1]),a[i]);
    }
    ans=min(ans,min(dp[n][0],dp[n][1])-m);
}

int main(){
    freopen("segment.in","r",stdin);
    freopen("segment.out","w",stdout);
    
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    if(n<=2000){
        for(int i=1;i<=n;++i)DP(a[i]);
        for(int i=2;i<=n;++i)DP(a[i]+a[i-1]);
    }else for(int i=1;i<=20;++i)DP(i);
    printf("%d",ans);
    return 0;
}
