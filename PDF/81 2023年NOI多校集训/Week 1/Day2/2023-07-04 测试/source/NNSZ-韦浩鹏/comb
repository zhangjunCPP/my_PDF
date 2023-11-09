#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
int a[N], ans, n;
void solve(int x, int y, int z, int w, int now, int k){
    if(w){
        ans=max(ans, k);
        solve(0, 0, 0, 0, now, k);
        return ;
    }
    if(!x){
        for(int i=now;i+3<=n;++i)
            solve(a[i], y, z, w, i+1, k);
    }else if(!y){
        for(int i=now;i+2<=n;++i)
            solve(x, a[i], z, w, i+1, k);
    }else if(!z){
        for(int i=now;i+1<=n;++i)
            if(a[i]==x) solve(x, y, x, w, i+1, k);
    }else{
        for(int i=now;i<=n;++i)
            if(a[i]==y) solve(x, y, x, y, now+1, k+1);
    }
}
int main(){
    freopen("comb.in", "r", stdin);
    freopen("comb.out", "w", stdout);
    scanf("%d", &n);
    for(int i=1;i<=n;++i)
        scanf("%d", &a[i]);
    solve(0, 0, 0, 0, 1, 0);
    printf("%d", 4*ans);
    return 0;
}
