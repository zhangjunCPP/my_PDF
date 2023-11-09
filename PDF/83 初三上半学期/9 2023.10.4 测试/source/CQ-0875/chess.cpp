#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int p,k,ans,n,pw[1000000];
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);	
	scanf("%d%d",&p,&k);
	pw[0]=1; for(int i=1;i<=2*k;++i) pw[i]=pw[i-1]*p;
	n=pw[k]-1;
	for(int i=1;i<=k;++i) ans+=pw[k-i]*pw[(i-1)<<1];
	printf("%d\n",ans);
	for(int i=0;i<=n;++i){
		printf("%d ",i);
		if((i+1)%p==0) puts("");
	}
	for(int now=2;now<=k;++now){
		for(int st=0;st<=n;st+=pw[now])
			for(int x=st;x<st+pw[now-1];++x)
				for(int i=st+pw[now-1];i<st+2*pw[now-1];++i){
					printf("%d %d ",x,i);
					for(int j=x+2*pw[now-1];j<st+pw[now];j+=pw[now-1]) printf("%d ",j);
					puts("");
				}
		
	}
	
	return 0;
}
