/*
i i i i
i-1的方案
i n i n 
设n=p1^k1*p2^k2……px^kx
ans+=(k1+1)(k2+1)……(kx+1)/2
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=110;
// int ans[N];
int sol(int n){
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				for(int l=1;l<=n;l++){
					if(i*j==k*l){
						sum++;
						// if(((i<j&&k<=l)||(i<=j&&k<l))&&(i==n||j==n||k==n||l==n)){
						// 	cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
						// }
					}
				}
			}
		}
	}
	return sum;
}
int fj(int x){
	int ans=1;
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			int k=0;
			while(x%i==0){
				x/=i;
				k++;
			}
			ans*=k+1;
		}
	}
	if(x!=1)ans*=2;
	if(!(ans&1)){
		ans/=2;
		return ans*(ans-1)*4;
	}
	ans=ans/2;
	return ans*(ans-1)*4+ans*2*2;
}
void sol1(int n){
	int ans=1;
	for(int i=2;i<=n;i++){
		ans+=1+(i-1)*4;
		int x=fj(i);
		ans+=x;
	}
	printf("%lld\n",ans);
}
void sol2(int n){
	map<int,int>mp;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mp[i*j]++;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mp[i*j]>0){
				ans+=mp[i*j];
			}
		}
	}
	printf("%lld\n",ans);
}
void sol3(int n){
	printf("%lld\n",sol(n));
}
void solve(){
	int n;scanf("%lld",&n);
	if(n<=100)sol3(n);
	else sol2(n);
}
signed main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int t;scanf("%lld",&t);
	while(t--){
		solve();
	}
	return 0;
}
/*
g++ count.cpp -o count -std=c++14 -O2 -Wall
./count
*/