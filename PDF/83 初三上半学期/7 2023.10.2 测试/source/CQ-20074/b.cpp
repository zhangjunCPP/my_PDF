#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
long long pre[100005];
int a[100005],num[100005],npre[100005];
void Freopen(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	m=n;n=0;
	for(int i=1;i<=m;i++)
		if(a[i]!=a[n])a[++n]=a[i],num[n]=1;
		else num[n]++;
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+1ll*a[i]*num[i],
		npre[i]=npre[i-1]+num[i];
	for(int l=1,r=1;l<=n;l++){
		while(r<n&&(pre[r+1]-pre[l-1])-1ll*(npre[r+1]-npre[l-1])*a[l]<1ll*a[l]*npre[l-1]-pre[l-1])++r;
		ans=max(ans,npre[r]-npre[l-1]);
	}
	printf("%d",ans);
	
}
/*
5
1 2 3 4 5
*/
