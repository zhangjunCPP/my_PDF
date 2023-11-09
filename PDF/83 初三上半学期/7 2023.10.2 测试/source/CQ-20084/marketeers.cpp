#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int maxn=5e5+5;
int k[maxn],n;
vector<int> s[maxn];
int d[maxn],mx[maxn];
int val[maxn];
inline int dfs(int now){
	if(now==0) return 1;
	int ret=0;
	for(auto v:s[now]){
		int cnt=0;
		for(int j=now+1;j<=n;j++)
			if(v>val[j]) cnt++;
		if(cnt==d[now]){
			val[now]=v;
			ret=(ret+dfs(now-1))%mod;
		}
	}
	return ret;
}
int main(){
	freopen("marketeers.in","r",stdin);
	freopen("marketeers.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1,x;j<=k[i];j++){
			scanf("%d",&x);
			s[i].push_back(x);
		}
		sort(s[i].begin(),s[i].end());
	}
	memset(mx,0x3f,sizeof(mx));
	for(int i=1;i<=n;i++){
		int x=0;
		for(auto v:s[i]){
			if(v<mx[i]) x=v;
			else break;
		}
		for(int j=i+1;j<=n;j++){
			if(s[j][0]<x){
				mx[j]=min(mx[j],x);
				d[i]++;
			}
		}
	}
	cout<<dfs(n);
	return 0;
}
