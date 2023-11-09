//我猜他会是前面连续一段和中间连续一段
//前面一段负责拉低平均数,后一段负责收集贡献
//那么后一段肯定是都比平均数大
//*,没时间了,暴力,启动!
//那么就是前面有一段,然后紧挨着前面又一段
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,a[1000010];
ll s[1000010];
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<n;i++)if(a[i]!=a[i+1]){
		int l=i,r=n;
		while(l<r){
			int mid=l+r+1>>1;
			if(a[i]*1ll*mid>=s[mid])l=mid;
			else r=mid-1;
		}ans=max(ans,l-i+(a[i]*1ll*l>s[l]));
	}cout<<ans;
	return 0;
}
