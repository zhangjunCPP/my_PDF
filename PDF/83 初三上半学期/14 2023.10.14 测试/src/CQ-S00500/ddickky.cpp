//the code is from chenjh
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<utility>
#include<vector>
#define MAXN 200002
using namespace std;
typedef long long LL;
inline void read(int&x){
	x=0;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;'0'<=ch&&ch<='9';ch=getchar())x=x*10+(ch^'0');
}
inline void write(LL x){
	static short stk[20];
	int p=0;
	for(;x;x/=10)stk[++p]=x%10;
	while(p)putchar(stk[p--]|'0');
}
const int mod=998244353;
inline int qpow(int a,int b,const int p){
	int r=1;
	for(;b;b>>=1,a=(LL)a*a%p)if(b&1)r=(LL)r*a%p;
	return r;
}
bool vis[MAXN];
int p[MAXN],tot=0;
void getprime(){
	for(int i=2;i<MAXN;i++){
		if(vis[i]) continue;
		p[++tot]=i;
		for(int j=i;(long long)i*j<MAXN;j++) vis[i*j]=1;
	}
//	fprintf(stderr,"Total: %d\n",tot);
}
//在 1~200000 中仅有 17984 个质数。 
int n,q;
int a[MAXN];
//unordered_map<int,int> c[MAXN];
vector<int> v[18000][20];
unordered_map<int,bool> b;
int d[20];
int main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	getprime();
//	scanf("%d%d",&n,&q);
	read(n),read(q);
	for(int i=1;i<=n;i++){
//		scanf("%d",&a[i]);
		read(a[i]);
		int j;
		for(j=1;j<=tot && p[j]<=a[i] && vis[a[i]];j++){
			if(!(a[i]%p[j])){
				int ct=0;
				for(;!(a[i]%p[j]);a[i]/=p[j]) ++ct;
//				c[i][p[j]]=ct;
				v[j][ct].emplace_back(i);
				b[j]=1;
			}
		}
		if(a[i]>1){
//			c[i][a[i]]=1;
			for(;j<=tot && p[j]<a[i];j++);
			if(p[j]==a[i]) v[j][1].emplace_back(i),b[j]=1;
		}
	}
	for(int l,r;q--;){
//		scanf("%d%d",&l,&r);
		read(l),read(r);
		LL ans=1;
		for(const pair<int,bool> J:b){
			int j=J.first; 
			if(b[j]){
				int s=0;
				for(int k=1,mk=min(int(log(MAXN)/log(j))+2,20);k<mk;k++){
					d[k]=0;
					if(!v[j][k].empty())
						s+=(d[k]=int(
							(upper_bound(v[j][k].begin(),v[j][k].end(),r)-v[j][k].begin())
							-(lower_bound(v[j][k].begin(),v[j][k].end(),l)-v[j][k].begin())
						));
				}
	//			fprintf(stderr,"%d: ",p[j]);
	//			for(int k=1;k<20;k++) fprintf(stderr,"%d ",d[k]);
	//			fprintf(stderr,"\n%d\n",s);
				LL tmp=p[j];
				if(s){
					for(int k=1,mk=min(int(log(MAXN)/log(j))+2,20);k<mk;k++,tmp=tmp*p[j]%mod)if(d[k]){
						s-=d[k];
						LL cc=((LL)qpow(2,d[k],mod-1)-1+mod-1)%(mod-1)*qpow(2,s,mod-1)%(mod-1);
						ans=ans*qpow(tmp,cc,mod)%mod;
					}
				}
			}
		}
//		printf("%lld\n",ans);
		write(ans),putchar('\n');
	}
	return 0;
}

