#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define N 200005
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,a[N],l=INF,r,ans,mid,mn,mx;
bool dfs(int x){
	if(x==n+1)return 1;
	else if(x>n+1)return 0;
	bool res=0;
	int t1=min(mn,a[x]),t2=max(mx,a[x]);
	if(abs(t1-t2)<=mid){
		swap(mn,t1);
		swap(mx,t2);
		res|=dfs(x+1);
		swap(mn,t1);
		swap(mx,t2);
	}
	t1=min(mn,a[x]+a[x+1]);
	t2=max(mx,a[x]+a[x+1]);
	if(abs(t1-t2)<=mid){
		swap(mn,t1);
		swap(mx,t2);
		res|=dfs(x+2);
		swap(mn,t1);
		swap(mx,t2);
	}
	return res;
}
bool check(){
	bool res=0;
	mn=mx=a[1];
	res|=dfs(2);
	mn=mx=a[1]+a[2];
	res|=dfs(3);
	return res;
}
signed main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		l=min(l,a[i]);
		r=max(r,a[i]+a[i-1]);
	}
	if(n==1){
		printf("0");
		return 0;
	}
	r-=l;
	l=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(check()){
			ans=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
5
2 2 3 5 2
*/
