#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int MAXN=1e5+10;
int a[MAXN];
int gcd(int x,int y){
    while(x^=y^=x^=y%=x);
    return y;
}
int lcm(int x,int y){
	x%=mod,y%=mod; 
    int tmp= gcd(x,y);
    x=x/tmp;
    y=y/tmp;
    return x*y%mod*tmp%mod;
}
int tree[MAXN*4];
void build(int k,int l,int r){
    if(l==r){
        tree[k]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    tree[k]= lcm(tree[k<<1],tree[k<<1|1])%mod;
}
int query(int k,int l,int r,int x,int y){
    if(x<=l&&y>=r){
        return tree[k];
    }
    int mid=(l+r)>>1;
    int tmp=1;
    if(x<=mid) tmp=lcm(tmp, query(k<<1,l,mid,x,y))%mod;
    if(y>mid) tmp= lcm(tmp, query(k<<1|1,mid+1,r,x,y))%mod;
    return tmp%mod;
}
signed main(){
    freopen("boring.in","r",stdin);
    freopen("boring.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    while(q--){
        int k;
        cin>>k;
        int tmp=1;
        for(int i=1;i<=k;i++){
            int x,y;
            cin>>x>>y;
            int tmpp= query(1,1,n,x,y)%mod;
            tmp= lcm(tmp,tmpp)%mod;
        }
        cout<<tmp%mod<<"\n";
    }
}
