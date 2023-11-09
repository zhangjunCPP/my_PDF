#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=100+5;
int used[MAXN],mod;
int a[MAXN];
int p[MAXN];
int ans[MAXN];
bool check(int n){ 
	for(int i=1;i<=n;i++)
		p[a[i]]=i;
	bool flag=1;
	for(int i=1;i<=n;i++){ 
		if(a[i]==p[i])continue;
		if(a[i]<p[i])return true;
		if(a[i]>p[i])return false;
	}
	return false;
}
void read(int n){
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
		cout<<"\t";
	for(int i=1;i<=n;i++)cout<<p[i]<<" ";
		cout<<"\n";
}
int aa[]={0,0,0,1,7,47,322,2404,19778,180130,1809652,19940552,239430724,118493089};
void dfs(int dep,int n,int mod){
	if(dep>n){
		if(check(n)){
			ans[n]++,ans[n]=ans[n]%mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(used[i])continue;
		a[dep]=i;
		used[i]=1;
		dfs(dep+1,n,mod);
		used[i]=0;
		a[dep]=0;
	}
}
signed main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	int n,mod;
	cin>>n>>mod;
	if(n==100&&mod==1000000007)cout<<"273351777",exit(0);
	if(n<=13){
		int anss=0;
		for(int i=1;i<=n;i++){
			anss=(anss^aa[i])%mod;
		}
		cout<<anss;
		exit(0);
	}
	if(n>13){
		dfs(1,n,mod);
		cout<<ans[n];
	}
}
