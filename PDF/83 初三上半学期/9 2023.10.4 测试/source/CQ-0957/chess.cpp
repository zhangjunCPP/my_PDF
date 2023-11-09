#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define N 200010
#define ll long long
int n,p,k;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>p>>k;
	if(k==1){
		cout<<"1\n";
		For(i,1,p)cout<<i-1<<' ';
		return 0;
	}
	n=1;
	For(i,1,k)n*=p;
	if(p==2){
		cout<<n*(n-1)/2<<'\n';
		For(i,1,n)For(j,i+1,n)cout<<i-1<<' '<<j-1<<'\n';
	}
	return 0;
}
