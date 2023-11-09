/*
t2
让粉丝多的人尽可能多打败一些人

总的比赛场数不固定
最少可以一场都不打
最多只能打n-1场

暴力骗50？ 

通过样例3好像隐隐约约嗅到了一丝正解的味道…… 
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+10;
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
ll n,i;
inline void subtask1(){
	/*对于能力越小，粉丝越多的情况，尽量让小的吃*/
	wr(n*(n-1)>>1);putchar(10);
	for(i=n;i;--i)wr(i),putchar(32);
}
inline void subtask2(){
	/*能力越大，粉丝越多，让1把其他的吃完即可*/
	wr(n*(n-1));putchar(10);
	for(i=2;i<=n;++i)wr(i),putchar(32);
	wr(1);
}
ll ans[N],a[N],top,stk[N],mx,s[N];
bool vis[N];
inline void check(){
	ll res=0;
	top=0;
	for(ll i=1;i<=n;++i){
		if(!top){
			stk[++top]=ans[i];
			continue;
		}
		while(top&&stk[top]>ans[i])res+=a[ans[i]],--top;
		stk[++top]=ans[i];
	}
	if(res>mx){
		mx=res;
		memcpy(s,ans,sizeof s);
	}
}
void dfs(ll now){
	if(now>n){
//		for(ll i=1;i<=n;++i)printf("%lld ",ans[i]);putchar(10);
		check();
		return;
	}
	for(ll i=1;i<=n;++i){
		if(!vis[i]){
			vis[i]=1;
			ans[now]=i;
			dfs(now+1);
			vis[i]=0;
		}
	}
}
inline void subtask3(){
	/*n<=9，暴枚即可*/
	dfs(1);
	wr(mx);putchar(10);
	for(i=1;i<=n;++i)wr(s[i]),putchar(32);
}
bool flag1,flag2,flag3;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=re();
	if(n>9)flag3=1;
	for(i=1;i<=n;++i){
		a[i]=re();
		if(a[i]!=i)flag1=1;
		if(a[i]!=n-i+1)flag2=1;
	}
	if(!flag3)subtask3();
	else if(!flag2)subtask2();
	else if(!flag1)subtask1();
	else subtask3();
	return 0;
}


