#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+15;
int n,k,t[N],c[N],st[N];
ll mn[N];
struct Node { ll sum,pa; } f[N];
struct node { int num,cost; } a[N];
bool cmp(node x,node y) { return x.num==y.num?x.cost>y.cost:x.num>y.num; }
int sp(int x) {
	if(x<0) x=0;
	int ans=0,l=0,r=n;
	while(l<=r) {
		int mid=( l+r )>>1;
		if(t[mid]>=x) r=mid-1,ans=mid;
		else l=mid+1;
	}
	return ans;
}
int main() {
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	scanf("%d%d",&n,&k); //t[0]=0;
	for(int i=1;i<=n;i++) scanf("%d",&t[i]);
	for(int i=1;i<=k;i++) scanf("%d%d",&a[i].num,&a[i].cost);
	a[k+1].num=1; scanf("%d",&a[k+1].cost); k++;
	if(k==1) {
		for(int i=1;i<=n;i++) printf("%d\n",a[k].cost);
		return 0;
	}
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<=n;i++) {
		f[i].sum=1e16;// cout<<t[i]<<" ";
		for(int j=k; j>=1 ;j--) {
			//cout<<a[j].num<<" "<<a[j].cost<<endl;
			//cout<<min( sp( t[i]-a[j].num+1 ),t[i-1] )<<" ";
			int uva=sp( t[i]-a[j].num+1 ), fff,uv;
			if( t[ uva ]>t[i-1] ) uv=i-1,fff=0;
			else uv=uva,fff=f[uv].pa;
			if(f[i].sum>=f[ uv ].sum + a[j].cost-fff){
				f[i].sum=f[ uv ].sum + a[j].cost-fff;
				if(!fff) f[i].pa=a[j].cost;
			}
			//=min(f[ t[i] ],);
		}
		//cout<<"    "<<f[i].sum<<" "<<f[i].pa;
		//if(f[t[i]]==1e16) f[t[i]]=f[t[i-1]]+a[k].cost;
		//puts("\n");
		//puts("\n\n");
	}
	for(int i=1;i<=n;i++) printf("%lld\n",f[ i ].sum-f[ i-1 ].sum);
	return 0;
} 
