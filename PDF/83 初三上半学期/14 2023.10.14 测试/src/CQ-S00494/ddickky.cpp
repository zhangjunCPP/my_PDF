#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
const int INF=0x3f3f3f3f; 
const int mod=998244353;
int n,Q,a[maxn];
map<int,int>mp;
struct node{
	int l,r,id;
}q[maxn];
int qpow(int x,int y){
	int val=1;
	while(y){
		if(y&1)val=val*x%mod;
		x=x*x%mod,y/=2;
	}
	return val;
}
signed main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=Q;i++)cin>>q[i].l>>q[i].r,q[i].id=i;
	for(int i=1;i<=Q;i++){
		int l=q[i].l,r=q[i].r;
		mp.clear();
		for(int j=l;j<=r;j++){
			if(j==l)mp[a[j]]=1;
			else{
				for(auto it=(--mp.end());it!=mp.begin();it--){
					int val=(*it).first;
					int v=(mp[__gcd(val,a[j])]+mp[val])%mod; 
					mp[__gcd(val,a[j])]=v;
					
				}
				int v=(*mp.begin()).first;
				int val=(mp[__gcd(v,a[j])]+mp[v])%mod;
				mp[__gcd(v,a[j])]=val;
				mp[a[j]]++;
			}
		}
		int ans=1;
		for(auto k=mp.begin();k!=mp.end();k++){
			int s=k->first,p=k->second;
			ans=ans*qpow(s,p)%mod;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//长的像莫队 又不像莫队？
//nm做不来 完蛋了 

//3 1
//2 4 3 
//1 3
