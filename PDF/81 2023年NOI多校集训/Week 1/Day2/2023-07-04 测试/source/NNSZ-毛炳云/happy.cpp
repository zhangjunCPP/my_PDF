#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int K=505;
const int MAXN=1e17+5;
int n,k;
int ti[N],num[K],cost[K];//ti为n次进入的时刻  num为票的时长（持续时间）  cost为票的价格 


long long ls=0;
long long sumi;
void dfs(int st,int x,long long s){
	//
	//边界条件 
	if(st>=x){
		//printf("s为%d\n",s);
		sumi=min(sumi,s);
		return;
	}

	
	if(s>=sumi)return;
	//搜索部分 
	for(int j=1;j<=k+1;j++){//分别枚举k+1种票
		int tar=ti[st]+num[j]-1;
		int to;
		if(num[j]==0)to=j+1;
		else{
			for(int i=st;i<=x;i++){
				if(ti[i]>tar){
					to=i;
					break;
				}
			}
		}
		
		dfs(to,x,s+cost[j]);
	}	
}



int main(){
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&ti[i]);
	}
	for(int i=2;i<=k+2;i++){
		if(i==k+2){
			scanf("%d",&cost[1]);
			num[1]=1;
		}
		else scanf("%d%d",&num[i],&cost[i]);
	}
	
	ls=0;//前i-1次进入的最少花费 
	for(int i=1;i<=n;i++){
		sumi=MAXN;
		dfs(0,i,0);
		printf("%d\n",sumi-ls);
		//printf("sumi为%d\n",sumi);
		ls=sumi;
	}

	return 0;
}
