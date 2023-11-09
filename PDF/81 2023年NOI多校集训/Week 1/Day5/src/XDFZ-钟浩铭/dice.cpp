#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int n,k,cnt;
int num[10]={0,0,2,4,6,8,10};
int p[10],Times;
bool vis[MAXN];
inline void print(){
	for(int i=0;i<6;i++) printf("%d ",p[i]);
	printf("\n");
	return ;
}
void dfs(int x,int sum){
	if(Times>9e8+10 && cnt>0) puts("No"),exit(0);  
	if(cnt<=0) exit(0);
	if(x==6){
		if(sum%k==0){
			if(cnt==n) puts("Yes"),print();
			else print();
			cnt--;
		}
		return ;
	}
	for(int i=0;i<=MAXN;i++){
		if(!vis[i]){
			vis[i]=1;
			p[x]=i;
			Times++;
			dfs(x+1,sum^i);
			vis[i]=0;
		}
	}
}
int main(){
	//freopen("dice.in","r",stdin);
	//freopen("dice.out","w",stdout);
	scanf("%d%d",&n,&k); cnt=n;
	if(k==2){
		puts("Yes");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=6;j++) printf("%d ",num[j]);
			printf("\n");
			for(int j=1;j<=6;j++) num[j]+=2;
		}
		return 0;
	}
	if(n==1){
		puts("Yes");
		for(int i=k;i<=MAXN;i+=k) printf("%d ",i);
		printf("\n");
	}
	dfs(0,0);	
	puts("No");
	return 0;
}

