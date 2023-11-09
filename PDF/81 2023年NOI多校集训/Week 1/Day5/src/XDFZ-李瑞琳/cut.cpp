#include<bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=5e5+10;
int n,a[N],ans,pre[N],dp[N],f[N][21],answ[N];
int get(int s){
	int i=0;
	while((s>>i)&1)++i;
	return i;
}
void solve1(){
	memset(dp,-0x3f3f3f3f,sizeof(dp));dp[0]=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<i;++j){
			int s=0;
			for(int k=j+1;k<=i;++k)s|=(1<<a[k]);
			int g=get(s);
			if(dp[i]<dp[j]+g)pre[i]=j;
			dp[i]=max(dp[i],dp[j]+g);
		}
	}
	printf("%d ",dp[n]);
	int i=n,num=0,tot=0;
	while(pre[i])answ[++tot]=pre[i]+1,++num,i=pre[i];
	answ[++tot]=1;
	printf("%d\n",num+1);
	sort(answ+1,answ+1+tot);
	for(int i=1;i<=tot;++i)printf("%d ",answ[i]);
}
void solve2(){
	memset(f,-0x3f3f3f3f,sizeof(f));
	f[0][0]=0,f[1][1<<a[1]]=(a[1]==0?1:0);
	for(int i=1;i<n;++i){
		for(int s=0;s<(1<<2);++s){
			if(!((s>>a[i])&1))continue;
			if(f[i][s]==-0x3f3f3f3f)continue;
			f[i+1][1<<a[i+1]]=f[i][s]+(a[i+1]==0?1:0);
			if((s>>a[i+1])&1)f[i+1][s]=max(f[i+1][s],f[i][s]);
			else f[i+1][s|(1<<a[i+1])]=max(f[i+1][s|(1<<a[i+1])],f[i][s]-get(s)+get(s|(1<<a[i+1])));
		}
	}
	for(int s=0;s<(1<<2);++s)ans=max(ans,f[n][s]);
	printf("%d\n",ans);
}
int main(){
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	if(n<=1e3)solve1();
	else solve2();
	return 0;
}
