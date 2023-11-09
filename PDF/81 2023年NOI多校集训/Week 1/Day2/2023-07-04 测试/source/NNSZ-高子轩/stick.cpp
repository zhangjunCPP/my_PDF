#include<bits/stdc++.h>
using namespace std;

int t,n,m;

int read(){
  int x = 0,f = 1;
  char ch = getchar();
  while(ch<'0'||ch>'9'){if(ch=='-')f = -f;ch = getchar();}
  while(ch>='0'&&ch<='9'){x = (x<<3)+(x<<1)+(ch^48);ch = getchar();}
  return x*f;
}

int main(){
  freopen("stick.in","r",stdin);
  freopen("stick.out","w",stdout);
  
  //  scanf("%d",&t);
  t = read();
  while(t--){
    //    scanf("%d%d",&n,&m);
    n = read(),m = read();
    bool fl = false;

    if(m==0||m==(n-1)*n/2){
      printf("1\n");
      continue;
    }
    
    if(m<(n-1)*n/2){
      for(int i = 1;i<n;i++){
	int tmp = i*(n-i),p = m - tmp,delta = 4*i*i - 4*i + 1 - 8*p;
	if(tmp>m)break;
	//cerr<<"P:"<<p<<" I : "<<i<<'\n';
	if(!p){
	  printf("1\n");
	  fl = true;
	  break;
	}
	
	if(delta<0){
	  continue;
	}else{
	  double sq = sqrt(delta);
	  if(sq - (int)sq>1e-5)continue;
	  else{
	    if(!((2*i-1+delta)&1)){
	      printf("1\n");
	      fl = true;
	      break;
	    }
	  }
	}
      }
    }

    if(!fl){
      printf("0\n");
    }
  }
}
