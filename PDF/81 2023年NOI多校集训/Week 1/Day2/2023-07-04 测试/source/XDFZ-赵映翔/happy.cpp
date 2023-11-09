#include<bits/stdc++.h>
using namespace std;
int n,k,one,t[100001],num[501],cost[501],lst[501];
long long sum[100001];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline long long Min(long long a,long long b){
	return (a<=b?a:b);
}
int main(){
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	
	n=read(),k=read();
	for(int i=1;i<=n;i++) t[i]=read();
	for(int i=1;i<=k;i++) num[i]=read(),cost[i]=read();
	one=read();
	for(int i=1;i<=k;i++) lst[i]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++) while(lst[j]+1<=i&&t[i]-num[j]+1>t[lst[j]]) lst[j]++;
		sum[i]=sum[i-1]+one;
		for(int j=1;j<=k;j++) sum[i]=Min(sum[i],sum[lst[j]-1]+1ll*cost[j]);
	}
	for(int i=1;i<=n;i++) printf("%lld\n",sum[i]-sum[i-1]);
	return 0;
}
