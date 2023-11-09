#include<cstdio>
#include<iostream>
using namespace std;
using ll=long long;
ll quickly_power(ll a,int b){
	ll res=1;
	for(;b;b>>=1,a*=a)if(b&1)res*=a;
	return res;
}
ll fac(int n){
	ll res=1;
	for(int i=1;i<=n;++i)res*=i;
	return res;
}
int a[2005][2005];
int b[2005][2005];
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int p,q;cin>>p>>q;
	if(q==1){
		cout<<1<<'\n';
		for(int i=0;i<p;++i)cout<<i<<' ';
		cout<<'\n';
		return 0;
	}else if(q==2){
		cout<<p*(p+1)<<'\n';
		for(int i=0;i<p;++i)
			for(int j=0;j<p;++j)a[i][j]=i*p+j;
		for(int i=0;i<=p;++i){
			for(int j=0;j<p;++j){
				for(int k=0;k<p;++k)cout<<a[j][k]<<' ';
				cout<<'\n';
			}
			for(int j=0;j<p;++j)
				for(int k=0;k<p;++k)b[j][k]=a[k][(j+k)%p];
			for(int j=0;j<p;++j)
				for(int k=0;k<p;++k)a[j][k]=b[j][k];
		}
	}else if(p==2){
		int n=quickly_power(p,q);
		cout<<n*(n-1)/2<<'\n';
		for(int i=0;i<n;++i)
 		for(int j=i+1;j<n;++j)cout<<i<<' '<<j<<'\n';
	}
	return 0;
}
