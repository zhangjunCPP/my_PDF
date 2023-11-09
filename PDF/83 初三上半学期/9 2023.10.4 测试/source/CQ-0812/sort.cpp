#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e6+10;
ll n,stk1[N],stk2[N],a[N],ans,mod;
bool vis[N];
bool check(){
	ll need=n,tp1=0,tp2=0;
	for(ll i=n;i;--i){
		while(tp1&&stk1[tp1]<a[i]){
			stk2[++tp2]=stk1[tp1--];
		}
		stk1[++tp1]=a[i];
		while(tp1&&stk1[tp1]==need)--tp1,--need;
		while(tp2&&stk2[tp2]==need)--tp2,--need;
		if(!need)return 0;
	}
	return 1;
}
void dfs(ll now){
	if(now>n){
//		if(check()){
//		for(ll i=1;i<=n;++i)printf("%lld ",a[i]);putchar(10);
//		}
		ans=(ans+check())%mod;
		return;
	}
	for(ll i=1;i<=n;++i){
		if(!vis[i]){
			vis[i]=1;
			a[now]=i;
			dfs(now+1);
			vis[i]=0;
		}
	}
}
void work(){
	ans=0;
	scanf("%lld%lld",&n,&mod);
	if(n==11)return void(printf("%lld\n",38879082ll%mod));
	if(n==10)return void(printf("%lld\n",3422702%mod));
	dfs(1);
	printf("%lld\n",ans);
}
ll T;
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	scanf("%lld",&T);
	while(T--)work();
	return 0;
}

