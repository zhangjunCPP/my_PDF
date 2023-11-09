#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b;
};
int a[222222],g[222222];
vector<node>f[222222];
map<int,int>v,vv;
int main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	int n;
	scanf("%d",&n);
	int ma=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	f[1].push_back({a[1],a[1]});
	f[2].push_back({a[1]+a[2],a[1]+a[2]});
	for(int i=1;i<n;++i){
		int o=0;
		for(int j=0;j<f[i].size();++j){
			int x=f[i][j].a,y=f[i][j].b;
			if(v[x]!=i){
				v[x]=i;
				vv[x]=y;
				g[++o]=x;
			}else{
				vv[x]=max(vv[x],y);
			}
		}
		for(int j=1;j<=o;++j){
			if(i<n){
				int x=a[i+1];
				int yu=g[j];
				if(yu>=x){
					f[i+1].push_back({yu,min(x,vv[yu])});
				}else{
					f[i+1].push_back({x,vv[yu]});
				}
			}
			if(i<n-1){
				int x=a[i+1]+a[i+2];
				int yu=g[j];
				if(yu>=x){
					f[i+2].push_back({yu,min(x,vv[yu])});
				}else{
					f[i+2].push_back({x,vv[yu]});
				}
			}
		}
	}
	int ans=2e9;
	for(int i=0;i<f[n].size();++i){
		int x=f[n][i].a,y=f[n][i].b;
		ans=min(ans,x-y);
	}
	printf("%d",ans);
	return 0;
}
