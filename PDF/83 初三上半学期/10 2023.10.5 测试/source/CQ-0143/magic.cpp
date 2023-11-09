#include<bits/stdc++.h>

using namespace std;
long long a[2222][2222];
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	long long n;
	cin>>n;
	long long fl=0;
	for(long long i=1;i<=n;i++){
		long long x,y,z;
		cin>>x>>y>>z;
		if(z==0) continue;
		if(x==y) continue;
		if(max(i-x,y-i)>0){
			fl=1;
		}
		for(long long j=x;j<=y;j++){
			if(j==i) continue;
			a[i][j]=max(a[i][j],z);
		}
	}
	if(fl==0){
		cout<<0;
		return 0;
	}
	long long ans=0;
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			if(!a[i][j]&&!a[j][i]) continue;
			ans=ans+max(a[i][j],a[j][i]);
		}
	}
	cout<<ans;
	
	
	return 0;
}
