//the code is from chenjh
#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef unsigned long long ULL;
template<const unsigned int p>struct myhash{
	int len;
	ULL pn[MAXN],hs[MAXN];
	myhash(int _len=0,const char * s=nullptr):len(_len){
		pn[0]=1;
		for(int i=1;i<MAXN;i++) pn[i]=pn[i-1]*p;
		for(int i=1;i<=len;i++) hs[i]=hs[i-1]*p+(unsigned)s[i];
	}
	ULL sub(const int l,const int r){return hs[r]-hs[l-1]*pn[r-l+1];}
	bool same(const int l1,const int r1,const int l2,const int r2){return sub(l1,r1)==sub(l2,r2);}
};
int n;
char s[MAXN];
vector<int> v[130];
int main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	myhash<1572869> h1(n,s);
	myhash<998244353> h2(n,s);
//	fprintf(stderr,"%llu %llu\n",h1.sub(3,5),h1.sub(6,8));
//	fprintf(stderr,"%d %d\n",h1.same(1,2,13,14),h2.same(1,2,13,14));
	for(int i=1;i<=n;i++) v[(int)s[i]].emplace_back(i);
	for(int i=1,w;i<=n;i++){
		w=0;
		for(auto it=v[(int)s[i]].rbegin();it!=v[(int)s[i]].rend();++it){
			int x=n-(*it)+1;
			if(x*3>=n-i+1) break;
			w+=(h1.same(i,i+x-1,i+x,i+(x<<1)-1)&&h2.same(i,i+x-1,i+x,i+(x<<1)-1)&&h1.same(i,i+x-1,n-x+1,n)&&h2.same(i,i+x-1,n-x+1,n));
		}
		printf("%d ",w);
	}
	return 0;
}

/*
bool isprime(const int x){
	if(x<2) return 0;
	for(int i=2;(long long)i*i<=x;i++)if(!(x%i)) return 0;
	return 1;
}
*/
