#include<stdio.h>
#include<bitset>


template <typename dy> dy max(dy x,dy y){return x>y?x:y;}
template <typename dy> dy min(dy x,dy y){return x<y?x:y;}
#define int long long
const int N=2e5+5,mod=998244353;
int gcd(int x,int y){return !x?y:gcd(y%x,x);}
int ksm(int x,int y){
	int s=1;
	while(y){
		if(y&1) (s*=x%mod)%=mod;
		(x*=x%mod)%=mod;y>>=1; 
	}
	return s;
}
int n,m,a[N],s[N],ci,sans,cnt;
void dfs(int u,int r){
	if(u==r+1){
		int x=0;
		for(int i=0;i<ci;i++) x=gcd(s[i],x);
//		if(x==8){
//			for(int i=0;i<ci;i++) printf("%lld ",s[i]);
//			printf("\n%lld\n----------------\n",x);	
//			cnt++;
//		}
	
		if(x) (sans*=x%mod)%=mod;
		return ;
	}
	s[ci++]=a[u];dfs(u+1,r);ci--;
	dfs(u+1,r);
}
//std::bitset<N> sum1[N<<1];
//void push_up(int rt){
//	sum1[rt]=sum1[rt*2]|sum1[rt*2+1];
////	sum2[rt]=sum2[rt*2]^sum2[rt*2+1];
//}
//void build(int rt,int l,int r){
//	if(l==r){
//		for(int i=2;i*i<=a[l];i++){
//			if(a[l]%i==0){
//				sum1[rt][i]=1;
//				sum1[rt][a[l]/i]=1;
////				sum2[rt][i]=1;
////				sum2[rt][a[l]/i]=1;
//			}
//		}
//		return ;
//	}
//	int mid=l+r>>1;
//	build(rt*2,l,mid);
//	build(rt*2+1,mid+1,r);
//	push_up(rt);
//}
signed main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	scanf("%lld%lld",&n,&m);int ma=0;
	for(int i=1;i<=n;i++) {scanf("%lld",&a[i]);ma=max(ma,a[i]);}
//	ans=1;dfs(1,5);
//	printf("%lld %lld\n",ans,cnt);
//	printf("%lld",ksm(8,7)*ksm(2,8)%mod*9%mod);
	while(m--){
		int l,r,f[N]={},ans=1;scanf("%lld%lld",&l,&r);
		if(n<=17){
			sans=1;dfs(l,r);
			printf("%lld\n",sans);
		}
		else{
			for(int i=l;i<=r;i++) f[a[i]]++;
			for(int i=ma;i>=2;i--){
				int t=0;
				for(int j=l;j<=r;j++){
					if(a[j]%i==0){
	//					if(f[i]) a[j]=1;
						t++;
					}
				}
//				if(f[i]) printf(":%d %d\n",i,t);
				if(t){
					if(f[i]) (ans*=ksm(i,(ksm(2,f[i])-1)*ksm(2,t-f[i])))%=mod;
	//				else if(t>1) ans*=i;
					
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
