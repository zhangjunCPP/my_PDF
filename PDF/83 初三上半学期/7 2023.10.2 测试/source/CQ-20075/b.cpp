#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
const int N=1e5+5;
int n;using ll=long long;
ll sum,a[N];
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	n=rd();for(int i=1;i<=n;i++)a[i]=rd(),sum+=a[i];
	sort(a+1,a+1+n);int cnt=0;
	int r=n;
	while(a[r]>sum/1.0/n)r--;
	cnt=n-r;
	for(int i=n-1;i>=1;i--){
		sum-=a[i+1];
		r=i;
		while(a[r]>sum/1.0/i)r--;
		cnt=max(cnt,i-r);
	}
//	for(int i=1;i<=n;i++)cnt+=(a[i]>(sum/1.0/n));
	cout<<cnt;
	return 0;
}
