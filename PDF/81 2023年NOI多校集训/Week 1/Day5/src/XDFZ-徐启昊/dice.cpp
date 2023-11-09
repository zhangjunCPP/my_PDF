#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+11,inf=1e9;
void Freopen(){
	freopen("dice.in","r",stdin);
  	freopen("dice.out","w",stdout);
}
int n,k;
void solve10(){
	puts("Yes");
	for(int i=1;i<=6;i++)
		cout<<k*i<<" ";
}
void solve20(){
	puts("Yes");
	for(int i=1;i<=n;i++)
		cout<<"0 2 4 6 8 10\n";
}
void solve70(){
	puts("Yes");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=6;j++)
			cout<<k*j*2<<" ";
		cout<<endl;
	}	
}
void chksolve(){
	if(n==1){
		solve10();
		return;
	}
	if(k==2){
		solve20();
		return;
	}
	solve70();
}
signed main(){
	Freopen();
	cin>>n>>k;
	chksolve();
	return 0;
}

