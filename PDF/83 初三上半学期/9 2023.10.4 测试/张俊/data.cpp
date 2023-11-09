#include <bits/stdc++.h>
using namespace std;
int random(int l,int r) {
	return rand()%(r-l+1)+l;
}
int main(){
	freopen("trans.in","w",stdout);
	srand(time(NULL));
	int T;
	T=random(1,5);
	cout<<T<<"\n";
	while(T--){
		int n=2;
		int m=random(1,20);
		int k=random(1,1000);
		cout<<n<<" "<<m<<" "<<k<<"\n";
		for(int i=1;i<=m;i++) {
			cout<<"1 2 "<<random(1,10000)<<" "<<random(1,10000)<<"\n";
		}
	}

}
