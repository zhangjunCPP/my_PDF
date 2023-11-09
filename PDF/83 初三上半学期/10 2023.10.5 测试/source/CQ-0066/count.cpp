#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int n;
ll cnt[N],ans;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d",&n),ans=0;
		for(int i=1;i<=n*n;++i) cnt[i]=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				++cnt[i*j];
		for(int i=1;i<=n*n;++i) ans+=1ll*cnt[i]*cnt[i];
		printf("%lld\n",ans);		
	}

	return 0;
}
