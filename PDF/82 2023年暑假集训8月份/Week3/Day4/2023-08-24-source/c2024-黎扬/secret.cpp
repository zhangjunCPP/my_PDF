#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
inline void work(ll k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
const ll mod=65535;
int t,k,cnt,x[265],y[265],vis[15];
ll ans,b[15],a[15],n,pn[100005];
ll power(ll a,ll b){
	ll sum=1,k=a;
	while(b){
		if(b&1ll){
			sum*=k;
			sum%=mod;
		}
		k*=k;
		k%=mod;
		b>>=1ll;
	}
	return sum;
}
void dfs(int k){
	if(k>cnt){
		ll sum=0;
		for(int i=1;i<=cnt;i++){
			sum+=a[b[i]]*power(256,i-1)%mod;
			sum%=mod;
		}
		ans=ans*sum%mod;
		return ;
	}
	for(int i=1;i<=cnt;i++){
		if(!vis[i]){
			b[k]=i;
			vis[i]=1;
			dfs(k+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("secret.in","r",stdin);
	freopen("secret.out","w",stdout);
	for(int i=1;i<=1e5;i++){
		pn[i]=pn[i-1]+power(256,i);
		pn[i]%=mod;
	}
	t=read();
	while(t--){
		k=read();
		n=0;
		for(int i=1;i<=k;i++){
			x[i]=read();
			y[i]=read();
			n+=y[i];
		}
		if(k==1){
			ans=1;
			for(ll i=10000;i<n;i+=10000){
				ans=(ans+pn[10000]*power(256,i-10000)%mod)%mod;
			}
			ans=(ans+pn[(n-1)%10000]*power(256,(n-1)/10000*10000))%mod;
			ll v=1;
			for(int i=1;i<=n;i++){
				v=v*i%mod;
			}
			work(power(ans*x[1]%mod,v));//(ans*x[1])^(n!) 
			putchar('\n');
			continue;
		}
		if(n<=9){
			ans=1;
			cnt=0;
			for(int i=1;i<=k;i++){
				for(int j=1;j<=y[i];j++){
					a[++cnt]=x[i];
				}
			}
			dfs(1);
			work(ans);
			putchar('\n');
		}
	}
	return 0;
}
