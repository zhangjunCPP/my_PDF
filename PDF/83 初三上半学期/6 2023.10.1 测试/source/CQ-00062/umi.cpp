#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
int n,m,id;
int fa[121],s[34],dep[232];
vector<int> E[23];
void dfs(int u){
	for(int v:E[u]){
		if(v==fa[u])continue;
		fa[v]=u;dep[v]=dep[u]+1;dfs(v);
	}
}
int q1[123],q2[121];
int vis[1233],d,ans;
vector<int> pos;
void s2(int x){
	if(x==d+1){
		int qq1[1212],qq2[212],k=1;
		for(int i=1;i<=d;i++)qq1[i]=q1[i],qq2[i]=q2[i];
		for(int i=0;i<pos.size();i++){
			int mn1=1,mn2=1;
			for(int j=1;j<=d;j++)mn1=(q1[j]<q1[mn1]?j:mn1);
			for(int j=1;j<=d;j++)mn2=(q2[j]<q2[mn2]?j:mn2);
			if(s[pos[i]]==1&&q1[mn1]>q2[mn2])k=0;
			if(s[pos[i]]==0&&q1[mn1]<q2[mn2])k=0;
			q1[mn1]=9999,q2[mn2]=9999;
		}ans+=k;
		for(int i=1;i<=d;i++)q1[i]=qq1[i],q2[i]=qq2[i];
		return;
	}for(int i=1;i<=m;i++){
		if(!vis[i]){
			vis[i]=1;
			q2[x]=i;
			s2(x+1);
			vis[i]=0;
			q2[x]=0;
		}
	}
}
void s1(int x){
	if(x==d+1){
		s2(1);
		return;
	}for(int i=1;i<=m;i++){
		if(!vis[i]){
			vis[i]=1;
			q1[x]=i;
			s1(x+1);
			vis[i]=0;
			q1[x]=0;
		}
	}
}
int main(){
	freopen("umi.in","r",stdin);
	freopen("umi.out","w",stdout);
	n=rd(),m=rd(),id=rd();
	for(int i=1;i<=n;i++)scanf("%1d",&s[i]);
	for(int i=1;i<n;i++){
		int u=rd(),v=rd();
		E[u].push_back(v);
		E[v].push_back(u);
	}dfs(1);int q=rd();
	while(q--){
		int u=rd(),v=rd();
		vector<int> p1,p2;pos.clear();
		while(u!=v){
			if(dep[u]<dep[v]){
				p2.push_back(v);
				v=fa[v];
			}else{
				p1.push_back(u);
				u=fa[u];
			}
		}p1.push_back(v);
		pos=p1;
		reverse(p2.begin(),p2.end());
		for(int x:p2)pos.push_back(x);
		d=pos.size();ans=0;
		s1(1);
		int x=1;
		for(int i=1;i<=d;i++)x=x*i;
		cout<<ans/x/x<<endl;
	}
	return 0;
}

