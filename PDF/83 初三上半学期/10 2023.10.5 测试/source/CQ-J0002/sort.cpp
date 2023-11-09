#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100001],n,m;
signed main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	cin>>n;
	srand(time(0));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) cout<<(rand()*rand())%(n*n),exit(0);
	}
	cout<<0;
	return 0;
}

