#include<bits/stdc++.h>

using namespace std;
const long long mod=1e9+7;
char s[222222];
long long a[222222],la[222222],c[222222],b[222222],g[222222];
int main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	cin>>s+1;
	long long n=strlen(s+1);
	for(long long i=1;i<=n;i++){
		a[i]=s[i]-'a'+1;
		c[a[i]]=n+1;
	}
	long long x=0;
	for(long long i=n;i>=1;i--){
		x=x*233%mod+a[i];
		x%=mod;
		b[i]=x;
	}
	g[0]=1;
	for(long long i=1;i<=2000;i++){
		g[i]=g[i-1]*233%mod;
	}
	for(long long i=n;i>=1;i--){
		la[i]=c[a[i]];
		c[a[i]]=i;
	}
	for(long long i=1;i<=n;i++){
		long long ans=0;
		for(long long j=la[i];j<=n;j=la[j]){
			long long len=n-j+1;
			if(len*3<n-i+1){
				long long yu=b[j]%mod,op=(b[i]-b[i+len]*g[len]%mod+mod)%mod;
				if(yu==op){
					long long rt=(b[i+len]-b[i+len*2]*g[len]%mod+mod)%mod;
					if(rt==yu){
						ans++;
					}
				}
			}
		}
		cout<<ans<<" ";
	}
	return 0;
}
