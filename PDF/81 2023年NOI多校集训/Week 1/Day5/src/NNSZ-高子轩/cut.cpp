#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair

/*
有没有可能……能把所有的数字都排个序（？
好像可以只讨论能对答案做出贡献的对数
那就……以0为单位开始找（？）

草，好像假了
一个0可以跨过很多的0，从而使一些用不上的数字用得上

算了写个n^2DP得了
 */

const int maxn = 5e5 + 9;
using namespace std;

//struct rec{int val,id;}recs[maxn];

int n;
bool vis[25];
int dp[1009],pos[1009],cnt[1009],a[maxn];
//vector<int> pos[25],res;
//vector<pii> segs;

/*bool cmp(const rec &a,const rec &b){
  if(a.val==b.val)return a.id<b.id;
  return a.val<b.val;
  }*/

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

inline int mex(int i,int j){
  memset(vis,0,sizeof vis);
  int res = 0;
  for(int p = i;p<=j;p++){
    //cerr<<a[p]<<' ';
    vis[a[p]] = true;
    while(vis[res])res++;
  }
  //  cerr<<'\n';
  return res;
}

int main(){
  freopen("cut.in","r",stdin);
  freopen("cut.out","w",stdout);
  
  n = read();

  bool fl = true;
  
  for(int i = 1;i<=n;i++){
    //scanf("%d",&recs[i].val);
    //recs[i].id = i;
    a[i] = read();
    if(a[i]>1)fl = false;
  }

  if(fl){
    vector<int> res;
    int sum = 0,segs = 0;
    for(int i = 1;i<=n;i++){
      if(a[i]==0){
	if(a[i+1]==1){
	  sum+=2,segs++,res.push_back(i);
	  i ++;
	}else{
	  sum++,segs++,res.push_back(i);
	}
      }else if(a[i]==1){
	if(a[i+1]==0){
	  sum+=2,segs++,res.push_back(i);
	  i++;
	}else{
	  segs++,res.push_back(i);
	}
      }
    }

    printf("%d %d\n",sum,segs);
    /*for(int i = 0;i<res.size();i++){
      printf("%d ",res[i]);
      }*/
    
    
    return 0;
  }

  for(int i = 1;i<=n;i++){
    for(int j = 0,val;j<i;j++){
      val = mex(j+1,i);
      //      cerr<<val<<'\n';
      if(dp[j] + val> dp[i]){
	dp[i] = dp[j] + val;
	pos[i] = j,cnt[i] = cnt[j] + 1;
      }
    }
  }

  printf("%d %d\n",dp[n],cnt[n]);

  int po = n;
  stack<int> st;
  while(po){
    st.push(pos[po] + 1);
    po = pos[po];
  }

  while(st.size()){
    printf("%d ",st.top()),st.pop();
  }

  /*sort(recs+1,recs+1+n,cmp);
  for(int i = 1;i<=n;i++){
    pos[recs[i].val].push_back(recs[i].id);
  }

  for(int i = 0;i<=20;++i)pos[i].push_back(n+1);

  int ans = 0,lst = 0;
  for(int i = 0;i<pos[0].size()-1;++i){
    int sum = 1,div = pos[0][i],minp = div;
    if(pos[0][i]<lst)continue;
    for(int j = 1;j<=20;++j){
      if(!pos[j].size())break;
      if(pos[j][0]<pos[j-1][0]&&pos[j][0]>lst){
	sum++,div = max(div,pos[j][0]),minp = min(minp,pos[j][0]);
	pos[j].erase(pos[j].begin());
      }else break;
    }

    ans += sum,lst = div;
    cerr<<sum<<'\n';
    }*/

  //printf("%d\n",ans);
}
