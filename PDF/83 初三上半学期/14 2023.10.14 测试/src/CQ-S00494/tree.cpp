#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+10;
const int INF=0x3f3f3f3f;
const int mod=998244353;
int n;
struct node{
	int l,r;
}a[maxn];
int f[maxn];
int F(int x){
	f[0]=f[1]=1;
	for(int i=2;i<=x;i++)f[i]=(f[i-1]+f[i-2])%mod;
	return f[x];
}

int vis[maxn];
map<int,int>mp;
void dfs(int x,int v){
	if(x==n+1){
		mp[v]=1;
		return ;
	}
	if(vis[a[x].l]==0&&vis[a[x].r]==0){
		vis[a[x].l]=1;
		dfs(x+1,v*10+a[x].l);
		vis[a[x].l]=0,vis[a[x].r]=1;
		dfs(x+1,v*10+a[x].r);
		vis[a[x].r]=0;
	}
	else dfs(x+1,v);
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	int flag1=0,flag2=0;
	for(int i=1;i<n;i++){
		cin>>a[i].l>>a[i].r;
		if(a[i].l==i&&a[i].r==i+1)flag1++;
		if(a[i].l==1&&a[i].r==i+1)flag2++;
	}
	if(flag1==n-1)cout<<F(n)<<"\n";
	else if(flag2==n-1)cout<<n<<"\n"; 
	else{
		dfs(1,0);
		cout<<mp.size()<<"\n"; 
	}
	return 0;
}
//5
//1 2
//1 3
//1 4
//1 5
