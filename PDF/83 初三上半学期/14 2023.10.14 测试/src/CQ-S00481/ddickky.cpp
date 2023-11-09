#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define i64 __int128
#define lowbit(i) i&(-i)
const int N = 2e5+5,mod = 998244353,M = 225;
int n,nB,vB,V,nl,nr,T,tot,len,a[N],pri[N/10],vis[N],b[N],cnt[N];
int s[M][N],val[M],base[M],pw2[N],pt[N];
ll ans;
void prework(){
	for(ll i=2;i<=V;i++){
		if(!vis[i]){
			pri[++tot] = i,b[i] = i;
			for(ll j=2*i;j<=V;j+=i) vis[j] = 1,b[j] = i;
		}
	}
	for(int i=1;i<=tot;i++){
		if(pri[i]>vB) break;
		int tmp = V,lim = 0;
		while(tmp>=pri[i]) tmp/=pri[i],lim++;
		int now = 1;
		for(int j=1;j<=lim;j++){
			now *= pri[i];
			val[++len] = now;
			base[len] = pri[i];
		}
	}	
}
struct Q{
	int l,r,id;
}q[N];
bool cmp(Q x,Q y){
	int xl = (x.l-1)/nB+1,xr = (x.r-1)/nB+1,yl = (y.l-1)/nB+1,yr = (y.r-1)/nB+1;
	if(xl!=yl) return xl<yl;
	if(xl&1) return xr<yr;
	else return xr>yr; 
}
ll qpow(ll a,ll p){
	ll res = 1;
	for(;p;p>>=1,a=a*a%mod) if(p&1) res = res*a%mod;
	return res;
} 
ll inv(ll x){
	return qpow(x,mod-2);
}
void change(int l,int r){
	while(nl>l){
		nl--;
		if(b[a[nl]]>vB){
			int x = b[a[nl]];
			if(cnt[x]>0) ans *= inv(qpow(x,pw2[cnt[x]]-1)),ans %= mod,cnt[x]++;
			if(cnt[x]>0)ans *= qpow(x,pw2[cnt[x]]-1),ans %= mod;
		}
	}
	while(nl<l){
		if(b[a[nl]]>vB){
			int x = b[a[nl]];
			if(cnt[x]>0) ans *= inv(qpow(x,pw2[cnt[x]]-1)),ans %= mod;
			cnt[x]--;
			if(cnt[x]>0) ans *= qpow(x,pw2[cnt[x]]-1),ans %= mod;
		}
		nl++;
	}
	while(nr<r){
		nr++;
		if(b[a[nr]]>vB){
			int x = b[a[nr]];
			if(cnt[x]>0) ans *= inv(qpow(x,pw2[cnt[x]]-1)),ans %= mod;
			cnt[x]++;
			if(cnt[x]>0) ans *= qpow(x,pw2[cnt[x]]-1),ans %= mod;
		}
	}
	while(nr>r){
		if(b[a[nr]]>vB){
			int x = b[a[nr]];
			if(cnt[x]>0) ans *= inv(qpow(x,pw2[cnt[x]]-1)),ans %= mod;
			cnt[x]--;
			if(cnt[x]>0) ans *= qpow(x,pw2[cnt[x]]-1),ans %= mod;
		}
		nr--;
	}
}
int main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> T;pw2[0] = 1;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=2*n;i++) pw2[i] = 2ll*pw2[i-1]%mod,V = max(V,a[i]);
	nB = sqrt(n),vB = sqrt(V);
	prework();
	for(int i=1;i<=len;i++){
		for(int j=1;j<=n;j++){
			s[i][j] = s[i][j-1]+(a[j]%val[i]==0 && a[j]%(val[i]*base[i])!=0);
		}
	}
	for(int i=1;i<=T;i++) cin >> q[i].l >> q[i].r,q[i].id = i;
	sort(q+1,q+1+T,cmp);
	ans = nl = 1,nr = 0;
	for(int i=1;i<=T;i++){
		change(q[i].l,q[i].r);
		ll now = 0,las = 0;
		ll res = 1;
		for(int j=len;j>=1;j--){
			if(j!=len && val[j+1]%val[j]!=0) las = 0;
			now = s[j][q[i].r]-s[j][q[i].l-1];
			if(now==0) continue;
			res *= qpow(val[j],1ll*(pw2[now]-1)*pw2[las]%(mod-1)),las += now;
			res %= mod;
		}
		pt[q[i].id] = (ans*res)%mod;
	}
	for(int i=1;i<=T;i++) cout << pt[i] << '\n';
	return 0;
}
//ÔõÃ´ÕâÃ´ÄÑ°¡©Ñ©Ò___©Ñ©Ò
//ÔÜrpÔÜrpÔÜrpÔÜrpÔÜrpÔÜrp
//ÔÜrpÔÜrpÔÜrpÔÜrpÔÜrpÔÜrp
//ÔÜrpÔÜrpÔÜrpÔÜrpÔÜrpÔÜrp
//ÔÜrpÔÜrpÔÜrpÔÜrpÔÜrpÔÜrp
//ÔÜrpÔÜrpÔÜrpÔÜrpÔÜrpÔÜrp
//ÔÜrpÔÜrpÔÜrpÔÜrpÔÜrpÔÜrp
