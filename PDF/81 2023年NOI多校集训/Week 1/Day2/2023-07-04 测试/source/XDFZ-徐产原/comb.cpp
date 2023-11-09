#include<bits/stdc++.h>
using namespace std;
int n;
int a[3005],ri[3005],nxt[3005],vis[3005];
int pre[3005][3005];
void Freopen(){
	freopen("comb.in","r",stdin);
	freopen("comb.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=1;j<=n;j++)pre[i][j]=pre[i-1][j];
		pre[i][a[i]]++;
	}
	for(int i=n;i>=1;i--){
		nxt[i]=vis[a[i]];
		vis[a[i]]=i;
	}
	ri[n+1]=n;
	for(int l=n;l>=1;l--){
		ri[l]=ri[l+1];
		for(int r=max(l+3,nxt[l]);r<=ri[l+1];r++){
			bool f1=false;
			for(int i=l+1;i<r;i++)if(a[i]==a[r]&&pre[r-1][a[l]]-pre[i][a[l]]){
				ri[l]=r;
				f1=true;
			}		
			if(f1)break;
		}
	}
	int p=0,ans=0;
	while(ri[p+1]!=p){
		++ans;
		p=ri[p+1];
	}
	printf("%d",ans*4);
}
