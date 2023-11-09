#include<bits/stdc++.h>
using namespace std;
inline int rd(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w; 
} 
inline void wr(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)wr(x/10);
	putchar(x%10+'0');
}
inline void FRE(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
}
struct node{
	int y,w,f;
};
const int N=2e3+5;
bool vis[N],mark[N];
bool poin[N];
int n,m,k,ans=1e9;
int final=-1;
int d[N];
int af[N];
vector<node> a[N];
inline void add(int u,int v,int w){
	a[u].push_back({v,w,0});
}
inline void dfs(int u,int FA,int pos,int vl){
	af[pos]=u;
	if(vis[u]){
		ans=min(ans,vl);
		return;
	}
	mark[u]=1;
	if(d[u]>=(int)a[u].size())return;
	for(int i=0;i<(int)a[u].size();++i){
		int v=a[u][i].y,w=a[u][i].w,ff=a[u][i].f;
		if(v==FA||mark[v]||ff)continue;
		dfs(v,u,pos+1,vl+w);
	}
	mark[u]=0;
}
struct xhb{
	int tot;
	int te[100][100]; //第几种情况。 
}use[N];
inline void go(int pos){
	if(pos==n+1){
		for(int i=1;i<=n;++i){
			for(int j=0;j<(int)a[i].size();++j){
			}
		} 
		dfs(1,0,0,0);
		if(ans!=1e9)final=max(final,ans);
		ans=1e9;
		return;
	}
	if(d[pos]==0){
		go(pos+1);
	}
	else if(d[pos]>=(int)a[pos].size()){
		go(pos+1);
	}
	else{
		int ff=use[pos].tot,dd=a[pos].size();
		for(int i=1;i<=ff;++i){
			for(int j=0;j<dd;++j){
				a[pos][j].f=(int)use[pos].te[i][j];
			}
			go(pos+1);
		}
	}
}
inline void pre(int pos,int pr,int ss,int sum){//第几个点，第几条边，一共多少条边，选了几条 
	if(d[pos]==0){
		return;
	}
	else if(d[pos]>=ss){
		for(int i=0;i<(int)a[pos].size();++i){
			a[pos][i].f=1;
		}
		return;
	}
	else{
		if(ss-pr+sum<d[pos])return; 
		if(sum==d[pos]){
			use[pos].tot++;
			int ff=use[pos].tot;
			for(int i=0;i<ss;++i){
				use[pos].te[ff][i]=poin[i];
			}
			return;
		} 
		if(pr>=ss)return;
		poin[pr]=1;
		pre(pos,pr+1,ss,sum+1);
		poin[pr]=0;
		pre(pos,pr+1,ss,sum);
	}
}
int main(){
	FRE(); 
	n=rd(),m=rd(),k=rd();
	for(int i=1,x;i<=k;++i){
		x=rd();vis[x]=1;
	}
	int sum=0;
	for(int i=1;i<=n;++i){
		d[i]=rd();
		if(d[i]>3){
			sum++;
		}
	}
	if(sum>30){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=m;++i){
		int x=rd(),y=rd(),w=rd();
		add(x,y,w);add(y,x,w);
	}
	for(int i=1;i<=n;++i){
		pre(i,0,a[i].size(),0);
	} 
	go(1);
	wr(final==1e9?-1:final);
	return 0;
} 
/*
5 8 3
2 3 5
2 0 1 1 2
1 2 1
2 3 2
3 4 5
2 5 3
4 5 2
5 1 3
3 5 2
4 1 1
*/
