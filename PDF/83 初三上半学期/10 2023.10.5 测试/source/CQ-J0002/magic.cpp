#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100001],cnt,n,m,t,ans,x[1001],y[1001],z[1001],vis[1001],jl;
vector<int> v[1001];
signed main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i]>>z[i];
		a[i]=z[i]*(y[i]-x[i]);
	}
	bool nm=0;
	for(int i=1;i<=n;i++){
		if(x[i]!=y[i]){
			nm=1;
			break;
		}
	}
	if(!nm){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(x[j]<=i&&y[j]>=i){
				v[i].push_back(j);
			}
		}
	}
	for(int i=1;i<=n;i++){
		int val=INT_MAX,sum=0,yx=0,jl=0;
		for(int j=1;j<=n;j++){
			if(vis[j]) continue;
			int sb=v[j].size();
			val=min(sb,val);
			if(sb==val){
				sum=max(sum,a[j]);
				if(sum==a[j]){
					int v1=0,v2=0;
					for(int k=0;k<v[j].size();k++){
						v1+=z[v[j][k]];
					}
					for(int k=0;k<v[jl].size();k++){
						v2+=z[v[jl][k]];
					}
					if(jl==0) v2=INT_MAX;
					jl=(v1<=v2?j:jl);
				}
			}
		}
		vis[jl]=1;
		ans+=sum;
		for(int j=0;j<v[jl].size();j++){
			a[v[jl][j]]-=z[v[jl][j]];
		}
		for(int j=x[jl];j<=y[jl];j++){
			for(int k=0;k<v[j].size();k++){
				if(v[j][k]==jl) v[j].erase(v[j].begin()+k);
			}
		}
	}
	cout<<ans;
	return 0;
}
//0 0 0 0 0
//0 0 5 5 0
//0 7 5 12 0
//0 8 5 12 0
//0 8 5 12 0
//1 X
//0 3 X
//14 4 X
//4 3 X
//10 4 X
//1+10
