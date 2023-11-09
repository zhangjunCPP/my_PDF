#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int rd(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w; 
}
inline void wr(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)wr(x/10);
	putchar(x%10+'0');
}

inline void FRE(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
}
const int N=2e5+5;
const int mod=998244353;
int n,m,l,r;
int ans;
int a[N];
int f[N][2];
inline void dfs(int pos,int vl,int sum,bool fl){
	if(fl)ans*=vl,ans%=mod;
	if(pos>r)return;
	if(vl==1&&sum)return;
	dfs(pos+1,sum?__gcd(vl,a[pos]):a[pos],sum+1,1);
	dfs(pos+1,vl,sum,0);
}
signed main(){
	FRE();
	n=rd(),m=rd();
	for(int i=1;i<=n;++i){
		a[i]=rd();
	} 
	while(m--){
		l=rd(),r=rd();
		ans=1;
		dfs(l,1,0,0);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
3 1
2 4 3
1 3
*/
/*
5 2
8 2 8 8 9
1 5
2 4
*/
