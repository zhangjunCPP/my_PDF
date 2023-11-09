#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define N 700010
#define ll long long
int a[N],n=700000;
int main(){
	For(i,1,n)a[i]=i;
	mt19937 rnd(time(0));
	shuffle(a+1,a+1+n,rnd);
//	For(i,1,5)swap(a[rnd()%n+1],a[rnd()%n+1]);
//	for(int i=1;i<=n;i+=10)shuffle(a+i,a+i+10,rnd);
	cout<<n<<'\n';
	For(i,1,n)cout<<a[i]<<' ';
	return 0;
}
