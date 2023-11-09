#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define N 200010
#define ll long long

void solve(){
	int n=100000,k=40,m=1000000,t=30;
	cout<<n<<' '<<k<<' '<<m<<'\n';
	For(i,1,n){
		cout<<rand()%m+1<<' '<<rand()%k+1<<' ';
		if(t&&rand()%7==0){
			cout<<"D\n";
			--t;
		}else{
			cout<<"L\n";
		}
	};
	return;
}
int main(){
	freopen("chameleon.in","w",stdout);
	int t=1;
	while(t--)solve();
	return 0;
}
