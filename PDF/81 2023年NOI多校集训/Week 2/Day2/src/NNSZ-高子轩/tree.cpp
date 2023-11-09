#include<bits/stdc++.h>
#define ll long long

const int modd = 1e9 + 7,maxn = 1e6 + 9;
using namespace std;

ll read(){
  int x = 0,f = 1;
  char ch = getchar();
  while(ch<'0'||ch>'9'){if(ch=='-')f = -f;ch = getchar();}
  while(ch>='0'&&ch<='9'){x = (x<<1)+(x<<3)+(ch^48);ch = getchar();}
  return x*f;
}

ll n,pow2[maxn],dep[maxn],fa[maxn][30],ans;
vector<ll> g[maxn],nodes[2];

void subtaskA(){
  pow2[0] = 1;
  for(int i = 1;i<=n;i++)pow2[i] = (pow2[i-1]<<1)%modd;
  
  ll res = 0;
  for(int i = (n+1)/2;i<=n;i++){
    ll curr;
    if(i!=n)
      curr = (pow2[max(2*i-n-1,0ll)]*2 + modd)%modd;
    else curr = pow2[n-2];
    cerr<<i<<' '<<curr<<'\n';
    res = (res + curr*(i-1)%modd)%modd;
  }
  printf("%lld\n",res);
}

void dfs(int u,int f){
  fa[u][0] = f,dep[u] = dep[f] + 1;
  for(int i = 1;i<=25;i++)fa[u][i] = fa[fa[u][i-1]][i-1];

  //cerr<<u<<' '<<dep[u]<<'\n';
  
  for(int v : g[u]){
    if(v!=f){
      dfs(v,u);
    }
  }
}

int lca(int x,int y){
  if(dep[x]>dep[y])swap(x,y);
  for(int i = 25;i>=0;i--)if(dep[fa[y][i]]>=dep[x])y = fa[y][i];
  if(x==y)return x;
  for(int i = 25;i>=0;i--)if(fa[y][i]!=fa[x][i])x = fa[x][i],y = fa[y][i];
  return fa[x][0];
}

inline int dis(int x,int y){
  //cerr<<x<<' '<<y<<' '<<lca(x,y)<<'\n';
  return dep[x] + dep[y] - 2*dep[lca(x,y)];
}

void fill(int pos){
  if(pos == n+1){
    int maxx = 0;
    
    for(int k = 0;k<=1;k++)
      for(int i = 0;i<nodes[k].size();i++){
	for(int j = 0;j<i;j++){
	  maxx = max(maxx,dis(nodes[k][i],nodes[k][j]));
	  //cerr<<"dis : "<<nodes[k][i]<<' '<<nodes[k][j]<<' '<<dep[nodes[k][i]]<<' '<<dep[nodes[k][j]]<<' '<<dis(nodes[k][i],nodes[k][j])<<'\n';
	}
      }

    ans += maxx;
    return;
  }

  nodes[0].push_back(pos);
  fill(pos+1);
  nodes[0].pop_back();
  
  nodes[1].push_back(pos);
  fill(pos+1);
  nodes[1].pop_back();
}

int main(){
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);

  bool isA = true;
  
  n = read();
  if(n==2){
    cout<<2<<'\n';
    return 0;
  }
  
  for(ll i = 1,u,v;i<n;i++){
    u = read(),v = read();
    g[u].push_back(v),g[v].push_back(u);

    if(u>v)swap(u,v);
    if(u!=i||v!=i+1)isA = false;
  }

  if(isA){
    subtaskA();
  }else{
    dfs(1,0);
    fill(1);
    printf("%lld",ans);
  }
}
