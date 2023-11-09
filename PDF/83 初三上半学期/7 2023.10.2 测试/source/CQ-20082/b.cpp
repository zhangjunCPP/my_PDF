#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+16;
int n,a[N];
int ant=0;
signed main() {
//	freopen("ex_A1.in","r",stdin);
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	queue<int> ql,qr;
	int suml=0,sumr=0,numl=n-1,numr=1;
	for(int i=n-1;i>=1;i--) ql.push(a[i]),suml+=a[i];
	qr.push(a[n]); sumr+=a[n]; int ans=0;
	while(!ql.empty()) {
//		printf("%lld %lld %lld %lld\n",suml,sumr,numl,numr);
		int u=ql.front(); ql.pop(); suml-=u; numl--;
		qr.push(u); sumr+=u; numr++;
		while( !qr.empty() && sumr+suml>=u*(numl+numr) ) sumr-=qr.front(), numr--, qr.pop();
		ans=max(ans,numr);
	} printf("%lld",ans);
	return 0;
}/*
bool check(int mid) {
	int l=2,r=mid+1;//从mid之前的<=平均数，之后的大于
	int sum=0; sum+=a[1]; int len=1; ant=0;
	while(l<=mid&&r<=n) {//这一部分都可以 
		while(l<=mid&&sum+a[r]>=a[mid+1]*(len+1)) sum+=a[l], l++, len++;
		if(l>mid) break;
		sum+=a[r]; r++; len++; ant++;
	} printf("%lld %lld %lld %lld %lld\n",mid,l,r,sum,len);
	return l<=mid&&r>n;
}*//*
	int l=1,r=n-1,ans=0; //int adf=0;
	while(l<=r) {
//	for(int i=1;i<n;i++) {
		int mid=(l+r)>>1;
//		int mid=i; l=r; r=l;
		if(check(mid)) r=mid-1,ans=max(ans,ant);
		else l=mid+1,ans=max(ans,ant);
//		if(ant==816) adf=i;
	} printf("%lld",ans);
//	cout<<" "<<adf<<" ";*/
