#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
int Rand(){
	return rand()<<15|rand();
}
int main(){
//	freopen(".in","r",stdin);
	freopen("d.in","w",stdout);
	int n=10000,m=1000000;
	cout<<n<<' '<<m<<endl;
	srand(time(0));
	for(int i=1;i<=n;i++){
		int a=Rand()%m+1,b=Rand()%m+1;
		while(b==a)b=Rand()%m+1;
		cout<<a<<' '<<b<<endl;
	}
	return 0;
}

