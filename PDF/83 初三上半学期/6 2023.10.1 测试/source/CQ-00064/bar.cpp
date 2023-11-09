#include<bits/stdc++.h>
using namespace std;
inline int read(){
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
	freopen("bar.in","r",stdin);
	freopen("bar.out","w",stdout);
}
typedef pair<int,int> PII;
typedef pair<int,string> node;
const int N=100,M=1e7;
int n,m,k,tot;
bool vis[N];
vector<PII> a[N];
node ans[M];
inline void add(int u,int v,int w){
	a[u].push_back({v,w});
}
inline bool cmp(node A,node B){
	if(A.first==B.first)return A.second<B.second;
	return A.first<B.first;
}
inline void dfs(int u,int FA,int val,string wo){
	if(u==n){
		ans[++tot]={val,wo};
		return;
	}
	for(int i=0;i<(int)a[u].size();++i){
		int v=a[u][i].first,w=a[u][i].second;
		if(vis[v])continue;
		char A=v+'0';
		vis[v]=1;
		dfs(v,u,val+w,wo+A);
		vis[v]=0;
	}
}
int main(){
	FRE();
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		add(u,v,w);
	}
	string aa="1";
	vis[1]=1;
	dfs(1,0,0,aa);
	sort(ans+1,ans+tot+1,cmp);
	if(tot<k){
		puts("-1");
		return 0;
	}
	aa=ans[k].second;
	printf("%d\n",aa.size());
	for(int j=0;j<aa.size();++j){
		printf("%d ",aa[j]-'0');
	}
}
