#include<bits/stdc++.h>
using namespace std;
int n,m,b,l=1,r,tot,now=1,w,a[200001],ans[200001],cnt[200001],sum[200001][232],val[200001],id[200001];
vector <pair<int,int> > G[200001];
const int mod=998244353;
struct node{
	int d,l,r;
	bool operator<(node k){
		if(l/b==k.l/b){
			if((l/b)&1) return r<k.r;
			else return r>k.r;
		}
		else return l<k.l;
	}
}q[200001];
struct qpow{
	int g,p1[40001],p2[40001];
	void init(int x,int h){
		p1[0]=p2[0]=1,g=h;
		for(int i=1;i<=40000;i++) p1[i]=1ll*p1[i-1]*x%g;
		for(int i=1;i<=40000;i++) p2[i]=1ll*p2[i-1]*p1[40000]%g;
	}
	int ask(int k){
		return 1ll*p2[k/40000]*p1[k%40000]%g;
	}
}p[101];
int power(int a,int b,int p){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%p) if(b&1) res=1ll*res*a%p;
	return res;
}
void add(int x){
	if(!x) return;
	now=1ll*now*G[x][cnt[x]].first%mod;
	cnt[x]++;
}
void del(int x){
	if(!x) return;
	cnt[x]--;
	now=1ll*now*G[x][cnt[x]].second%mod;
}
void read(int &x){
	char ch=getchar();x=0;
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
}
int main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	
	read(n),read(m),b=sqrt(n);
	for(int i=2;i<=500;i++){
		bool prime=1;
		for(int j=2;j*j<=i;j++) if(i%j==0) prime=0;
		if(prime) id[i]=++tot,val[tot]=i,p[tot].init(i,mod);
	}
	p[96].init(2,mod-1);
	for(int i=tot;i>=1;i--){
		int x=val[i];
		while(x*val[i]<=200000) x*=val[i],id[x]=++tot,val[tot]=val[i];
	}
	for(int i=1;i<=n;i++){
		read(a[i]),w=0;
		for(int j=1;j<=tot;j++) sum[i][j]=sum[i-1][j];
		for(int j=2;j*j<=a[i];j++){
			if(a[i]%j==0){
				if(j<=500){
					int k=1;
					while(a[i]%j==0) k*=j,sum[i][id[k]]++,a[i]/=j;
				}
				else a[i]/=j,w=j;
			}
		}
		if(a[i]>1){
			if(a[i]<=500) sum[i][id[a[i]]]++;
			else w=a[i];
		}
		a[i]=w;
	}
	for(int i=1;i<=m;i++){
		read(q[i].l),read(q[i].r),q[i].d=i,ans[i]=1;
		for(int j=1;j<=tot;j++){
			int s=sum[q[i].r][j]-sum[q[i].l-1][j],e=(p[96].ask(s)-2+mod)%(mod-1);
			if(s!=0) ans[i]=1ll*ans[i]*p[id[val[j]]].ask(e)%mod;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]){
			int e=(power(2,cnt[a[i]],mod-1)-1+mod)%(mod-1);
			G[a[i]].push_back({power(a[i],e,mod),power(power(a[i],e,mod),mod-2,mod)});
			cnt[a[i]]++;
		}
	}
	memset(cnt,0,sizeof(cnt));
	sort(q+1,q+1+m);
	for(int i=1;i<=m;i++){
		while(l>q[i].l) add(a[--l]);
		while(r<q[i].r) add(a[++r]);
		while(l<q[i].l) del(a[l++]);
		while(r>q[i].r) del(a[r--]);
		ans[q[i].d]=1ll*ans[q[i].d]*now%mod;
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}
