#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int p,k;
	cin>>p>>k;
	if(k==1){
		cout<<"1\n";
		for(int i=0;i<p;i++) cout<<i<<" ";
		return 0;
	}
	else if(p==2){
		int n=pow(p,k);
		cout<<n*(n-1)/2<<"\n";
		for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)cout<<i<<" "<<j<<"\n";
		return 0;
	}	
}