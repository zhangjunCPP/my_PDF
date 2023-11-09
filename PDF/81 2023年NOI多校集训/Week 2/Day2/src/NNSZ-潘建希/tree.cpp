#include<bits/stdc++.h>
using namespace std;
const int N=1000009,M=1000000007;
int n,a[N][3];
long long ans;
bool v[N],v2[N],k;
long long m(int x){
	long long e=1;
	for(int i=1;i<=x;i++){
		e*=2;
		e%=M;
	}
	return e;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	if(n==1){
		printf("0");
		return 0;
	}
	if(n==2){
		printf("2");
		return 0;
	}
	for(int i=1;i<n;i++){
		scanf("%d%d",&a[i][1],&a[i][2]);
		if(v2[a[i][1]]||v2[a[i][2]])k=true;
		if(v[a[i][1]])v2[a[i][1]]=true;
		if(v[a[i][2]])v2[a[i][2]]=true;
		v[a[i][1]]=true;
		v[a[i][1]]=true;
	}
	if(k){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans=ans%M;
		}
		ans*=3;
		ans=ans%M;
		printf("%lld",(ans+M)%M);
	}else{
		for(int i=n;i>=(n+1)/2;i--){
			ans=ans+((i-1)*m(i-1-n+i))%M;
			ans=(M+ans%M)%M;
		}
		printf("%lld",(ans*2+M)%M);
	}
	return 0;
} 
