/*
Sakurajima Mai,
Eriri Spencer,
Izumi Sagiri,
Keqing,
Hu tao,
Ganyu
say,"With our sincere wishes to HHX: never to debug code"
*/

#include<bits/stdc++.h>
#define int long long 
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
} 
int n,q,dis[150][150]; 
inline int dot(int i,int j){ return i*n+j; }
inline void want_50pts(){
	for (int i=0;i<=n*n+n;i++)
	for (int j=0;j<=n*n+n;j++)
		if (i!=j) dis[i][j]=0x3f3f3f3f3f3f3f3f;
	for (int i=0;i<=n;i++)
	for (int j=0;j<=n;j++){
		if (j==0){
			dis[dot(i,j)][dot(i,n)]=1;
			dis[dot(i,j)][dot(i,j+1)]=1;
		} else if (j==n){
			dis[dot(i,j)][dot(i,j-1)]=1;
			dis[dot(i,j)][dot(i,0)]=1;
		} else{
			dis[dot(i,j)][dot(i,j-1)]=1;
			dis[dot(i,j)][dot(i,j+1)]=1;
		}
		if (i==0){
			dis[dot(i,j)][dot(n,n-j)]=1;
			dis[dot(i,j)][dot(i+1,j)]=1;
		} else if (i==n){
			dis[dot(i,j)][dot(i-1,j)]=1;
			dis[dot(i,j)][dot(0,n-j)]=1;
		} else{
			dis[dot(i,j)][dot(i-1,j)]=1;
			dis[dot(i,j)][dot(i+1,j)]=1;
		}
	}
	for (int k=0;k<=n*n+n;k++)
	for (int i=0;i<=n*n+n;i++)
	for (int j=0;j<=n*n+n;j++)
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while (q--){
		int x=read(),y=read(),xx=read(),yy=read();
		printf("%lld\n",dis[dot(x,y)][dot(xx,yy)]);
	}
	exit(0);
}
signed main(){
	freopen("klein.in","r",stdin);
	freopen("klein.out","w",stdout);
	n=read(),q=read();
	if (n<=10) want_50pts();
	while (q--){
		int x=read(),y=read(),xx=read(),yy=read();
		int ct1=(int)abs(x-xx)+min((int)abs(y-yy),n-(int)abs(y-yy)+1);
		int to=n-yy,pt=min((int)abs(y-to),n-(int)abs(y-to)+1);
		int ct2=pt+x+1+(int)abs(n-xx);
		int ct3=pt+(n-x+1)+(int)abs(0-xx);
		printf("%lld\n",min(ct1,min(ct2,ct3)));
	}
	return 0;
}

