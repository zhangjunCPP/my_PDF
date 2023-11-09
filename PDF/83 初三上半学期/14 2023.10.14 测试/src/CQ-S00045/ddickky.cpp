#include<bits/stdc++.h>
template<typename T> void _(T &x){
	x=0; bool f=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	if(f) x=-x;
}
#define int long long
const int N=2e5+5;
const int p=998244353;
int gcd(int a,int b){ return b?gcd(b,a%b):a; }
int n,q,a[N];
int l,r,ans;
void dfs(int step,int g){
	if(g==1) return ;
	if(step>r){
		if(g!=-1) ans=ans*g%p;
		return ;
	}
	dfs(step+1,g);
	if(g==-1) dfs(step+1,a[step]);
	else dfs(step+1,gcd(g,a[step]));
}
signed main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	_(n),_(q);
	for(int i=1;i<=n;i++) _(a[i]);
	while(q--){
		_(l),_(r),ans=1;
		dfs(l,-1);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
3 1
2 4 3
1 3

5 2
8 2 8 8 9
1 5
2 4
*/
