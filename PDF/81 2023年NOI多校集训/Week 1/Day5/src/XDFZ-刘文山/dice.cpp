#include<bits/stdc++.h>
using namespace std;
int n,d;
int main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	cin>>n>>d;
	if(n==1){
		cout<<"Yes\n";
		for(int i=1;i<=6;i++){
			cout<<i*d<<" ";
		}
		return 0;
	}
	if(d==2){
		for(int i=1;i<=(n>>1)<<1;i++){
			cout<<"1 3 5 7 9 11\n"; 
		}
		if(n&1) cout<<"2 4 6 8 10 12\n";
		return 0;
	}
	cout<<"Yes\n";
	int x=d,cnt=0;
	while(x){
		x>>=1;
		cnt++;
	}
	for(int i=1;i<=n;i++){
		cout<<d<<" "<<(d<<cnt)<<" "<<(d<<(cnt*2))<<" "<<(d|(d<<cnt))<<" "<<(d|(d<<(cnt*2)))<<" "<<((d<<cnt)|(d<<(cnt*2)))<<endl;
	}
	return 0;
} 
