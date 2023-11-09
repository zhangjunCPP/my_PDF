#include<bits/stdc++.h>
#define ll long long

const int maxn = 1e5 + 9;
using namespace std;

int n,k;
int t[maxn],one;
ll dp[maxn];

struct tick{
  int num,cost;
}tickets[509];

bool sort(const tick &a,const tick &b){
  return a.cost<b.cost;
}

int main(){
  freopen("happy.in","r",stdin);
  freopen("happy.out","w",stdout);
  
  scanf("%d%d",&n,&k);
  for(int i = 1;i<=n;i++)scanf("%d",&t[i]);
  for(int i = 1;i<=k;i++)scanf("%d%d",&tickets[i].num,&tickets[i].cost);

  scanf("%d",&one);
  for(int i = 1;i<=n;i++){
    dp[i] = dp[i-1] + one;
    for(int j = 1;j<=k;j++){
      int delta = t[i] - tickets[j].num + 1;
      int pos = upper_bound(t+1,t+1+i,delta) - t - 1;
      //cerr<<pos<<'\n';

      dp[i] = min(dp[i],dp[pos] + tickets[j].cost);
    }
  }

  for(int i = 1;i<=n;i++){
    printf("%lld\n",dp[i] - dp[i-1]);
  }
}
