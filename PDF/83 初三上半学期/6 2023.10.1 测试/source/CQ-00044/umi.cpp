//我们应该将同色联通段一起计算
//首先选出来这些Iskermon,C(m,d*2)
//之后乘上每个联通段的贡献 
//C,每个段的贡献怎么算
//他就是要求每个前缀中A的数量不少于B的数量
//那不就卡特兰数?
//来个极限现推:T(x)=xT(x)^2+1,G(x)=T(x)-1,则G(x)=x(G(x)+1)^2,那么[x^n]G(x)=[x^{n-1}]((x+1)^2n)/n=C(2n,n-1)/n?
//check一下是对的
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=998244353;
auto qpow=[](ll p,ll t){ll res=1;for(;t;t>>=1,p=p*p%mod)if(t&1)(res*=p)%=mod;return res;};
ll fac[1000010],ifac[1000010],f[100010];//长i的联通段的贡献 
auto C=[](int n,int m){return m<0||m>n?0ll:fac[n]*ifac[m]%mod*ifac[n-m]%mod;};
int n,m,q;
void init(){
	fac[0]=1;for(int i=1;i<=m;i++)fac[i]=fac[i-1]*i%mod;
	ifac[m]=qpow(fac[m],mod-2);for(int i=m-1;i>=0;i--)ifac[i]=ifac[i+1]*(i+1)%mod;
	f[0]=1;for(int i=1;i<=n;i++)f[i]=C(i*2,i-1)*qpow(i,mod-2)%mod;
}
struct info_t{
	int len,llen,lc,rlen,rc;ll w;
	info_t operator+(const info_t&o)const{
		if(len==0)return o;
		if(o.len==0)return *this;
		info_t A=*this,B=o,res{A.len+B.len,A.llen,A.lc,B.rlen,B.rc,1};int tr=A.rlen;
		if(A.llen==A.len)A.rlen=0,res.llen=A.len+(A.rc==B.lc?B.llen:0);
		if(B.rlen==B.len)B.llen=0,res.rlen=B.len+(A.rc==B.lc?tr:0);
		res.w=A.w*B.w%mod*(A.rc==B.lc?f[A.rlen+B.llen]:f[A.rlen]*f[B.llen]%mod)%mod;
		return res;
	}
	info_t rev()const{return{len,rlen,rc,llen,lc,w};}
	ll val()const{return len==llen?f[llen]:w*f[llen]%mod*f[rlen]%mod;}
}mkif[2]{{1,1,0,1,0,1},{1,1,1,1,1,1}},emp{0,0,0,0,0,1},up[100010][25];
int fa[100010][25],dep[100010],a[100010];
vector<int>G[100010];
void dfs(int u,int dad){
	dep[u]=dep[dad]+1;up[u][0]=mkif[a[u]];fa[u][0]=dad;
	for(int i=1;i<=20;i++)
	fa[u][i]=fa[fa[u][i-1]][i-1],up[u][i]=up[u][i-1]+up[fa[u][i-1]][i-1];
	for(int v:G[u])if(v!=dad)dfs(v,u);
}
ll calc(int u,int v){
	int ds=dep[u]+dep[v];info_t l=emp,r=emp;
	if(dep[u]<dep[v])swap(u,v);
	for(int i=20;i>=0;i--)
	if(dep[fa[u][i]]>=dep[v])
	l=l+up[u][i],u=fa[u][i];
	if(u==v)return(l+up[v][0]).val()*C(m,ds-dep[u]*2+1<<1)%mod;
	for(int i=20;i>=0;i--)
	if(fa[u][i]!=fa[v][i])
	l=l+up[u][i],u=fa[u][i],
	r=r+up[v][i],v=fa[v][i];
	return(l+up[u][0]+up[fa[u][0]][0]+(r+up[v][0]).rev()).val()*C(m,ds-dep[fa[u][0]]*2+1<<1)%mod;
}
int main(){
	freopen("umi.in","r",stdin);
	freopen("umi.out","w",stdout);
	scanf("%d%d%*d",&n,&m);
	init();
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1,u,v;i<n;i++)
	scanf("%d%d",&u,&v),G[u].push_back(v),G[v].push_back(u);
	dfs(1,0);cin>>q;
	for(int u,v;q--;)
	scanf("%d%d",&u,&v),printf("%lld\n",calc(u,v));
	return 0;
}
