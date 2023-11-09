#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
const int N=2e5+17;
int n,a[N];
int ans=0x7fffffff;
void dfs(int mn,int mx,int pos){
	if(mx-mn>=ans)return;
	if(pos==n+1){
		ans=min(ans,mx-mn);
//		printf("1");
		return;
	}
	dfs(min(mn,a[pos]),max(mx,a[pos]),pos+1);
	if(pos!=n){
		dfs(min(mn,a[pos]+a[pos+1]),max(mx,a[pos]+a[pos+1]),pos+2);
	}
}
signed main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	int mn=0x7fffffff;
	int mx=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mx=max(a[i],mx);
		mn=min(a[i]+a[i-1],mn);
//		t[++tot]=a[i];
//		t[++tot]=a[i]+a[i-1];
	}
	if(n==1){
		printf("%d",0);
		return 0;
	}
	else{
		if(n<=18){
			dfs(a[1],a[1],2);
			dfs(a[1]+a[2],a[1]+a[2],3);
			printf("%d",ans);
			return 0;
		}
		printf("%d",mx-mn);
		return 0;
	}
//	sort(t+1,t+1+tot);
//	tot=unique(t+1,t+1+tot)-(t+1);
//	added[0]=1;
//	for(int mn=1;mn<=tot;mn++){
//		int l=0,r=0;
//		for(int i=1;i<=n;i++){
//			while(a[i]>=mn)i++;
//			l=i;
//			r=l;
//			while(a[i+1]<mn)r++;
//			
//		}
//	}
}
/*
5
2 2 3 5 2

*/
