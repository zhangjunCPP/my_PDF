#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
#define ll long long
ll a[maxn],Sum[maxn];
int n;
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&n); 
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) Sum[i]=Sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(a[mid]*(ll)i>Sum[i]) r=mid;
			else l=mid+1;
		}
		if(a[l]*(ll)i>Sum[i])
			ans=max(ans,i-l+1);
	}
	printf("%d",ans); 
	return 0;
}
