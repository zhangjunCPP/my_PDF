#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
#define ll long long
ll v[maxn];
int st[maxn][19],lg[maxn],w[maxn][19];
int n;
inline int ask(int l,int r){
	int k=lg[r-l+1];
	return st[l][k]>st[r-(1<<k)+1][k]?w[l][k]:w[r-(1<<k)+1][k];
}
vector< pair<int,int> > ANS;
vector<int> ans2;
stack<int> sta;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout); 
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&v[i]);
	}
	reverse(v+1,v+n+1);
	for(int i=1;i<=n;i++){
		st[i][0]=v[i];
		w[i][0]=i;
	}
	for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(int k=1;k<=18;k++){
		for(int i=1; i+(1<<k)-1 <=n;i++){
			st[i][k]=max(st[i][k-1],st[i+(1<<(k-1))][k-1]);
			w[i][k]=st[i][k-1]>st[i+(1<<(k-1))][k-1]?w[i][k-1]:w[i+(1<<(k-1))][k-1];
		}
	}
	ll ans=0;
	for(int i=1;i<=n;){
		int V=ask(i,n);
		ANS.push_back(make_pair(i,V));
		i=V+1;
	}
	for(int i=(int)ANS.size()-1;i>=0;i--){
		for(int j=ANS[i].second-1;j>=ANS[i].first;j--){
			ans2.push_back(j);
		}
	}
	for(auto x:ANS){
		ans2.push_back(x.second);
	}
	for(auto x:ans2){
		while(!sta.empty() && sta.top()<x){
			ans+=v[x];
			sta.pop();
		}
		sta.push(x);
	}
	printf("%lld\n",ans);
	for(auto x:ans2){
		printf("%d ",n-x+1);
	}
	return 0;
}

