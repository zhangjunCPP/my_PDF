#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
const int INF=0x3f3f3f3f;
const int mod=998244353;
char s[maxn]; 
int n,Hash[maxn],ans[maxn],pw[maxn];
signed main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s+1; 
	n=strlen(s+1);
	pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=pw[i-1]*131%mod;
	for(int i=1;i<=n;i++)Hash[i]=(Hash[i-1]*131+s[i]-'a'+1)%mod;
	for(int i=1;i<=n;i++){
		for(int len=1;len<=n;len++){
			if(i+3*len>n)break;
			int v1=(Hash[i+len-1]-Hash[i-1]*pw[len]%mod+mod)%mod;
			int v2=(Hash[i+2*len-1]-Hash[i+len-1]*pw[len]%mod+mod)%mod;
			int v3=(Hash[n]-Hash[n-len]*pw[len]%mod+mod)%mod;
			if(v1==v2&&v2==v3)ans[i]++;
		}
	}
	for(int i=1;i<n;i++)cout<<ans[i]<<" ";
	cout<<ans[n];
	return 0;
}
//ouvouvouvouvou
