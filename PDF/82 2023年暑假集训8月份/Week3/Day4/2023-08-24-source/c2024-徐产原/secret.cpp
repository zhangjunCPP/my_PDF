#include<bits/stdc++.h>
using namespace std;
#define mod 65535
int t,n,k;
int p[20];
void Freopen(){
	freopen("secret.in","r",stdin);
	freopen("secret.out","w",stdout);
}
int power(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)ans=1ll*ans*a%mod;
	return ans;
}
int main(){
	Freopen();
	scanf("%d",&t);
	while(t--){
		n=0;
		scanf("%d",&k);
		if(k==1){
			int a,b;
			scanf("%d%d",&a,&b);
			int sum=0;
			for(int i=1,bit=1;i<=b;i++,bit=1ll*bit*256%mod)
				sum=(sum+1ll*a*bit%mod)%mod;
			printf("%d\n",power(sum,b));
		}
		else{
			int mul=1;
			for(int i=1;i<=k;i++){
				int x,y;
				scanf("%d%d",&x,&y);
				for(int j=1;j<=y;j++)
					mul=1ll*mul*j%mod;
				while(y--)p[++n]=x;
			}
			sort(p+1,p+1+n);
			int ans=1;
			do{
				int sum=0;
				for(int i=1,bit=1;i<=n;i++,bit=1ll*bit*256%mod)
					sum=(sum+1ll*p[i]*bit%mod)%mod;
				ans=1ll*ans*power(sum,mul)%mod;
			}while(next_permutation(p+1,p+1+n));
			
			
			
			printf("%d\n",ans);	
		}
	}
}
