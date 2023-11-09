#include<bits/stdc++.h>
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
const int QWQ=1e5+5;
using namespace std;
struct node{ int pay,time; } a[QWQ];
int n,k,t[QWQ],one,f[QWQ];
signed main(){
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	scanf("%lld%lld",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%lld",&t[i]);
	for (int i=1;i<=k;i++)
		scanf("%lld%lld",&a[i].time,&a[i].pay);
	scanf("%lld",&one);
	if (!k){ for (int i=1;i<=n;i++) printf("%lld\n",one); return 0; }
	f[0]=0; //f[1]=one;
	for (int i=1;i<=n;i++){
		f[i]=min(f[i],f[i-1]+one);
		for (int j=1;j<=k;j++){
			int l=0,r=i+1,tot;
			while (l<=r){
				int mid=(l+r)>>1;
				if (t[i]-t[mid]<a[j].time) r=mid-1,tot=mid;
				else l=mid+1;
			} f[i]=min(f[i],f[tot-1]+a[j].pay);
		}
	} for (int i=1;i<=n;i++)
		printf("%lld\n",f[i]-f[i-1]);
	return 0;
} 
