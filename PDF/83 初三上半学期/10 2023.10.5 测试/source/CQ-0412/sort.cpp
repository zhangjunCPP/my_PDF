/*
±©Á¦
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll re(){
	ll x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}
const ll N=7e5+10;
ll a[N],ans,q1[N],q2[N],n;
void solve(ll l,ll r){
//	printf("solve(%lld,%lld)\n",l,r);
	if(l>=r)return;
	ll mid=a[l+((r-l+2)>>1)-1];
//	printf("mid=%lld\n",mid);
	ll tp1=0,tp2=0;
	for(ll i=l;i<=r;++i){
		++ans;
		if(a[i]<mid)q1[++tp1]=a[i];
		if(a[i]>mid)q2[++tp2]=a[i];
	}
	ll i;
	for(i=1;i<=tp1;++i)a[l+i-1]=q1[i];
	a[l+tp1]=mid;
	for(i=1;i<=tp2;++i)a[l+tp1+i]=q2[i];
//	for(i=1;i<=n;++i)printf("%lld ",a[i]);putchar(10);
	solve(l,l+tp1-1);
	solve(l+tp1+1,r);
}
ll i;
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	n=re();
	for(i=1;i<=n;++i)a[i]=re();
	solve(1,n);
//	for(i=1;i<=n;++i)printf("%lld ",a[i]);putchar(10);
	printf("%lld",ans);
	return 0;
}

