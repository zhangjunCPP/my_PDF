#include<bits/stdc++.h>
#define ll long long
#define m_p make_pair
using namespace std;
const int N=1000000+10,mod=998244353;
int n;
pair<int,int> b[N];
ll f[N];
ll ask_lian(){
	f[n]=1;
	for(int i=n-1;i>=1;i--){
		f[i]=(f[i+1]+f[i+2])%mod; 
	}
	return (f[1]+f[2])%mod;
}

ll ans=0;
bool v[N];
void dfs(int now){
	if(now>=n){
		ans++;
		ans%=mod;
		return;
	}
	int x=b[now].first,y=b[now].second;
	if(v[x]||v[y]) dfs(now+1);
	else{
		v[x]=1;
		dfs(now+1);
		v[x]=0;
		v[y]=1;
		dfs(now+1);
		v[y]=0;
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	bool f1=1,f2=1;
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		b[i]=m_p(x,y);
		if(x!=1&&y!=1) f1=0;
		if(x!=i||y!=i+1) f2=0;
	}
	if(f1){
		cout<<n;
		return 0;
	}
	if(f2){
		cout<<ask_lian();
		return 0;
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
