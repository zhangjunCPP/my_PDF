#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5,inf=0x3f3f3f3f;
int n,a[N];
int tong[3][25][25];
int A=0,B=1,C=2;
void update(int w,int now,int las) {
	for(int mn=w;mn<=20;mn++) 
		for(int mx=mn;mx<=20;mx++) 
			tong[now][w][mx]|=tong[las][mn][mx];
	for(int mx=w;mx>=1;mx--) 
		for(int mn=mx;mn>=1;mn--) 
			tong[now][mn][w]|=tong[las][mn][mx];
	for(int mn=1;mn<=w;mn++) 
		for(int mx=w;mx<=20;mx++) 
			tong[now][mn][mx]|=tong[las][mn][mx];
}
void solve() {
	tong[A][a[1]][a[1]]=1;
	tong[B][a[2]][a[2]]=1;
	tong[B][min(a[1],a[2])][max(a[1],a[2])]=2;
	for(int i=3;i<=n;i++) {
		update(a[i],C,B);
		update(a[i]+a[i-1],C,A);
		int t=A;
		A=B,B=C,C=t;
		memset(tong[C],0,sizeof tong[C]);
	}
	int now=B,ans=inf;
	if(n==1) now=A; 
	for(int mn=1;mn<=20;mn++) 
		for(int mx=mn;mx<=20;mx++) 
			if(tong[now][mn][mx]) ans=min(mx-mn,ans);
	printf("%d",ans);
}
int f[N];
int DP(int l,int r,int mx) {
	for(int i=l-1;i<=r;i++)f[i]=mx;
	for(int i=l;i<=r;i++) {
		if(a[i]>mx) return -inf;
		f[i]=min(f[i-1],a[i]);
		if(i>l&&a[i]+a[i-1]<=mx) {
			f[i]=max(f[i],min(f[i-2],a[i]+a[i-1]));
		}
	}
	return f[r];
}
void bf() {
	int ans=inf;
	for(int i=1;i<=n;i++) {
		int w=a[i];
		ans=min(ans,w-min(DP(1,i-1,w),DP(i+1,n,w)));
		if(i>1) 
			w=a[i]+a[i-1],
			ans=min(ans,w-min(DP(1,i-2,w),DP(i+1,n,w)));
	}
	printf("%d",ans);
}
signed main() {
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	int flag=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if(a[i]>10) flag=1;
	}
	if(!flag) solve();
	else 
	bf();
	return 0;
}
