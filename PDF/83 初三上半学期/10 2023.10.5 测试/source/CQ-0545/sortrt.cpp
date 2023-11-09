#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
int a[200002];
int main(){
//	freopen(".in","r",stdin);
	freopen("sort.in","w",stdout);
	int n=200000;
	cout<<n<<endl;srand(time(0)); 
	for(int i=1;i<=n/2;i++)a[i]=i,cout<<i<<' ';
	for(int i=n/2+1;i<=n;i++)a[i]=n-(i-n/2)+1,cout<<a[i]<<' '; 
	return 0;
}

