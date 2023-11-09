#include<bits/stdc++.h>

const int maxn = 1e6 + 9;
using namespace std;

int read(){
  int x = 0,f = 1;
  char ch = getchar();
  while(ch<'0'||ch>'9'){if(ch=='-')f = -f;ch = getchar();}
  while(ch>='0'&&ch<='9'){x = (x<<1)+(x<<3)+(ch^48);ch = getchar();}
  return x*f;
}

int n,m,M,N,B,deg[maxn],maxdeg = 0;
vector<int> g[maxn];

int main(){
  freopen("subgraph.in","r",stdin);
  freopen("subgraph.out","w",stdout);
  
  n = read(),m = read();
  M = read(),N = read(),B = read();

  for(int i = 1,u,v;i<=m;i++){
    u = read(),v = read();
    g[u].push_back(v),g[v].push_back(u);
    deg[u]++,deg[v]++;

    maxdeg = max({maxdeg,deg[u],deg[v]});
  }

  cout<<maxdeg<<'\n';
}
