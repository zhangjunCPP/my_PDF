#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=45,MAXM=1e5+10;
const int mod=998244353;
template <typename T>
inline void read(T &x){
	bool f=0; x=0; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=1; ch=getchar();}
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x=f?-x:x;
}
template <typename T,typename ...Args>
inline void read(T &x,Args &...args){read(x); read(args...);}
int n,k;
ll sum[MAXN][MAXM],f[MAXN];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n,k);
	for(int x=1;x<=k;x++){
		if(x<n || x>n*(n+1)/2) printf("0 ");
		else{
			int cnt=2,ans=0;
			memset(f,0,sizeof(f)); memset(sum,0,sizeof(sum));
			f[0]=1; for(int i=1;i<=n;i++) f[i]=f[i-1]*2%mod;
			sum[1][0]=1; sum[1][1]=1;
			for(int i=1;i<=n;i++){
				for(int j=0;j<cnt;j++){
					sum[i][j+cnt]=sum[i][j]+1;
					sum[i][j+cnt*2+1]=sum[i][j+cnt]+1;
					if(sum[i][j]!=x && i==n) ans++; 
				}
				cnt+=2; 
			}
			printf("%lld ",f[n]-ans);
		}
	}
	return 0;
}
