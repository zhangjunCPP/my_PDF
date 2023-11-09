#include<bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=5e5+10;
int n,head[N],cnt,w[N],len[N],st[N],mx;
set<int> S1,S2;
struct node{
	int to,next;
}e[N<<1];
void add(int u,int v){e[++cnt].to=v,e[cnt].next=head[u],head[u]=cnt;}
void dfs(int u,int f){
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v==f)continue;
		if(w[v]>w[u])len[v]=len[u]+1,st[v]=st[u];
		else len[v]=0,st[v]=v;
	}
}
int main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	for(int i=1;i<=n;++i)w[i]=read();
	for(int i=1;i<=n;++i){
		len[i]=1,st[i]=i,dfs(i,0);
		for(int j=1;j<=n;++j){
			if(len[j]>mx){
				S1.clear(),S2.clear();
				mx=len[j],S1.insert(st[j]),S2.insert(j);
			}else if(len[j]==mx){
				S1.insert(st[j]),S2.insert(j);
			}
		}
	}
	printf("%d\n",(mx+1)/2);
	return 0;
}
