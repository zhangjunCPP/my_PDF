#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,M=32190,mod=998244353;
bool st;
int pri[N],tot,vis[N];
int cl[N],k_cl;
int n,q,a[N];
int s1[M][510],s2[110][N];
bool ed;
void sol1(){
	for(int i=1;i<=k_cl;i++){
		for(int j=1;j<=n;j++){
			if(a[j]%cl[i]==0){
				s1[i][j]=s1[i][j-1]+1;
			}
			else{
				s1[i][j]=s1[i][j-1];
			}
		}
	}
}
void sol2(){
	for(int i=1;i<=k_cl;i++){
		for(int j=1;j<=n;j++){
			if(a[j]%cl[i]==0){
				s2[i][j]=s2[i][j-1]+1;
			}
			else{
				s2[i][j]=s2[i][j-1];
			}
		}
	}
}
int ksm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int sol3(int l,int r){
	int ans=1,la=0;
	for(int i=1;i<=k_cl;i++){
		if(!vis[cl[i]])la=cl[i];
		ans=ans*ksm(la,(1ll<<(s1[i][r]-s1[i][l-1]))-1)%mod;
	}
	return ans;
}
int sol4(int l,int r){
	int ans=1,la=0;
	for(int i=1;i<=k_cl;i++){
		if(!vis[cl[i]])la=cl[i];
		ans=ans*ksm(la,(1ll<<(s2[i][r]-s2[i][l-1]))-1)%mod;
	}
	return ans;
}
signed main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	cout<<(&st-&ed)/1024.0/1024.0;
	scanf("%lld%lld",&n,&q);
	int mx=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		mx=max(mx,a[i]);
	}
	for(int i=2;i<=mx;i++){
		if(!vis[i]){
			pri[++tot]=i;
			int x=i;
			while(x<=mx){
				cl[++k_cl]=x;
				x*=i;
			}
		}
		for(int j=1;j<=tot;j++){
			int x=i*pri[j];
			if(x>mx)break;
			vis[x]=1;
		}
	}
	if(mx<=450)sol2();
	else sol1();
	for(int i=1;i<=q;i++){
		int l,r;scanf("%lld%lld",&l,&r);
		if(mx<=450)printf("%lld\n",sol4(l,r));
		else printf("%lld\n",sol3(l,r));
	}
	return 0;
}
/*
g++ ddickky.cpp -o ddickky -std=c++14 -O2 -Wall
./ddickky
*/