#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7+10;
int n,mod;
int dp[N];
int jc[N];
int qpow(int x,int y){
    int ans=1;
    while(y){
        if(y&1) ans=(ans*x)%mod;
        y>>=1;
        x=(x*x)%mod;
    }
    return ans%mod;
}
int inv(int x){
    return qpow(x,mod-2)%mod;
}
signed  main(){
    freopen("perm.in","r",stdin);
    freopen("perm.out","w",stdout);
    cin>>n>>mod;
    int inv2=inv(2)%mod;
    jc[0]=1;
    for(int i=1;i<=n;i++) jc[i]=(jc[i-1]*i)%mod;
    dp[1]=dp[2]=0;
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-1]%mod+dp[i-2]%mod*(i-1)%mod+(((jc[i-2]%mod*(i-1)%mod)%mod)*(((i-2)%mod*inv2%mod)%mod))%mod)%mod;
    }
    int ans=dp[1];
    for(int i=2;i<=n;i++){
        ans=(ans^dp[i])%mod;
    }
    cout<<(ans)%mod;
}
