#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200005,INF=1e9,mod=1e9+7;
int _;
int n,k,tot;

int main(){
	ios::sync_with_stdio(0);
	freopen("dice.in","r",stdin); 
	freopen("dice.out","w",stdout); 
	cin>>n>>k;
	
	if(n==1){
		if(k*6>1e6)cout<<"No"<<endl;
		else {
			for(int i=1;i<=6;i++){
				cout<<k*i<<" ";
			}
		}
		return 0;
	}
	
	if(k==2){
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=6;j++){
				cout<<j*2<<" ";
			}
			cout<<endl;
		}
		return 0;
	}
	cout<<"NO"<<endl;
    return 0 ^ _ ^ 0;
}



