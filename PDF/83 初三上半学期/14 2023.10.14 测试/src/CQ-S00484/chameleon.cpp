#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,l,k,x,y,cnt,tot;
double vis[100001];
struct dcz{
	int x,ys;
}a[100001],b[100001];
bool cmp(dcz x,dcz y){
	return x.x<y.x;
}
signed main(){
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
	cin>>n>>k>>l;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>x>>y>>ch;
		if(ch=='D') b[++cnt].x=x,b[cnt].ys=y,vis[b[cnt].ys]+=l-x;
		else a[++tot].x=x,a[tot].ys=y;
	}
	sort(a+1,a+tot+1,cmp);
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<=tot;i++){
		double val=0;
		for(int j=cnt;j>=1;j--){
			if(b[j].x>a[i].x) continue;
			vis[a[i].ys]+=((double)(a[i].x-b[j].x)-val*2)/2.0;
			val+=((double)(a[i].x-b[j].x)-val*2)/2.0;
			a[i].ys=(a[i].ys+b[j].ys)%k;
		}
		vis[a[i].ys]+=a[i].x-val;
	}
	for(int i=0;i<k;i++){
		printf("%.1lf\n",vis[i]);
	}
	return 0;
}
//(a+b)%k  b
