#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
ll ans;
int n;
ll f[2002];
int a[2002],v[2002];
int cnt,l[2002],r[2002];
ll ksm(ll a,ll b){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
void dfs(int k,int last){
	if(k==cnt+1){
		ans++;
		return;
	}
	if(l[k]==r[k]){
		for(int i=1;i<=n;i++){
			if(i!=last+1&&i!=last-1&&!v[i]){
				v[i]=1;
				dfs(k+1,i);
				v[i]=0;
			}
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(i!=last+1&&i!=last-1){
			int f=0;
			for(int j=1;j<=r[k]-l[k]+1;j++)if((v[i+j-1]||i+j-1>n)&&(f=1))break;
			if(!f){
				for(int j=1;j<=r[k]-l[k]+1;j++)v[i+j-1]=1;
				dfs(k+1,i+r[k]-l[k]);
				for(int j=1;j<=r[k]-l[k]+1;j++)v[i+j-1]=0;
			}
			f=0;
			for(int j=1;j<=r[k]-l[k]+1;j++)if((v[i-j+1]||i-j+1<1)&&(f=1))break;
			if(!f){
				for(int j=1;j<=r[k]-l[k]+1;j++)v[i-j+1]=1;
				dfs(k+1,i-r[k]+l[k]);
				for(int j=1;j<=r[k]-l[k]+1;j++)v[i-j+1]=0;
			}
		}
	}
}
int main(){
	freopen("gap.in","r",stdin);
	freopen("gap.out","w",stdout);
	scanf("%d",&n);
	int fl=1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),fl&=(a[i]==1);
	for(int i=1;i<=n;){
		l[++cnt]=i,r[cnt]=i+a[i]-1;
		i+=a[i];
	}
	dfs(1,-1);
	printf("%lld",ans%mod);
	return 0;
}

