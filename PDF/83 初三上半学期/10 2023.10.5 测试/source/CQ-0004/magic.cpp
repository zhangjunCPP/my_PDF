#include<cstdio>
#include<iostream>
using namespace std;
using ll=long long;
template<class _Tp>
inline _Tp &umax(_Tp &fi,_Tp se){return fi=max(fi,se);}
int L[1005],R[1005];
int c[1005];
ll  f[1<<20|5];
ll  g[1005][1<<8|5];
int las[1<<20|5],ptr[1<<20|5];
void presolve(int n){
	for(int i=0;i<1<<n;++i)
		for(int j=1;j<=n;++j)if(~i>>j-1&1){
			int cnt=-1;
			for(int k=L[j];k<=R[j]&&k<=n;++k)cnt+=(~i>>k-1&1);
			if(f[i|1<<j-1]<f[i]+1ll*cnt*c[j]){
				las[i|1<<j-1]=i,ptr[i|1<<j-1]=j;
			}
			umax(f[i|1<<j-1],f[i]+1ll*cnt*c[j]);
		}
}
int main(){
//	freopen("ex_magic/magic2.in","r",stdin);
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;++i)cin>>L[i]>>R[i]>>c[i];
	presolve(min(n,20));
	if(n<=20){cout<<f[(1<<n)-1]<<'\n';return 0;}
//	cout<<f[127]<<'\n';
	for(int i=0;i<=127;++i){
		g[7][i]=f[i]+f[i^127];
		for(int j=1;j<=7;++j)if(~i>>j-1&1){
			int cnt=0;
			for(int k=L[j];k<=R[j]&&k<=7;++k)cnt+=(i>>k-1&1);
			g[7][i]-=1ll*cnt*c[j];
		}
	}
	for(int i=8;i<=n;++i){
		for(int j=0;j<=127;++j){
			ll tmp=g[i-1][j];
			int p=64|j>>1;
			for(int k=0;k<7;++k)if(( j>>k&1)&&R[i+k-7]>=i)tmp+=c[i+k-7];
			for(int k=0;k<7;++k)if((~j>>k&1)&&L[i]<=i+k-7)tmp+=c[i];
			umax(g[i][p],tmp);
//			if(tmp==110){
//				cout<<j<<' '<<g[i-1][j]<<' '<<p<<'\n';
//				for(int k=0;k<7;++k)if(( j>>k&1)&&R[i+k-7]>=i)cout<<"R "<<i+k-7<<' '<<c[i+k-7]<<'\n';
//				for(int k=0;k<7;++k)if((~j>>k&1)&&L[i]<=i+k-7)cout<<"L "<<i+k-7<<' '<<c[i    ]<<'\n';
//			}
		}
		for(int j=0;j<=127;++j)
			for(int k=0;k<=127;++k)umax(g[i][j>>1],g[i][64|(j|k)>>1]);
	}
	/*
	for(int i=8;i<=n;++i){
		for(int j=0;j<=127;++j){
			ll tmp=f[i-1][j];
			int p=64|j>>1;
			for(int k=0;k<7;++k)if(( j>>k&1)&&R[i+k-7]>=i)tmp+=c[i+k-7];
			for(int k=0;k<7;++k)if((~j>>k&1)&&L[i]<=i+k-7)tmp+=c[i];
			umax(f[i][p],tmp);
			if(tmp==132){
				cout<<j<<' '<<tmp-f[i-1][j]<<' '<<p<<'\n';
				for(int k=0;k<7;++k)if(( j>>k&1)&&R[i+k-7]>=i)cout<<"R "<<i+k-7<<' '<<c[i+k-7]<<'\n';
				for(int k=0;k<7;++k)if((~j>>k&1)&&L[i]<=i+k-7)cout<<"L "<<i+k-7<<' '<<c[i    ]<<'\n';
			}
		}
	}
	*/
	ll ans=0;
	for(int i=0;i<=127;++i)ans=max(ans,g[n][i]);
	cout<<ans<<'\n';
	return 0;
}
