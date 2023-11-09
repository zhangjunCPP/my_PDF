#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q,a[N],mx;
int vis[100010];
void sol1(){
	for(int i=1;i<=q;i++){
		for(int j=0;j<=mx;j++)vis[j]=0;
		int k;scanf("%d",&k);
		int mex=0;
		for(int j=1;j<=k;j++){
			vis[a[j]]++;
		}
		while(vis[mex])mex++;
		int ans=mex;
		for(int j=k+1;j<=n;j++){
			vis[a[j-k]]--;
			if(!vis[a[j-k]]&&a[j-k]<mex)mex=a[j-k];
			vis[a[j]]++;
			while(vis[mex])mex++;
			ans=max(ans,mex);
		}
		printf("%d\n",ans);		
	}
}
void sol2(){
	for(int i=1;i<=q;i++){
		for(int j=0;j<=mx;j++)vis[j]=0;
		int k;scanf("%d",&k);
		int mex=0,ans=0;
		for(int j=1;j<=k;j++){
			vis[a[j]]++;
			while(vis[mex])mex++;
			if(mex>mx){
				ans=mex;break;
			}
		}
		if(ans){
			printf("%d\n",ans);
			continue;
		}else ans=mex;
		for(int j=k+1;j<=n;j++){
			vis[a[j-k]]--;
			if(!vis[a[j-k]]&&a[j-k]<mex)mex=a[j-k];
			vis[a[j]]++;
			while(vis[mex])mex++;
			ans=max(ans,mex);
			if(ans>mx)break;
		}
		printf("%d\n",ans);		
	}
}
int main(){
	freopen("maxmex.in","r",stdin);
	freopen("maxmex.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
	}
	scanf("%d",&q);
	if(n<=100||q<=10)sol1();
	if(mx<=10)sol2();
	return 0;
}


