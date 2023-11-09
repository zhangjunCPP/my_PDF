#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,w;
}b[2222222];
int s[2222222],cnt=0;
int add(int x,int y){
	cnt++;
	b[cnt].v=y;
	b[cnt].w=s[x];
	s[x]=cnt;
	return 0;
}
int d[2222222],a[2222222];
int ans=0;
int dfs(int x){
	for(int i=s[x];i;i=b[i].w){
		int xx=b[i].v;
		if(!d[xx]){
			d[xx]=d[x]+1;
			
			dfs(xx);
		}else{
			if(d[x]-d[xx]+1==3){
				ans=3;
			}
		}
	}	
	return 0;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int opt;
	cin>>opt;
	while(opt--){
		int n,m;
		cin>>n>>m;
		ans=0;
		cnt=0;
		for(int i=1;i<=n;i++){
			s[i]=0;
			a[i]=0;
			d[i]=0;
		}
		for(int i=1;i<=m;i++){
			int x,y;
			cin>>x>>y;
			add(x,y);
			add(y,x);
			a[x]++;
			a[y]++;
		}
		dfs(1);
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
