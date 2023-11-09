#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=105,INF=0x3f3f3f3f,mod=1e9+7;
int _;
int n,m,q;
vector<int>g[maxn];
map<pair<int,int>,int>mp;

int main(){
    ios::sync_with_stdio(0);
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    cin>>q;
    
    g[1].push_back(0);
	for(int i=2;i<=50;i++){
		g[i].push_back(0);
		mp[{i,0}]=1;
		for(int k=i-1,t=1;k>=1;k--,t++){
			for(int l=0;l<g[t].size();l++){
				int x=k*t+g[t][l];
				//cout<<x<<endl;
				if(!mp.count({i,x})){
					mp[{i,x}]=1;
					g[i].push_back(x);
				}
			}
		}
	}
    
    while(q--){
    	cin>>n>>m;
		
		if(!mp.count({n,m}))cout<<0<<endl;
		else cout<<1<<endl;
	}
    return 0 ^ _ ^ 0;
}

