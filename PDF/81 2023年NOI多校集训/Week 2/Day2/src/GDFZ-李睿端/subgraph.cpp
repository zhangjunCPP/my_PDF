#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define int long long
using namespace std;
int read(){
	int ret=0,f=1;char c=getchar();
	while(c>57||c<48){if(c=='-')f= -1;c=getchar();}
	while(c<=57&&c>=48)ret=(ret<<3)+(ret<<1)+(c-48),c=getchar();
	return ret*f;
}
void write(int x){
	if(x<0) x= -x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+48);
}
const int maxn=2e5+5;
const int mod =998244353;
int n,m,A,B,C;
struct ed{
	int h,t;
}e[maxn];
int last[maxn],ecnt,edu[maxn],edv[maxn];
void link(int x,int y){
	e[++ecnt].h=last[x];
	e[ecnt].t=y;
	last[x]=ecnt;
}
queue<int>q;
bool vis[maxn];
int s[maxn],top;
int fa[maxn];
int edge_num[maxn],ge[maxn],pos_num[maxn];
int find(int x){
	if(x==fa[x])return fa[x];
	return fa[x]=find(fa[x]);
}
void merge(int u,int v){
	if(find(u)==find(v)){
		ge[find(u)]-=1;
		edge_num[find(u)]++;
	}else{
		ge[find(u)]+=ge[find(v)]-1;
		edge_num[find(u)]+=edge_num[find(v)]+1;
		pos_num[find(u)]+=pos_num[find(v)];
		fa[find(v)]=find(u);
	}
}
int in[maxn],innow[maxn],time[maxn];
void tuopu(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			if(innow[i]<k)q.push(i),vis[i]=1;
		}
		while(!q.empty()){
			int u=q.front();
			s[++top]=u;
			time[u]=k;
			q.pop();
			for(int i=last[u];i;i=e[i].h){
				int v=e[i].t;
				if(vis[v])continue;
				if(--innow[v]<k){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	
}
void solve(){
	freopen("subgraph.in","r",stdin);
	freopen("subgraph.out","w",stdout);
    n=read(),m=read(),A=read(),B=read(),C=read();
    for(int i=1,x,y;i<=m;i++){
    	x=read(),y=read();
    	link(x,y),link(y,x);
    	in[x]++,in[y]++;
    	innow[x]++,innow[y]++;
	}
	tuopu();
	for(int i=1;i<=n;i++){
		fa[i]=i;
		ge[i]=in[i];
		pos_num[i]=1;
	}
	int ans= -1e17,max_tim;
	for(int k=n;k>=1;k--){
		int top1=top;
		while(top1&&time[s[top1]]>k){
			int u=s[top1--];
			for(int i=last[u];i;i=e[i].h){
				int v=e[i].t;
				merge(u,v);
			}
		}
		for(int i=top1+1;i<=top;i++){
			int tmp=edge_num[find(s[i])]*A/2-pos_num[find(s[i])]*B+ge[find(s[i])]*C;
			if(ans<tmp){
				ans=tmp;
				max_tim=k;
			}
		}
		top=top1;
	}
	cout<<max_tim<<' '<<ans;
}
signed main(){
    int t=1;
    while(t--)solve();
    return 0;
}/*
3 3
1 1 2
1 2
2 3
3 1
*/
