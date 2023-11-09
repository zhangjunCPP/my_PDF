/*

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=7e5+10;
int n,a[N],ans;
int s1[N],s2[N],t1,t2;
void solve(int l,int r){
	// cout<<l<<" "<<r<<endl;
	if(r-l+1<=1)return;
	int mid=l-1+ceil((r-l+1)/2.0);
	int point=a[mid];
	t1=t2=0;
	for(int i=l;i<=r;i++){
		ans++;
		if(a[i]<point)s1[++t1]=a[i];
		if(a[i]>point)s2[++t2]=a[i];
	}
	// cout<<l<<" "<<r<<" "<<mid<<" "<<t1<<" "<<t2<<endl;
	for(int i=1;i<=t1;i++){
		a[l+i-1]=s1[i];
	}
	for(int i=1;i<=t2;i++){
		a[r-t2+i]=s2[i];
	}
	int x=t1,y=t2;
	solve(l,l+x-1);
	solve(r-y+1,r);
}
signed main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	solve(1,n);
	printf("%lld",ans);
	return 0;
}
/*
g++ sort.cpp -o sort -std=c++14 -O2 -Wall
./sort
*/