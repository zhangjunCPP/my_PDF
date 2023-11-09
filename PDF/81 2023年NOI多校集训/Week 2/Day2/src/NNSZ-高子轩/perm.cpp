#include<bits/stdc++.h>
#define int long long
using namespace std;

int read(){
  int x = 0,f = 1;
  char ch = getchar();
  while(ch<'0'||ch>'9'){if(ch=='-')f = -f;ch = getchar();}
  while(ch>='0'&&ch<='9'){x = (x<<1)+(x<<3)+(ch^48);ch = getchar();}
  return x*f;
}

int n,modd,now,last,sol,forelast,fac,firsts[5] = {0,0,1,7,47};

inline int qp(int a,int b){
  int res = 1;
  while(b){
    if(b&1)res = (res*a)%modd;
    a = (a*a)%modd;
    b>>=1;
  }
  return res%modd;
}

signed main(){
  freopen("perm.in","r",stdin);
  freopen("perm.out","w",stdout);
  
  n = read(),modd = read();

  int ans = 1;
  if(n<=5){
    ans = 0;
    for(int i = 0;i<n;i++){
      ans^=firsts[i];
    }
    printf("%lld",ans);
  }else{
    int qpp = qp(2,modd-2);
    last = 4,forelast = 2,fac = 6;
    for(int i = 4;i<=n;i++){
      fac = (fac*i)%modd;
      now = (last + (i-1)*forelast%modd)%modd;
      forelast = last,last = now;

      sol = (fac - now + modd)%modd;
      sol = (sol * qpp)%modd;
      ans ^= sol%modd;
      //cerr<<ans<<'\n';
    }

    printf("%lld",ans);
  }
}
