//the code is from chenjh
#include<bits/stdc++.h>
#define MAXN 500005
using namespace std;
const int mod=998244353;
int n;
vector<int> s[MAXN];
int a[MAXN],b[MAXN];
int c[MAXN];
void add(int x,const int val){for(;x<=n;x+=x&-x)c[x]+=val;}
int ask(int x){int r=0;for(;x>0;x^=x&-x)r+=c[x];return r;}
int ans=0;
vector<int> q;
void dfs(const int pos){
	if(pos<1){
		if(++ans>=mod)ans-=mod;
		return;
	}
	for(const int x:s[pos]){
		auto it=lower_bound(q.begin(),q.end(),x);
		if(it-q.begin()==b[pos]){
			q.insert(it,x);
			dfs(pos-1);
			q.erase(lower_bound(q.begin(),q.end(),x));
		}
		else if(it-q.begin()>b[pos]) break;
	}
}
int main(){
	freopen("marketeers.in","r",stdin);
	freopen("marketeers.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		s[i].resize(k);
		for(int&x:s[i]) scanf("%d",&x);
		sort(s[i].begin(),s[i].end());
	}
	set<int> S;
	for(int i=1;i<=n;i++){
		auto it=S.upper_bound(s[i].front());
		if(it==S.end()) a[i]=s[i].back();
		else a[i]=*--upper_bound(s[i].begin(),s[i].end(),*it);
		S.insert(a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+n+1,a[i])-b;
	for(int i=n;i>0;i--)
		b[i]=ask(a[i]-1),add(a[i],1);
//	for(int i=1;i<=n;i++) printf("%d ",b[i]);
	dfs(n);
	printf("%d\n",ans);
	return 0;
}

