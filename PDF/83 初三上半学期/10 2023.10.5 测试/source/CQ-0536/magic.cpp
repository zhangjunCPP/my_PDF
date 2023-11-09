#include<stdio.h>
#include<algorithm>

template <typename dy> dy max(dy x,dy y){return x>y?x:y;}
template <typename dy> dy min(dy x,dy y){return x<y?x:y;}
#define int long long
const int N=1e3+5;
int n,ans,id[N];
struct dy{
	int l,r,c;
}a[N];
signed main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i].l,&a[i].r,&a[id[i]=i].c);
	do{
		int sum[N]={},s=0;bool f[N]={};
		for(int i=1;i<=n;i++){
			f[id[i]]=1;
			for(int j=a[id[i]].l;j<=a[id[i]].r;j++) if(!f[j]) sum[j]+=a[id[i]].c;
		}
		for(int i=1;i<=n;i++) s+=sum[i];
		ans=max(ans,s);
	}while(std::next_permutation(id+1,id+n+1));
	printf("%lld\n",ans);
	return 0;
}
