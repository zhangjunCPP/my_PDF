#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=2e3+10;
int p,k,n;
LL res;
int my_pow(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a;
		a=a*a,b>>=1;
	}
	return res;
}
int vis[N];
vector<int> cho;
void dfs(int now){
	if(now>p){
		for(int i=0;i<p;++i)printf("%d ",cho[i]-1);
		printf("\n");return;
	}
	for(int i=now;i<=n;i+=p)
		if(!vis[(i-now)/p+1])vis[(i-now)/p+1]=1,cho.push_back(i),dfs(now+1),vis[(i-now)/p+1]=0,cho.pop_back();
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	p=read(),k=read(),n=my_pow(p,k),res=1ll;
	if(k==1){
		printf("1\n");
		for(int i=0;i<p;++i)printf("%d ",i);
	}else if(k==2){
		for(LL i=p;i;--i)res*=i;
		int round=my_pow(p,k-1);
		printf("%lld\n",round*2ll+res);
		for(int i=1;i<=round;++i){
			for(int j=(i-1)*round+1;j<=i*round;++j)printf("%d ",j-1);
			printf("\n");
		}
		for(int i=1;i<=round;++i){
			int now=i,tur=0;
			for(int j=i;j<=n;j+=p){
				printf("%d ",j-1);++tur;
				if(tur==p){tur=0;printf("\n");}
			}
		}
		dfs(1);
//		for(int i=1;i<=p;++i){
//			for(int j=2;j<=round;++j){
//				for(int z=1;z<=p;++z){
//					if(!vis[z]){
//						vis[z]=1;printf(" %d",(z-1)*round+j);break;
//					}
//				}
//			}
//		}
	}else if(p==2){
		int round=my_pow(p,k-1);
		printf("%lld\n",n*(n-1)/2);
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				printf("%d %d\n",i-1,j-1);
	}
//	for(LL i=p;i;--i)res*=i;
//	int round=my_pow(p,k-1);
//	printf("%lld\n",round*2ll+res*my_pow(p,k-2)*);
//	for(int i=1;i<=round;++i){
//		for(int j=(i-1)*round+1;j<=i*round;++i)printf("%d ",j);
//		printf("\n");
//	}
//	for(int i=1;i<=round;++i){
//		int now=i,tur=0;
//		for(int j=i;j<=n;j+=p){
//			printf("%d ",j);++tur;
//			if(tur==p){tur=0;printf("\n");}
//		}
//	}
//	
	return 0;
}
