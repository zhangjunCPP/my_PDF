/*
t4
继续骗
23pts 
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll re(){
    ll x=0;
    char c=getchar();
    while(c<48||c>57)c=getchar();
    while(c>47&&c<58)x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x;
}
void wr(ll x){
    if(x>9)wr(x/10);
    putchar(x%10|48);
}
const ll N=300,mod=65535;
ll n,ans,s,cn;
struct B{
	ll x,y;
}num[N];
ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
unordered_map<ll,bool>vis;
ll chos;
void dfs(ll now){
//	printf("dfs:%lld\n",now);
	if(now>n){
//		if(!vis.count(chos)){
//			printf("chos=%lld s=%lld\n",chos,s);
			ans=ans*s%mod;
//			vis[chos]=1;
//		}
		return;
	}
	for(ll i=1;i<=cn;++i){
		int numy=num[i].y;
		if(num[i].y){
			chos=chos*(cn+1)+i;
			s=(s+qpow(256ll,n-now)*num[i].x%mod)%mod;
			--num[i].y;
			while(numy){
				dfs(now+1);
				--numy;
			}
			s=(s-qpow(256ll,n-now)*num[i].x%mod+mod)%mod;
			++num[i].y;
			chos/=cn+1;
		}
	}
}
ll k,i,x,y;
inline void work(){
//	vis.clear();
	cn=n=0;
	ans=1;
	k=re();//重名警告 
	for(i=1;i<=k;++i){
		x=re();
		y=re();
		num[++cn]={x,y};
		n+=y;
	}
	s=chos=0;
	dfs(1);
	wr(ans);
	putchar(10);
}
ll T;
int main(){
	freopen("secret.in","r",stdin);
	freopen("secret.out","w",stdout);
	T=re();
	while(T--)work();
	return 0;
}
/*
1
1
239 2
*/

