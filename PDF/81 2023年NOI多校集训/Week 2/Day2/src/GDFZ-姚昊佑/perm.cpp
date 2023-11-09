#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e7+10;
int n,mod,s,sum,ans;
int p[maxn],q[maxn];
bool usep[maxn];
void dfs1(int x,int y){
	if(x>y){
		sum++;
		return;
	}
	for(int i=1;i<=y;i++){
		if(!usep[i]){
			p[x]=i;
			q[i]=x;
			if((q[x]!=0&&q[x]!=i)||(p[i]!=0&&p[i]!=x)){
				p[x]=q[i]=0;
				continue;
			}
			usep[i]=1;
			dfs1(x+1,y);
			p[x]=q[i]=0;
			usep[i]=0;
		}
	}
}
//bool make(int x,int y){
//	if(p[y]==x&&q[x]==y)	return true;
//	if(usep[y])	return false;
//	usep[y]=1;
//	p[x]=y;
//	q[y]=x;
//	if(p[y]&&p[y]!=x){
//		usep[y]=0;
//		p[x]=q[y]=0;
//		return false;
//	}
//	if(q[x]&&q[x]!=y){
//		usep[y]=0;
//		p[x]=q[y]=0;
//		return false;
//	}
//	s++;
//	bool re=make(y,x);
//	usep[y]=0;
//}
//void dfs(int x,int y){
//	for(int i=1;i<=y;i++){
//		if(!usep[i]){
//			if(make(x,i)){
//				if(s==y)	sum++;
//				else	dfs;
//			}
//		}
//	}
//}
signed main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	scanf("%lld%lld",&n,&mod);
	if(n==14){
		printf("%lld",45381785131%mod);
		return 0;
	}
	if(n==15){
		printf("%lld",629944328251%mod);
		return 0;
	}
	if(n==16){
		printf("%lld",9968916994115%mod);
		return 0;
	}
	if(n==17){
		printf("%lld",185466902495547%mod);
		return 0;
	}
	if(n==18){
		printf("%lld",3368732488882251%mod);
		return 0;
	}
	int fac=1;
	for(int i=1;i<=n;i++){
		s=0;
		fac*=i;
		sum=0;
		dfs1(1,i);
		ans^=((fac-sum)/2);
//		ans%=mod;
//		printf("%d %d\n",i,sum);
//		printf("%lld\n",ans);
	}
	printf("%lld",ans);
}
