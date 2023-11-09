#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}

int main(){
//	freopen(".in","r",stdin);
	freopen("b.in","w",stdout);
	int n=18;
	srand(time(0));
	cout<<n<<endl;
	for(int i=1;i<=n;i++)cout<<rand()<<' ';
	
	return 0;
}

