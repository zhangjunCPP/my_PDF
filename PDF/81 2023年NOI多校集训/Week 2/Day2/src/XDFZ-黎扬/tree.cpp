#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	char ch=getchar();
	ll f=1,x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void work(ll k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
    putchar(k%10+'0');
}
//n<=10直接暴力
const ll mod=1e9+7;
ll n,cnt,first[1000005],flag,f,dep[1000005],dp[1000005][21],ans;
struct q1{
    ll u,w,nex;
}a[2000005];
void add(ll u1,ll w1){
    a[++cnt]={u1,w1,first[u1]};
    first[u1]=cnt;
}
void dfs(ll u,ll dad){
    dep[u]=dep[dad]+1;
    dp[u][0]=dad;
    for(ll i=1;i<=20;i++){
        dp[u][i]=dp[dp[u][i-1]][i-1];
    }
    for(ll i=first[u];i;i=a[i].nex){
        if(a[i].w==dad)
            continue;
        dfs(a[i].w,u);
    }
}
ll LCA(ll x,ll y){
    if(dep[x]>dep[y])
        swap(x,y);
    for(ll i=20;i>=0;i--){
        if(dep[dp[y][i]]>=dep[x])
            y=dp[y][i];
    }
    if(x==y)
        return x;
    for(ll i=20;i>=0;i--){
        if(dp[x][i]!=dp[y][i]){
            x=dp[x][i];
            y=dp[y][i];
        }
    }
    return dp[x][0];
}
ll power(ll a,ll b){
    ll sum=1,k=a;
    while(b){
        if(b&1ll){
            sum*=k;
            sum%=mod;
        }
        k*=k;
        k%=mod;
        b>>=1ll;
    }
    return sum;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
	n=read();
    for(ll i=1,x,y;i<n;i++){
        x=read();
        y=read();
        add(x,y);
        add(y,x);
        if(x!=i||y!=i+1)
            flag=1;
        if(x!=1&&y!=1)
            f=1;
    }
    dfs(1,0);
    for(ll i=0;i<(1<<n);i++){
        ll sum=0;
        for(ll j=1;j<=n;j++){
            for(ll k=j+1;k<=n;k++){
                if(((i>>(j-1))&1)==((i>>(k-1))&1))
                    sum=max(sum,dep[j]+dep[k]-2*dep[LCA(j,k)]);
            }
        }
        ans+=sum;
        ans%=mod;
    }
    work(ans);
	return 0;
}