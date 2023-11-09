#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[110][10];
signed main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(n==1){
		cout<<"Yes\n";
		for(int i=1;i<=6;i++){
			cout<<k*i<<" ";
		}
		return 0;
	}
	if(k==2){
		cout<<"Yes\n";
		for(int i=1;i<=n;i++){
			int x=1;
			for(int j=1;j<=6;j++){
				cout<<2*x<<" ";
				x++;
			}
			cout<<endl;
		}
		return 0;
	}
	cout<<"No";
	return 0;
}
/*
*/
