#include<bits/stdc++.h>

const int maxn = 5e5 + 9;
using namespace std;

ll read(){
  int x = 0,f = 1;
  char ch = getchar();
  while(ch<'0'||ch>'9'){if(ch=='-')f = -f;ch = getchar();}
  while(ch>='0'&&ch<='9'){x = (x<<1)+(x<<3)+(ch^48);ch = getchar();}
  return x*f;
}

int n,w[maxn];
vector<int> g[maxn];

int main(){
  freopen("lis.in","r",stdin);
  freopen("lis.out","w",stdout);
  
  n = read();
  for(int i = 1,u,v;i<n;i++){
    u = read(),v = read();
    g[u].push_back(v),g[v].push_back(u);
  }

  for(int i = 1;i<=n;i++)w[i] = read();

  cout<<n/2;
}
