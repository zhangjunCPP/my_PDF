#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL read(){LL s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const LL N=1e6+10;
LL n,mod,db[10]={0,0,0,1,7,47,322,2404},answer;
void solve1(){
	LL ans=0;
	for(LL i=1;i<=n;++i)ans^=db[i];
	printf("%lld\n",ans);
}
int main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	n=read(),mod=read();
	if(n<=7){solve1();return 0;}
	for(LL k=1;k<=n;++k){
		LL ans=0;
		for(LL i=1;i<k;++i){
			LL qian=1,sum=i-1,hou=0,jc=1;
			if(i>1)
				for(LL j=i-1;j>=(i)/2;--j)qian=(qian+sum)%mod,sum=sum*(j-1)%mod;
			for(LL j=1;j<=k-i-1;++j)hou=(hou+j)%mod,jc=jc*j%mod;
			hou=hou*jc%mod;
			ans=(ans+qian*hou%mod)%mod;
		}
		answer^=ans;
	}
	printf("%lld\n",answer);
	return 0;
}
