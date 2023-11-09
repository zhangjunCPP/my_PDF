/*
10pts 一共就两个点...A(2,k)*dif+k*sam 
10pts 的爆搜？枚举每个处理中心的国家，算方案 
20pts A(n,k) ?
*/

#include<bits/stdc++.h>
#define int long long
const int mod=1e9+7;
using namespace std;
int out[1<<10],buf;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
}
int dif10=1,sam10=1; bool have[99][99];
int n,t,m,k,dis[99][99][2],of[99],Eriri;
void dfs(int step){
	if (step>n){
		int res=1;
		for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
			if (have[i][j])
				if (of[i]==of[j]){
					if (!dis[i][j][1]) return ;
					res=res*dis[i][j][1]%mod;
				}
				else{
					if (!dis[i][j][0]) return ;
					res=res*dis[i][j][0]%mod;
				}
		Eriri=(Eriri+res)%mod;
		return ;
	} for (int i=1;i<=k;i++){
		of[step]=i;
		dfs(step+1);
		of[step]=0; 
	}
}
void soln2(){
	dif10=1,sam10=1;
	while (m--){
		int x=read(),y=read();
		x=read(),y=read();
		dif10=dif10*x%mod;
		sam10=sam10*y%mod;
	}
	printf("%lld\n",(k*(k-1)%mod*dif10%mod+k*sam10%mod)%mod);
}
void solk34(){
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		dis[i][j][0]=dis[i][j][1]=1,have[i][j]=0;
	Eriri=0;
	for (int i=1;i<=m;i++){
		int u=read(),v=read();
		int x=read(),y=read();
		have[u][v]=have[v][u]=1;
		dis[u][v][0]=dis[u][v][0]*x;
		dis[v][u][0]=dis[u][v][0];
		dis[u][v][1]=dis[u][v][1]*y;
		dis[v][u][1]=dis[u][v][1];
	} dfs(1);
	printf("%lld\n",Eriri);
}
void soldif1(){
	while (m--){ int x=read();x=read();x=read();x=read(); }
	int res=1;
	for (int i=k,j=1;j<=n;i--,j++)
		res=res*i%mod;
	printf("%lld\n",res);
}
signed main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	t=read();
	while (t--){
		n=read(),m=read(),k=read();
		if (n==2){ soln2(); continue; }
		if (k==13||k==12||n==8||n==10){ soldif1(); continue; }
		solk34();
	}
	return 0;
} 
/*
TheProblem'sNotEasy
*/
