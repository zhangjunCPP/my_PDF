#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N=2e3+17;
int p,k;
ll ans;
int t[N];
ll ppow(ll a,ll b){
	ll ans=1;
	while(b>0){
		if(b&1){
			ans*=a;
		}
		a*=a;
		b>>=1;
	}
	return ans;
}
signed main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&p,&k);
	ll n=ppow(p,k);
	for(int i=1;i<=k;i++){
		ans+=ppow(p,k-i)*ppow(p,(i-1)*2);
	}
	printf("%lld\n",ans);
	for(int len=1;len<n;len*=p){//lenth per chess;
		int part=len*p;//part lenth
		for(int st=1;st<=n;st+=part){//start place of each part
			for(int i=0;i<len;i++){
				for(int T=st;T<st+len;T++){
					int lst=T;
					for(int j=1;j<=p;j++){
						printf("%d ",lst-1);
						lst=lst+i+len;
						if(lst>=st+(j+1)*len){
							lst-=len;
						}
					}
					printf("\n");
				}
			}
		}
//		printf("\n");
	}
	return 0;
}
