#include<bits/stdc++.h>
using namespace std;
int n,q,now,tot,cnt,k,a[100001],val[100001],id[100001],l[220001],r[220001],ls[6000001],rs[6000001],sum[6000001],root[100001];
const int mod=998244353;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	return x*f;
}
void update(int rt,int l,int r,int x,int v){
	if(l==r){
		sum[rt]=v;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid){
		if(!ls[rt]) ls[rt]=++cnt;
		update(ls[rt],l,mid,x,v);
	}
	else{
		if(!rs[rt]) rs[rt]=++cnt;
		update(rs[rt],mid+1,r,x,v);
	}
	if(ls[rt]) sum[rt]=max(sum[rt],sum[ls[rt]]);
	if(rs[rt]) sum[rt]=max(sum[rt],sum[rs[rt]]);
}
int query(int rt,int l,int r,int L,int R){
	if(L<=l&&r<=R) return sum[rt];
	int mid=(l+r)>>1,res=0;
	if(L<=mid&&ls[rt]) res=max(res,query(ls[rt],l,mid,L,R));
	if(R>mid&&rs[rt]) res=max(res,query(rs[rt],mid+1,r,L,R));
	return res;
}
long long power(long long a,int b){
	long long res=1;
	for(;b;b>>=1){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
	}
	return res;
}
int main(){
	freopen("boring.in","r",stdin);
	freopen("boring.out","w",stdout);
	
	n=read(),q=read();
	cnt=10000;
	for(int i=1;i<=n;i++){
		a[i]=now=read();
		for(int j=2;j*j<=now;j++){
			if(now%j==0){
				int cnt=0;
				while(now%j==0) now/=j,cnt++;
				if(!id[j]){
					id[j]=++tot;
					val[tot]=j;
					root[tot]=tot;
				}
				update(root[id[j]],1,n,i,cnt);
			}
		}
		if(now){
			if(!id[now]){
				id[now]=++tot;
				val[tot]=now;
				root[tot]=tot;
			}
			update(root[id[now]],1,n,i,1);
		}
	}
	while(q--){
		long long ans=1;
		k=read();
		for(int i=1;i<=k;i++) l[i]=read(),r[i]=read();
		for(int i=1;i<=tot;i++){
			int res=0;
			for(int j=1;j<=k;j++) res=max(res,query(root[i],1,n,l[j],r[j]));
			ans=ans*power(val[i],res)%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
