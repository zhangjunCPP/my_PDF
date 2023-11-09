/*
T1不是zyx鸽着没做的那道吗???6
考虑扫过去,然后权值是a^(2^c-1) 
莫队会带log啊...
可以把前面k个素数不用莫队单独处理!
处理到19就差不多了.
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=998244353;
constexpr int mxv=2e5,B=200;
auto qpow=[](ll p,ll t){ll res=1;for(;t;t>>=1,p=p*p%mod)if(t&1)(res*=p)%=mod;return res;};
auto qpow2=[](ll x){return x*x%mod;};
struct Q_{int id,l,r;}ques[200010];
int n,m,a[200010],p[200010],cnt[200010],smt[B][200010],pt;
basic_string<int>fac[200010];
void init(){
	for(int i=2;i<=mxv;i++)
	if(!p[i]){p[pt++]=i;
		for(int j=i,x;j<=mxv;j+=i){
			int c=0;for(x=j;x%i==0;x/=i)c++;
			if(pt<=B)smt[pt-1][j]=c;
			else for(int k=j/x;k>1;k/=i)
			fac[j]+=k;
			p[j]=1;
		}
	}
}
ll ans[200010];
basic_string<ll>vpow[200010],ivpow[200010];
ll*lhz[200010],*ilhz[200010];
void mosolve(){
	sort(ques+1,ques+m+1,[blk=int(n/sqrt(m/3.0)+1)](Q_ x,Q_ y){return x.l/blk==y.l/blk?((x.l/blk)&1?x.r>y.r:x.r<y.r):x.l<y.l;});
	ll now=1;
	for(int i=1;i<=n;i++)lhz[i]=&vpow[i][0],ilhz[i]=&ivpow[i][0];
//	auto add=[&](int v){for(int x:fac[v])(now*=vpow[x][cnt[x]++])%=mod;};
//	auto del=[&](int v){for(int x:fac[v])(now*=ivpow[x][--cnt[x]])%=mod;};
	auto add=[&](int v){for(int x:fac[v])(now*=*lhz[x]++)%=mod,ilhz[x]++;};
	auto del=[&](int v){for(int x:fac[v])(now*=*--ilhz[x])%=mod,lhz[x]--;};
	for(int i=1,l=1,r=0;i<=m;i++){
		while(l>ques[i].l)add(a[--l]);
		while(r<ques[i].r)add(a[++r]);
		while(l<ques[i].l)del(a[l++]);
		while(r>ques[i].r)del(a[r--]);
		ans[ques[i].id]=now;
	}
}
void solve2(){
	for(int idx=0;idx<B;idx++){
		ll _=p[idx];int c=0;
		for(int i=1;i<=n;i++)c+=!!smt[idx][a[i]];
		vector<ll>w(c+5,1);
		for(int i=1;i<=c;i++)w[i]=w[i-1]*_%mod,_=_*_%mod;
		for(int t=1;;t++){
			for(int i=1;i<=n;i++)
			cnt[i]=cnt[i-1]+(smt[idx][a[i]]>=t);
			if(!cnt[n])break;
			for(int i=1;i<=m;i++)
			(ans[ques[i].id]*=w[cnt[ques[i].r]-cnt[ques[i].l-1]])%=mod;
		}
	}
}
char buf[1<<22],*ptr=buf+(1<<22),*ed=ptr;
auto readi=[](){
	if(ed-ptr<20){
		char*newptr=buf;
		for(;ptr!=ed;*newptr++=*ptr++);
		ptr=newptr;fread(ptr,1,ed-ptr,stdin);
	}
	int x=0;char c=*ptr++;
	while(!isdigit(c))c=*ptr++;
	while(isdigit(c))x=x*10+c-'0',c=*ptr++;
	return x;
};
int main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	init();
	n=readi(),m=readi();int mx=0;
	for(int i=1;i<=n;i++)a[i]=readi(),mx=max(mx,a[i]);
	for(int i=1;i<=m;i++)
	ques[i].l=readi(),ques[i].r=readi(),ques[i].id=i;
	for(int i=2,x;i<=mxv;i++)
	if(!fac[i].empty())x=fac[i].back(),vpow[i]={x},ivpow[i]={qpow(x,mod-2)};
	for(int i=1;i<=n;i++)
	for(int x:fac[a[i]])vpow[x]+=qpow2(vpow[x].back()),ivpow[x]+=qpow2(ivpow[x].back());
	if(mx>450)mosolve();solve2();
	for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
	return 0;
}
