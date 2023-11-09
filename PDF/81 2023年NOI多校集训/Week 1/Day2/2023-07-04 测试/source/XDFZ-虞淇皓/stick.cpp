#include <bits/stdc++.h>
using namespace std;
int vis[124755];
vector<int>s[510];
void init(int n,int m){
	s[1].push_back(0);
	s[2].push_back(0);s[2].push_back(2);
	s[3].push_back(0);s[3].push_back(2);s[3].push_back(3);
	for(int i=4;i<=n;i++){
		memset(vis,0,sizeof(vis));
		s[i].push_back(0);s[i].push_back(i-1);
		for(int j=2;j<i;j++){
			for(int k=0,ss=s[j].size();k<ss;k++){
				int x=j*(i-j)+s[j][k];
				if(x<=m&&!vis[x]){
					s[i].push_back(x);
					vis[x]=1;
				}
			}
		}
		sort(s[i].begin(),s[i].end());
	}
}
int nt[100010],mt[100010],mxn,mxm;
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>nt[i]>>mt[i];
		mxn=max(mxn,nt[i]);
		mxm=max(mxm,mt[i]);
	}
	init(mxn,mxm);
	for(int i=1;i<=t;i++){
		vector<int>::iterator x=lower_bound(s[nt[i]].begin(),s[nt[i]].end(),mt[i]);
		if((*x)==mt[i]) cout<<1<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
