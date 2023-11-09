/*
t2
要使 严格>S的平均数 的数个数尽量多
我们不妨考虑对已有的S，新加入一个数会带来什么后果
如果新数<S的平均数，加入它会让S的平均数减小，对答案显然有利
如果等于，不加白不加
如果大于，会给答案带来1的贡献，但会增大平均数

所以，我们有以下几种可能的思路：
1.dp
2.二分
3.贪心

先说贪心
我们可以全选
此时会有一个平均数s
显然，我们不会删掉比平均数小的数字
因此，我们每次删掉最大的数

写出来了，样例也过了
但说实话有点不放心 
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
ll n,i,a[N],ans,sum;
ll calc(ll x){//>=x
	ll l=1,r=n,res=-1;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(a[mid]>=x)res=n-mid+1,r=mid-1;
		else l=mid+1;
	}
	return res;
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%lld",&n);
	for(i=1;i<=n;++i)scanf("%lld",a+i),sum+=a[i];
	sort(a+1,a+1+n);
	for(;n;--n){
		ans=max(ans,calc(sum/n+1));
		sum-=a[n];
	}
	printf("%lld",ans);
	return 0;
}
