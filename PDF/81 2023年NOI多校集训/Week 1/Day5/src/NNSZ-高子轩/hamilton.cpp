#include<bits/stdc++.h>

const int maxn = 1e5 + 9;
using namespace std;

int n,m;
int read(){
  int x = 0,f = 1;
  char ch = getchar();
  while(ch<'0'||ch>'9'){
    if(ch == '-')f = -f;
    ch = getchar();
  }

  while(ch>='0'&&ch<='9'){
    x = (x<<1)+(x<<3)+(ch^48);
    ch = getchar();
  }

  return x*f;
}

vector<int> g[maxn];
bool vis[maxn],ins[maxn];

/*bool ins[maxn];
int top,st[maxn],dfn[maxn],dfc,low[maxn],idx;
void tarjan(int u){
  dfn[u] = ++dfc,low[u] = dfn[u];
  st[++top] = u,ins[u] = true;
  for(int i = 0;i<g[u].size();i++){
    int v = g[u][i];
    if(!dfn[v]){
      tarjan(v);
      low[u] = min(low[u],low[v]);
    }else if(ins[v])low[u] = min(low[u],dfn[v]);
  }

  if(low[u]==dfn[u]){
    cerr<<u<<'\n';
    int vv;idx++;
    do{
      vv = st[top--];
      ins[vv] = false;
      nodes[idx].push_back(vv);
    }while(vv!=u);
    if(nodes[idx].size()==1){
      printf("NO\n");
      exit(0);
    }
  }
  }*/

vector<int> loop[maxn];
int st[maxn],top,idx,cnt;
bool dfs(int u){
  //cerr<<"dfs : "<<u<<'\n';
  vis[u] = true,ins[u] = true,st[++top] = u;
  for(int i = 0;i<g[u].size();i++){
    int v = g[u][i];
    //cerr<<v<<'\n';
    if(vis[v]&&ins[v]){
      int vv;idx++;
      do{
	vv = st[top--],cnt++;
	ins[vv] = false;
	loop[idx].push_back(vv);
      }while(vv!=v);
      return true;
    }else if(!ins[v]&&!vis[v]){
      if(dfs(v))return true;
    }
  }
  return false;
}

int main(){
  freopen("hamilton.in","r",stdin);
  freopen("hamilton.out","w",stdout);
  
  n = read(),m = read();
  for(int i = 1,a,b;i<=m;i++){
    a = read(),b = read();
    g[a].push_back(b);
  }

  for(int i = 1;i<=n;i++){
    //cerr<<"now : "<<i<<'\n';
    if(!vis[i])dfs(i);
  }

  if(cnt!=n){
    printf("NO\n");
  }else{
    printf("YES\n");
    for(int i = 1;i<=idx;i++){
      printf("%d ",loop[i].size());
      for(auto i : loop[i]){
	printf("%d ",i);
      }
      putchar('\n');
    }
  }
}
