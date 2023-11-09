#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e4+10;
int Q,n,m;
bool vis[55][MAXN];
struct node{
	int sum,dep;
};
void bfs(){
	queue<node> q;
	q.push({0,1});
	while(!q.empty()){
		node t=q.front(); q.pop();
//		printf("%d %d\n",t.dep,t.sum);
//		printf("\n");
		if(t.dep==11) return ;
		vis[t.dep][t.sum]=1;
		for(int i=1;i<=t.dep;i++){
			vis[t.dep][t.sum+i]=1;
			q.push({t.sum+i,t.dep+1});
		}
	}
	return ;
}
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	scanf("%d",&Q);
	bfs(); 
//	printf("%d\n",vis[10][23]);
	while(Q--){
		scanf("%d%d",&n,&m);
		if(n==m && n>=5){puts("0"); continue;}
		if(m==0){puts("1"); continue;}
		if(n>=3 && m==1){puts("0"); continue;}
		if(vis[n][m]==1) puts("1");
		else puts("0");
	}
	return 0;
}
