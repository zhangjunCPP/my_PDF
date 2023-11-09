#include<cstdio>
#include<iostream>
using namespace std;
const int Mod=998244353;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int a[20];
int f[1<<20];
int main(){
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;++i)cin>>a[i];
	long long ans=1;
	for(int i=0;i<1<<n;++i){
		int tmp=0;
		for(int j=1;j<=n;++j)if(i>>j-1&1)
			tmp=gcd(a[j],tmp);
		if(tmp)(ans*=tmp)%=Mod;
	}
	cout<<ans<<'\n';
	return 0;
}
