#include<bits/stdc++.h>
using namespace std;
int n,maxn,ans=0x7fffffff;
int a[200005];
int b[400005],tot;
int op(int l,int r,int mn){
	int lst=l,mx=0;
	for(int i=l+1;i<=r;i++)if(a[i-1]+a[i]<mn){
		if((i-lst)%2==0)
			for(int j=lst;j<i;j+=2)mx=max(mx,a[j]+a[j+1]);
		else if(lst==l&&l!=1){
			for(int j=lst+1;j<i;j+=2)
				mx=max(mx,a[j]+a[j+1]);
			mx=max(mx,a[lst]+a[lst-1]);
		}
		else return 0x7fffffff;
		lst=i;
	}
	if((r+1-lst)%2==0)for(int j=lst;j<r;j+=2)mx=max(mx,a[j]+a[j+1]);
	else if(r!=n||(lst==l&&l!=1)){
		int C1=0x7fffffff,C2=0x7fffffff;
		if(r!=n){
			C1=-0x7fffffff;
			for(int j=lst;j<r;j+=2)C1=max(C1,a[j]+a[j+1]);
			C1=max(C1,a[r]+a[r+1]);	
		}
		if(lst==l&&l!=1){
			C2=-0x7fffffff;
			for(int j=lst+1;j<r;j+=2)
				C2=max(C2,a[j]+a[j+1]);
			C2=max(C2,a[lst]+a[lst-1]);
		}
		mx=max(mx,min(C1,C2));
	}
	else return 0x7fffffff;
	return mx;
}
void Freopen(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d",&n);
	if(n==1||n==2)return puts("0"),0;
	a[0]=a[n+1]=0x3f3f3f3f;for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[++tot]=a[i],maxn=max(maxn,a[i]);
	for(int i=2;i<=n;i++)b[++tot]=a[i]+a[i-1];
	sort(b+1,b+1+tot);
	tot=unique(b+1,b+1+tot)-b-1;
	for(int i=1;i<=tot;i++){
		int mn=b[i],mx=maxn;
		for(int l=1,r=l;l<=n;l=++r)if(a[l]<mn){
			while(r<n&&a[r+1]<mn)++r;
			//printf("%d %d\n",l,r);
			mx=max(mx,op(l,r,mn));
		}
		//printf("%d %d\n",mn,mx);
		ans=min(ans,mx-mn);
	}	
	printf("%d",ans);
}
