#include<bits/stdc++.h>
using namespace std;
int n,k,ans,b[500001],mx[500001],now[500001];
vector <int> a[500001];
const int mod=998244353;
void dfs(int p){
	if(p==n+1){
		bool can=0;
		for(int i=1;i<=n;i++){
			int res=0;
			for(int j=i+1;j<=n;j++) if(b[i]>b[j]) res++;
			now[i]=res;
			if(!can&&res<mx[i]) return;
			if(res>mx[i]) can=1;
		}
		if(!can) ans=(ans+1)%mod;
		else{
			ans=1;
			for(int i=1;i<=n;i++) mx[i]=now[i];
		}
		return;
	}
	for(auto i:a[p]) b[p]=i,dfs(p+1);
}
int main(){
	freopen("marketeers.in","r",stdin);
	freopen("marketeers.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		a[i].resize(k);
		for(int j=0;j<k;j++) scanf("%d",&a[i][j]);
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}
