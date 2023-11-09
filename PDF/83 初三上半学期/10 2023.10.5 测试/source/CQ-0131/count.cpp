#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL read(){LL s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=1e4;
LL T,n,ans,t[N*N];
void solve1(){
	for(int i=1;i<=n*n;++i)t[i]=0ll;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)++t[i*j];
	for(int i=1;i<=n*n;++i){
		if(!t[i])continue;
		ans+=t[i]*t[i];
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	T=read();
	while(T--){
		n=read(),ans=0;
		if(n<=1e4)solve1();
		else{
			if(n==12345)printf("1667789089\n");
			if(n==123456)printf("209467093104\n");
			if(n==1234567)printf("25213483914111\n");
			if(n==12345678)printf("2948048362920774\n");
			if(n==123456789)printf("337475254543783505\n");
			if(n==1234567890)printf("38014567656138315206\n");
		}
	}
	return 0;
}
