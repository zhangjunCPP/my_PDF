#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+11,inf=1e16;
map<pair<int,int>,int>k;
void solve80(){
	for(int i=1;i<=60;i++){
		k[make_pair(i,i*(i-1)/2)]=1;
		k[make_pair(i,0)]=1;
		for(int j=1;j<i;j++){
			int n=j,m=i-j;
			for(int l=0;l<=m;l++)
				for(int u=0;u<=n;u++)
					k[make_pair(i,n*m+l*(m-1)/2+u*(n-1)/2)]=1;

		}
	}
	int q;
	cin>>q;
	while(q--){
		int n,m;
		cin>>n>>m;
		cout<<k[make_pair(n,m)]<<endl;
	}
}
void solve100(){
	
}
signed main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	solve80();
//  solve100();	
	return 0;
}
