#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int a[1000000];
int gcd(int x,int y){
    while(x^=y^=x^=y%=x);
    return y;
}
int lcm(int x,int y){
    x%=mod;
    y%=mod;
    int tmp= gcd(x,y);
    x=x/tmp;
    y=y/tmp;
    return x*y%mod*tmp%mod;
}
signed main(){
    freopen("boring.in","r",stdin);
    freopen("boringbf.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(q--){
        int k;
        cin>>k;
        int tmp=1;
        for(int i=1;i<=k;i++){
            int x,y;
            cin>>x>>y;
            int tmpp=1;
            for(int j=x;j<=y;j++){
                tmpp= lcm(tmpp,a[j])%mod;
            }
            tmp= lcm(tmp,tmpp)%mod;
        }
        cout<<tmp<<"\n";
    }
}