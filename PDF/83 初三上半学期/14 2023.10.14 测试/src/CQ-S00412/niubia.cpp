#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}

int main(){
//	freopen(".in","r",stdin);
	freopen("ddickky.in","w",stdout);
	int n=500,q=500;
	srand(time(0));
	cout<<n<<' '<<q<<endl;
	for(int i=1;i<=n;i++)cout<<rand()%n+1<<' ';
	cout<<endl;
	while(q--){
		int l=1,r=n;
		cout<<l<<' '<<r<<endl;
	}
	return 0;
}

