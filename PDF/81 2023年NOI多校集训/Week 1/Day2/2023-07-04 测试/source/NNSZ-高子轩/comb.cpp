#include<bits/stdc++.h>
using namespace std;

int read(){
  int x = 0,f = 1;
  char ch = getchar();
  while(ch<'0'||ch>'9'){if(ch=='-')f = -f;ch = getchar();}
  while(ch>='0'&&ch<='9'){x = (x<<3)+(x<<1)+(ch^48);ch = getchar();}
  return x*f;
}

int main(){
  freopen("comb.in","r",stdin);
  freopen("comb.out","w",stdout);
  
  n = read();

  for(int i = 1;i<=n;i++){
    a[i] = read();
  }

  cout<<4*(n/4);
}
