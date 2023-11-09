#include<bits/stdc++.h>
using namespace std;
struct node{
	long long v,w,op;
}b[2222222];
long long s[2222222],cnt=0,d[2222222],c[2222222],a[2222222],v[2222222],vis[2222222];
long long add(long long x,long long y,long long z){
	cnt++;
	b[cnt].v=y;
	b[cnt].w=s[x];
	b[cnt].op=z;
	s[x]=cnt;
	return 0;
}

long long dfs(long long x){
	vis[x]=1;
	if(v[x]==1){
		d[x]=0;
		return 0;
	}
	for(long long i=s[x];i;i=b[i].w){
		long long xx=b[i].v;
		if(!vis[xx]){
			dfs(xx);
		}
	}
	long long o=0;
	for(long long i=s[x];i;i=b[i].w){
		long long xx=b[i].v;
		c[++o]=d[xx]+b[i].op;
	}
	sort(c+1,c+o+1);
	if(a[x]>=o){
		return 0;
	}
	d[x]=c[a[x]+1];
	return 0;
}

int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	for(long long i=1;i<=k;i++){
		long long x;
		cin>>x;
		v[x]=1;
	}
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=m;i++){
		long long x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	memset(d,0x3f3f3f3f3f3f3f3f,sizeof d);
	dfs(1);
	if(d[1]>=0x3f3f3f3f3f3f3f3f){
		cout<<-1;
	}else{
		cout<<d[1];
	}
	
	return 0;
}
