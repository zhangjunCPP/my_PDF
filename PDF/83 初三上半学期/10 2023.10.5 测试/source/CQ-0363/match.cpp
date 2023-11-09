#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=1e6+17;
int v[N<<1],nxt[N<<1],head[N],tot;
int rdu[N],dep[N],ans,n,m,t;
bool fl;
void add(int fr,int to){
	v[++tot]=to;
	nxt[tot]=head[fr];
	head[fr]=tot;
	return;
}
void dfs(int pos){
	for(int i=head[pos];i!=0;i=nxt[i]){
		if(dep[v[i]]<dep[pos]){
			if(dep[v[i]]==dep[pos]-2){
				fl=true;
				return;
			}
			continue;
		}
		dep[v[i]]=dep[pos]+1;
		dfs(v[i]);
		if(fl)return;
	}
}
signed main(){
//	freopen("D:\\down\\match\\match2.in","r",stdin);
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		for(int i=1;i<=n;i++){
			rdu[i]=0;
			head[i]=0;
		}
		ans=0;
		tot=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
			rdu[x]++;
			rdu[y]++;
		}
		for(int i=1;i<=n;i++){
			ans=max(ans,rdu[i]);
		}
		if(ans>=3){
			printf("%d\n",ans);
			continue;
		}
		fl=false;
		for(int i=1;i<=n;i++){
			dep[i]=n+1;
		}
		for(int i=1;i<=n;i++){
			if(dep[i]>n){
				dep[i]=1;
				dfs(i);
				if(fl)break;
			}
		}
		if(fl)ans=3;
		printf("%d\n",ans);
	}
}
//uncertainlly all connected!!!
