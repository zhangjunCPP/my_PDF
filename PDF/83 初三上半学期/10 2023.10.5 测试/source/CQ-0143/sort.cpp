#include<bits/stdc++.h>

using namespace std;

long long tot=1;
long long ans=0;
vector<long long>a[777777];
long long solve(long long d){
//	cout<<a[d].size()<<endl;
	if(a[d].size()<=1) return 0;
	long long x=ceil(1.0*a[d].size()/2);
	long long yu=a[d][x-1];
	long long er=++tot;
	long long df=++tot;
	for(long long i=0;i<a[d].size();i++){
		long long xx=a[d][i];
		ans++;
		if(xx<yu){
			a[er].push_back(xx);
		}
		if(xx>yu){
			a[df].push_back(xx);
		}
	}
	solve(er);
	solve(df);
	return 0;
}

int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long x;
		cin>>x;
		a[1].push_back(x);
	}
	solve(1);
	cout<<ans;
	
	return 0;
}
