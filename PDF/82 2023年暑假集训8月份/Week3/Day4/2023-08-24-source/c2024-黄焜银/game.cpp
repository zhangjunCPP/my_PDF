/*
t2
�÷�˿����˾����ܶ���һЩ��

�ܵı����������̶�
���ٿ���һ��������
���ֻ�ܴ�n-1��

����ƭ50�� 

ͨ������3��������ԼԼ�ᵽ��һ˿�����ζ������ 
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
	/*��������ԽС����˿Խ��������������С�ĳ�*/
	wr(n*(n-1)>>1);putchar(10);
	for(i=n;i;--i)wr(i),putchar(32);
}
inline void subtask2(){
	/*����Խ�󣬷�˿Խ�࣬��1�������ĳ��꼴��*/
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
	/*n<=9����ö����*/
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


