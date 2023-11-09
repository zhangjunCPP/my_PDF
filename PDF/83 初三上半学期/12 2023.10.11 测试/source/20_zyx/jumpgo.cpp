#include<bits/stdc++.h>
using namespace std;
#define c(n,m) (pre[n]*inv[m]%mod*inv[(n)-(m)]%mod)
int n;
char s[501],a[501];
long long ans,pre[1001]={1},inv[1001]={1};
const int mod=1e9+7;
long long power(long long a,long long b){
	long long res=1;
	for(;b;b>>=1){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
	}
	return res;
}
void dfs(int x){
	if(x==n+1){
		int zero=0,one=0,now=0,cnt=0;
		long long res=1;
		for(int i=1;i<=n;i++){
			if(a[i]=='0'){
				if(now&1) cnt++;
				now=0;
			}
			else now++;
		}
		if(!(now=0)&&cnt<=1){
			for(int i=1;i<=n;i++){
				if(a[i]=='0') zero++;
				else one++;
			}
			res=c(one/2+zero,one/2);
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]=='0') zero++;
				else one++,now++;
				if(i==n||a[i]=='1'&&a[i+1]=='0'){
					if(now&1||n==i){
						res=res*c(one/2+zero,one/2)%mod;
						zero=0,one=0;
					}
					now=0;
				}
			}
		}
		ans=(ans+res)%mod;
		return;
	}
	if(s[x]!='?') a[x]=s[x],dfs(x+1);
	else a[x]='0',dfs(x+1),a[x]='1',dfs(x+1);
}
int main(){
	freopen("jumpgo.in","r",stdin);
	freopen("jumpgo.out","w",stdout); 
	
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n*2;i++) pre[i]=pre[i-1]*i%mod;
	for(int i=1;i<=n*2;i++) inv[i]=power(pre[i],mod-2);
	dfs(1);
	printf("%lld",ans);
	return 0;
}
