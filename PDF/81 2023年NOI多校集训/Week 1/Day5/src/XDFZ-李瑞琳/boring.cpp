#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=1e5+10;
const int mod=998244353;
int n,q,c[N];
LL a[N],ans[N];
int main(){
	freopen("boring.in","r",stdin);
	freopen("boring.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=q;++i){
		memset(c,0,sizeof(c));
		int k=read(),maxx=0;
		LL ans=1ll;
		for(int j=1;j<=k;++j){
			int l=read(),r=read();
			++c[l],--c[r+1],maxx=max(maxx,r);
		}
		for(int j=1;j<=maxx;++j){
			c[j]+=c[j-1];
		}
		for(int j=1;j<=maxx;++j)
			if(c[j]>0)ans=std::__detail::__lcm(ans,a[j])%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
