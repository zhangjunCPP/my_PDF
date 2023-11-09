#include<bits/stdc++.h>
#define ll long long

const int modd = 998244353,maxn = 20,maxdi = 7e4;
using namespace std;

int n,a[maxn],chunk[maxn],tot,tag[maxn],dp[19][19][2][maxdi];

int read(){
  int x = 0,f = 1;
  char ch = getchar();
  while(ch<'0'||ch>'9'){if(ch=='-')f = -f;ch = getchar();}
  while(ch>='0'&&ch<='9'){x = (x<<3)+(x<<1)+(ch^48);ch = getchar();}
  return x*f;
}

int dfs(int po,int lst,int rem,bool inc,int stat,int fin){
  //cerr<<po<<'\n';
  if(dp[po][lst][inc][stat]!=-1)return dp[po][lst][inc][stat];
  if(po>n){
    return 1;
  }

  ll res = 0;
  
  //we've met a new chunk
  if(rem==0){
    //cerr<<po<<' '<<lst<<' '<<fin<<'\n';
    rem = chunk[tag[po]];
    for(int i = 1;i<=n;i++){
      if((!(stat&(1<<i-1)))&&i!=lst-1&&i!=lst+1){
	//cerr<<i<<'\n';
	if(rem!=1){
	  res += dfs(po+1,i,rem-1,0,stat|(1<<i-1),fin*10+i);
	  res += dfs(po+1,i,rem-1,1,stat|(1<<i-1),fin*10+i);	  
	}else{
	  res += dfs(po+1,i,0,0,stat|(1<<i-1),fin*10+i);
	}
      }
    }
  }else{//continue last chunk
    if(!inc){
      if(lst!=1&&!(stat&(1<<lst-2)))
	res += dfs(po+1,lst-1,rem-1,inc,stat|(1<<lst-2),fin*10+lst-1);
    }else{
      if(lst!=n&&!(stat&(1<<lst)))
	res += dfs(po+1,lst+1,rem-1,inc,stat|(1<<lst),fin*10+lst+1);
    }
  }

  return dp[po][lst][inc][stat] = res%modd;
}

int main(){
  freopen("gap.in","r",stdin);
  freopen("gap.out","w",stdout);
  
  //  scanf("%d",&n);
  memset(dp,-1,sizeof dp);
  n = read();

  for(int i = 1;i<=n;i++){
    a[i] = read();
  }

  for(int i = 1;i<=n;){
    chunk[++tot] = a[i];
    for(int j = i;j<i+a[i];j++)tag[j] = tot;
    i += a[i];
  }

  printf("%d\n",dfs(1,-1,0,0,0,0)); 
}
