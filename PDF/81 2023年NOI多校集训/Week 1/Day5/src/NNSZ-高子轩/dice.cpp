/*
�о�������֮ǰ������ɫ�Ӷ�Ͷ��һ�����룬�����������
���������Ǻܿ���
 */
#include<bits/stdc++.h>
using namespace std;

void print(int x){
  string res;
  while(x){
    if(x&1)res += '1';
    else res += '0';
    x>>=1;
  }
  reverse(res.begin(),res.end());
  cout<<res<<'\n';
}

int n,k,res[109];

int main(){
  freopen("dice.in","r",stdin);
  freopen("dice.out","w",stdout);
  
  scanf("%d%d",&n,&k);

  if(n==1){
    printf("Yes\n");
    for(int i = 1;i<=6;i++){
      printf("%d ",k*i);
    }
  }else if(k==2){
    printf("Yes\n");
    for(int i = 1;i<=n;i++){
      for(int j = 1;j<=6;j++){
	printf("%d ",2*j);
      }
      putchar('\n');
    }
  }else{
    
  }
}
