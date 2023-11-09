//the code is from chenjh
#include<cstdio>
#include<algorithm>
#include<map>
#include<utility>
#define MAXN 100005
#define lson (rt<<1)
#define rson (rt<<1|1)
typedef long long LL;
typedef std::map<int,int> MII;
typedef std::pair<int,int> PII;
const int mod=998244353;
inline int qpow(int a,int b,int p){
	int ret=1;
	for(;b;b>>=1,a=1ll*a*a%p)if(b&1)ret=1ll*ret*a%p;
	return ret%p;
}
int n,q;
int a[MAXN];
MII s[MAXN<<2];
void Max(MII& ret,const MII&tmp){
	for(PII it:tmp) ret[it.first]=std::max(ret[it.first],it.second);
}
void build(int rt,int l,int r){
	if(l==r){
		int A=a[l];
		for(int i=2;i*i<=A;i++)
			if(!(A%i)){
				int c=0;
				for(;!(A%i);A/=i)++c;
				s[rt][i]+=c;
			}
		if(A>1) ++s[rt][A];
		return;
	}
	int mid=(l+r)>>1;
	build(lson,l,mid),build(rson,mid+1,r);
	Max(s[rt],s[lson]),Max(s[rt],s[rson]);
//	for(PII it:s[lson]) s[rt][it.first]=max(s[rt][it.first],it.second);
//	for(PII it:s[rson]) s[rt][it.first]=max(s[rt][it.first],it.second);
}
MII query(int rt,int l,int r,int L,int R){
	if(L<=l && r<=R) return s[rt];
	int mid=(l+r)>>1;
	MII ret; ret.clear();
	if(L<=mid){
		MII tmp(query(lson,l,mid,L,R));
		Max(ret,tmp);
	}
	if(mid<R){
		MII tmp(query(rson,mid+1,r,L,R));
		Max(ret,tmp);
	}
	return ret;
}
/*
MII operator + (MII A,const MII&B){
	for(PII it:B) A[it.first]+=it.second;
	return A;
}
MII operator += (MII&A,const MII&B){return A=A+B;}
MII operator - (MII A,const MII&B){
	for(PII it:B) A[it.first]-=it.second;
	return A;
}
MII operator -= (MII&A,const MII&B){return A=A-B;}
#define lb(X) (X&-X)
void add(int x,const MII&v){for(;x<=n;x+=lb(x))s[x]+=v;}
void build(int x,int v){
	MII ret;ret.clear();
	for(int i=2;i*i<=v;i++){
		if(!(v%i)){
			int c=0;
			for(;!(v%i);v/=i)++c;
			ret[i]+=c;
		}
	}
	if(v>1) ++ret[v];
	add(x,ret);
}
MII ask(int x){
	MII ret;ret.clear();
	for(;x;x^=lb(x))ret+=s[x];
	return ret;
}
int query(int l,int r){
	
}
*/
int main(){
	freopen("boring.in","r",stdin);
	freopen("boring.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n);
	for(int k;q--;){
		scanf("%d",&k);
		MII ans;ans.clear();
		for(int l,r;k--;){
			scanf("%d%d",&l,&r);
			Max(ans,query(1,1,n,l,r)); 
		}
		long long ret=1;
		for(PII it:ans){
			ret=ret*qpow(it.first,it.second,mod)%mod;
		}
		printf("%lld\n",ret);
	}
	return 0;
}
/*
//the code is from chenjh
#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long LL;
const int mod=998244353;
inline int gcd(const int a,const int b){return b?gcd(b,a%b):a;}
inline int qpow(int a,int b,int p){
	int ret=1;
	for(;b;b>>=1,a=1ll*a*a%p)if(b&1)ret=1ll*ret*a%p;
	return ret%p;
}
inline int inv(const int a,const int p){return qpow(a,p-2,p);} 
int n,q;
int a[MAXN],s[MAXN];//数列 a 与前缀积。  
int g[MAXN],t[MAXN][20];//预处理 log2，ST 表存 lcm。 
inline int query(int l,int r){
	int k=g[r-l+1];
//	return gcd(t[l][k],t[r-(1<<k)+1][k]);
//	直接查询最小公倍数。
	 
}
//
//inline int lcm(int l,int r){
//	if(l==r) return a[l];//查询一个，最小公倍数等于自身。 
//	LL S=(LL)s[r]*inv(s[l-1],mod)%mod;//乘积。
//	int G=query(l,r);
//	return S*inv(G,mod)%mod;
//}

int main(){
//	freopen("boring.in","r",stdin);
//	freopen("boring.out","w",stdout);
	scanf("%d%d",&n,&q);
	s[0]=1;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),s[i]=(LL)s[i-1]*a[i]%mod,t[i][0]=a[i];
	for(int i=2;i<=n;i++) g[i]=g[i>>1]+1;
	for(int k=1;k<=g[n];k++)for(int i=1,mi=n+1-(1<<k);i<=mi;i++){
		
		t[i][k]=gcd(t[i][k-1],t[i+(1<<(k-1))][k-1]);
	}
	for(int k;q--;){
		scanf("%d",&k);
		int l,r;scanf("%d%d",&l,&r);
		LL S=lcm(l,r);//答案。
		if(k==1){printf("%lld\n",S);continue;}
		printf("l = %d, r = %d: lcm = %lld.\n",l,r,S);
		while(--k){
			scanf("%d%d",&l,&r);
			int LCM=lcm(l,r);
			S=S*inv(gcd(S,LCM),mod)*LCM%mod;
			printf("l = %d, r = %d: lcm = %d.\n",l,r,LCM);
		}
//		printf("Finally: gcd = %d, S = %lld.\n",G,S);
		printf("%lld\n",S);
	}
	return 0;
}
*/
