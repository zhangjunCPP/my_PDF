#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,k,L,col[1000010];
char op[1000010];
ll ans[50];
int main(){
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
	cin>>n>>k>>L;
	for(int i=1,p;i<=n;i++)
	scanf("%d",&p),scanf("%d %c",&col[p],&op[p]);
	ll sum[50]{};
	for(int i=0,las=-1,fir=-1;i<=L;i++)
	if(op[i]=='L'){
		if(~las)ans[col[i]]+=i-las,ans[(col[i]+col[fir])%k]+=i+fir;
		else ans[col[i]]+=i*2;
		for(int x=0;x<k;x++)
		ans[(col[i]+x)%k]+=sum[x];
	}else if(op[i]=='D'){
		ans[col[i]]+=L-i<<1;
		if(las==-1)fir=i;
		else{(col[fir]+=col[i])%=k;
			ll tmp[50]{};sum[0]+=i-las;
			for(int x=0;x<k;x++)
			tmp[(x+col[i])%k]=sum[x];
			swap(tmp,sum);
		}
		las=i;
	}for(int i=0;i<k;i++)
	printf("%lld.%d\n",ans[i]/2,ans[i]&1?5:0);
	return 0;
}
