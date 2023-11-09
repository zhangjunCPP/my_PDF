#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
const int Maxn=2e5+5;
const int Inf=0x3f3f3f3f;
int a[Maxn];
map<int,int>f[3];
int main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n;cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	if(n==1||n==2){cout<<0<<'\n';return 0;}
	f[1][a[1]]=a[1];
	f[2][a[1]+a[2]]=a[1]+a[2];
	f[2][max(a[1],a[2])]=min(a[1],a[2]);
	for(int i=3;i<=n;++i){
		int v1=a[i],v2=a[i]+a[i-1];
		f[i%3].clear();
		for(auto j:f[(i-1)%3]){
			int x=max(j.first,v1),y=min(j.second,v1);
			if(!f[i%3].count(x))f[i%3][x]=y;
			else  f[i%3][x]=max(f[i%3][x],y);
		}
		for(auto j:f[(i-2)%3]){
			int x=max(j.first,v2),y=min(j.second,v2);
			if(!f[i%3].count(x))f[i%3][x]=y;
			else  f[i%3][x]=max(f[i%3][x],y);
		}
	}
	int ans=Inf;
	for(auto i:f[n%3])ans=min(ans,i.first-i.second);
	cout<<ans<<'\n';
	return 0;
}
