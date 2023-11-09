#include<bits/stdc++.h>
#define int long long
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
inline int read(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w; 
}
inline void FRE(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
}
const int maxn=1e6+5;
const int mod=1e9+7;
int n,ans=0,ans1,ans2,ANS;
int s1,MAX;
bool flag=1;
int val[maxn],dis[100][100];
vector<int> a[maxn]; 
inline int qpow(int a,int b){
	int sum=1;
	while(b){
		if(b&1)sum=(sum*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	} 
	return sum;
}
inline void dfs1(int Val){
	mem(val,0);ans1=ans2=0;
	for(int i=0;i<n;++i)if((Val>>i)&1)val[i+1]=1;
	for(int i=1;i<n;++i){
		for(int j=1;j<=n;++j){
			if(val[i]==val[j]){
				if(val[i]==0){
					ans1=max(ans1,dis[i][j]);
				}
				else{
					ans2=max(ans2,dis[i][j]);
				}
			}
		}
	}
	ans+=max(ans1,ans2);
}
signed main(){
	FRE();
	n=read();
	mem(dis,0x3f); 
	for(int i=0;i<=n;++i)dis[i][i]=0;
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		if(u+1!=v)flag=0;
		dis[u][v]=dis[v][u]=min(dis[u][v],(int)1);
	}
	if(n<=10){  
		for(int k=1;k<=n;++k){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}                                   
		for(int i=0;i<(1<<n);++i)dfs1(i);
		printf("%lld\n",ans);
		return 0;
	}
	if(flag){
		int a=1,b,c,d=n;
		for(int i=(n-1)/2;i<n-1;++i){
			b=a+i;
			c=n-i;
			int SUM=b-c; 
			if(SUM<0){
				ANS+=i*2;
				continue;
			}
			int ss=qpow(2,SUM+2);
			ss-=qpow(2,SUM);
			if(SUM==0)ss++;
			ANS=(ANS+(i*ss))%mod; 
		}         
		ANS=(ANS+(n-1)*qpow(2,n-1)%mod)%mod;
		printf("%lld",ANS);    
		return 0;          
	}   
	puts("1145141919810");
}
/*
2 
1 2
*/
/*
6
1 2 
2 3
3 4
4 5
3 6
*/
/*
10
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
*/

	
