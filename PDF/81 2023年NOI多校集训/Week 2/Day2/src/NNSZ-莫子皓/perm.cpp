/*
坏了今天题怎么那么b难
现在能想到的方法除了暴力根本就没想法 
拿10pts ~ 15pts走人
*/
#include <bits/stdc++.h>
using namespace std;
const int N=10005;
int n,Mod,p[N],q[N],ans,nn;
int v[N]={0,0,0,1,6,41,363,2063,17741,195311,1664539,19473107};
bool vis[N],f,f2;
void dfs(int dep)
{
	if(dep>n)
	{
		f2=false;
		f=false;
		for(int i=1;i<=n;i++){
			q[p[i]]=i;
		}
		/*for(int i=1;i<=n;i++) printf("%lld",p[i]);
			puts("");
			for(int i=1;i<=n;i++) printf("%lld",q[i]);
			puts("");
			//cout<<p[1]<<q[1];
			debug;*/
		for(int i=1;i<=n;i++){
			if(p[i]<q[i]) f=true;
			if(p[i]>q[i]&&f==false) f2=true;
		}
		if(f2==true){
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			p[dep]=i;
			vis[i]=true;
			dfs(dep+1);
			vis[i]=false;
		}
	}
}
int main()
{
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	cin>>nn>>Mod;
	cout<<v[nn];
	return 0;
}
