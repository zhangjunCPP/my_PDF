#include<bits/stdc++.h>

using namespace std;
struct node{
	long long v,op,op2,w;
}bb[222222];
long long ss[222222],cntt=0;
const long long mod=1e9+7;
long long n,m,k;
long long a[2222],b[2222],c[2222],d[2222],v[2222],f[2222];
long long gg(long long x,long long y){
	if(!y) return 1;
	long long ttt=gg(x,y/2);
	if(y%2){
		return ttt*ttt%mod*x%mod;
	}
	return ttt*ttt%mod;
}
long long cnt=0;
long long dfs(long long x,long long y){
	if(x==n+1){
		long long s=0;
		for(long long i=1;i<=y;i++){
			if(v[i]) s++;
		}	
		if(s!=y) return 0;
		long long yu=1;
		for(long long i=1;i<=m;i++){
			if(f[a[i]]==f[b[i]]){
				yu*=d[i];
				yu%=mod;
			}else{
				yu*=c[i];
				yu%=mod;
			}
		}
		cnt=(cnt+yu)%mod;
		return 0;
	}
	for(long long i=1;i<=y;i++){
		f[x]=i;
		v[i]++;
		dfs(x+1,y);
		v[i]--;
	}
	return 0;
}
long long C(long long x,long long y){
	long long yu=1;
	for(long long i=x;i>=x-y+1;i--){
		yu=yu*i%mod;
	}
	for(long long i=2;i<=y;i++){
		yu=yu*gg(i,mod-2)%mod;
	}
	return yu;
}
long long pop=1;
long long add(long long x,long long y,long long z,long long zz){
	cntt++;
	bb[cntt].v=y;
	bb[cntt].op=z;
	bb[cntt].op2=zz;
	bb[cntt].w=ss[x];
	ss[x]=cntt;
	return 0;
}
long long dfs2(long long x,long long y,long long s){
	long long sa=0;
	for(long long i=ss[x];i;i=bb[i].w){
		long long xx=bb[i].v;
		if(xx!=y){
			sa++;
			long long rt=(s*bb[i].op%mod*(k-1)%mod+s*bb[i].op2%mod)%mod;
			dfs2(xx,x,rt);
		}
	}
	if(sa==0){
		pop=pop*s%mod;
	}
	return 0;
}
int main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	long long opt;
	cin>>opt;
	while(opt--){
		cin>>n>>m>>k;
		long long fl=0;
		for(long long i=1;i<=m;i++){
			cin>>a[i]>>b[i]>>c[i]>>d[i];
			if(c[i]!=1||d[i]!=0){
				fl=1;
			}
		}
		if(fl==0){
			long long ans=1;
			if(k<n){
				cout<<0<<endl;
				continue;
			}
			for(long long i=k;i>=k-n+1;i--){
				ans=ans*i%mod;
			}
			cout<<ans<<endl;
			continue;
		}
		if(m==n-1){
			memset(ss,0,sizeof ss);
			cntt=0;
			for(long long i=1;i<=m;i++){
				add(a[i],b[i],c[i],d[i]);
				add(b[i],a[i],c[i],d[i]);
			}
			dfs2(1,0,1);
			cout<<pop<<endl;
			continue;
		}
		long long ans=0;
		for(long long i=1;i<=min(n,k);i++){
			cnt=0;
			dfs(1,i);
			ans=(ans+cnt*C(k,i)%mod)%mod;
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}

