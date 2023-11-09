#include<iostream>
#include<bitset>
using namespace std;
const int MAXN=2005,modd=998244353;
int a,b,c,tot=0;
int num[MAXN],len[MAXN];
int val[MAXN];
int que[MAXN];
bitset<MAXN> bj;
//long long sum[MAXN];
inline int read(){
	char x=getchar();int t=0;
	while(!isdigit(x))x=getchar();
	while(isdigit(x))t=(t<<3)+(t<<1)+(x^48),x=getchar();
	return t;
}
int dfs(int x,int last)
{
	if(x==a)
	{
		int to=0;
		for(register int i=1;i<=a;++i)
		if(!bj[i]){to=i;break;}
		if(to==last+1||to==last-1)return 0;
		que[a]=to;
//		for(register int i=1;i<=a;++i)
//		{
//			printf("%d ",que[i]);
//		}
//		puts("");
		return 1;
	}
	long long ans=0;
	if(val[x])
	{
		for(int i=1;i<=a;++i)
		{
			if(bj[i])continue;
			if(last==i-1||last==i+1)continue;
			bj[i]=1,que[x]=i;
			(ans+=dfs(x+1,i))%=modd;
			bj[i]=0;
		}
	}
	else
	{
		if(!bj[last+1]&&last+1<=a)que[x]=last+1,bj[last+1]=1,(ans+=dfs(x+1,last+1))%=modd,bj[last+1]=0;
		if(!bj[last-1]&&last-1>0)que[x]=last-1,bj[last-1]=1,(ans+=dfs(x+1,last-1))%=modd,bj[last-1]=0;
	}
	return ans%modd;
}
int main()
{
	freopen("gap.in","r",stdin);
	freopen("gap.out","w",stdout);
	a=read();
	for(register int i=1;i<=a;++i)num[i]=read();
	for(register int i=1;i<=a;i+=num[i])val[i]=1;
//	for(register int i=1;i<=a;++i)cout<<val[i];
//	puts("");
	long long ans=0;
	printf("%lld",dfs(0,a+10));
	return 0;
	/*
	sum[0]=1;
	a=read();
	for(register int i=1;i<=a;++i)(sum[i]=sum[i-1]*i)%modd;
	for(register int i=1;i<=a;++i)num[i]=read();
	for(register int i=1;i<=a;++i)len[num[i]]++,i+=num[i]-1;
	if(len[1]==a&&a<=3)puts("0");
	else if(len[a]=1)puts("2");
	else
	{
		IDK ;D 
	}
	return 0;*/
}
