#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+5;
const ll mod=998244353;
int pr[N],v[N],k,to[N];
ll ksm(ll a,ll b){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
void primes(int n){
	for(int i=2;i<=n;i++){
		if(!v[i])pr[++k]=i,to[i]=k;
		for(int j=i+i;j<=n;j+=i)v[j]=1;
	}
}
int n,q;
int a[N];
int f[2000][330][13],lg2[N];
int f1[N][96][17];
int ask(int p,int l,int r){
	int tmp=lg2[r-l+1];
	return max(f[l][p][tmp],f[r-(1<<tmp)+1][p][tmp]);
}
int ask1(int p,int l,int r){
	int tmp=lg2[r-l+1];
	return max(f1[l][p][tmp],f1[r-(1<<tmp)+1][p][tmp]);
}
void solve(){
	primes(500);
	for(int i=1;i<=n;i++){
		for(int j=2;j*j<=a[i];j++)while(a[i]%j==0)f1[i][to[j]][0]++,a[i]/=j;
		if(a[i]>1)f1[i][to[a[i]]][0]=1;
	}
	for(int p=1;p<=k;p++){
		for(int j=1;j<=lg2[n];j++)for(int i=1;i+(1<<j)-1<=n;i++)
			f1[i][p][j]=max(f1[i][p][j-1],f1[i+(1<<(j-1))][p][j-1]);
	}
	while(q--){
		ll ans=1;
		int w;
		scanf("%d",&w);
		vector<int> s;
		s.resize(96);
		while(w--){
			int l,r;
			scanf("%d%d",&l,&r);
			for(int i=1;i<=k;i++)s[i]=max(s[i],ask1(i,l,r));
		}
		for(int i=1;i<=k;i++)ans=(ans*ksm(pr[i],s[i]))%mod;
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("boring.in","r",stdin);
	freopen("boring.out","w",stdout);
	int fl=1;
	for(int i=2;i<N;i++)lg2[i]=lg2[i>>1]+1;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),fl&=(a[i]<=500);
	if(fl)return solve(),0;
	primes(2000);
	for(int i=1;i<=n;i++){
		for(int j=2;j*j<=a[i];j++)while(a[i]%j==0)f[i][to[j]][0]++,a[i]/=j;
		if(a[i]>1)f[i][to[a[i]]][0]=1;
	}
	for(int p=1;p<=k;p++){
		for(int j=1;j<=lg2[n];j++)for(int i=1;i+(1<<j)-1<=n;i++)
			f[i][p][j]=max(f[i][p][j-1],f[i+(1<<(j-1))][p][j-1]);
	}
	while(q--){
		ll ans=1;
		int w;
		scanf("%d",&w);
		vector<int> s;
		s.resize(330);
		while(w--){
			int l,r;
			scanf("%d%d",&l,&r);
			for(int i=1;i<=k;i++)s[i]=max(s[i],ask(i,l,r));
		}
		for(int i=1;i<=k;i++)ans=(ans*ksm(pr[i],s[i]))%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
/*
10 4
2 7 4 3 5 1 3 9 5 1
5 2 2 4 4 6 6 7 7 10 10
2 1 4 8 8
3 1 3 2 2 7 9
2 1 1 2 2
*/
