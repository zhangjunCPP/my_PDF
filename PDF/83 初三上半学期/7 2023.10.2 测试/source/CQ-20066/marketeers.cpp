#include<bits/stdc++.h>
using namespace std;
template<typename T> void _(T &x){
	x=0; bool f=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	if(f) x=-x;
}
const int p=998244353;
const int N=5e5+5;
int n;
vector<int> st[N];
int now[N];
int ans,maxn[N];
int tmp[N];
void calc(){
	for(int i=1;i<=n;i++){
		tmp[i]=0;
		for(int j=i+1;j<=n;j++) tmp[i]+=now[j]<now[i];
	}
	for(int i=1;i<=n;i++){
		if(tmp[i]<maxn[i]) return ;
		else if(tmp[i]>maxn[i]){
			for(int j=1;j<=n;j++) maxn[j]=tmp[j];
			ans=1;
			return ;
		}
	}
	ans=(ans+1)%p;
}
void dfs(int step){
	if(step>n){
		calc();
		return ;
	}
	for(auto i:st[step]){
		now[step]=i;
		dfs(step+1);
	}
}
int main(){
	freopen("marketeers.in","r",stdin);
	freopen("marketeers.out","w",stdout);
	_(n);
	for(int i=1;i<=n;i++){
		int k; _(k);
		for(int j=1;j<=k;j++){
			int s; _(s);
			st[i].emplace_back(s);
		}
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}

