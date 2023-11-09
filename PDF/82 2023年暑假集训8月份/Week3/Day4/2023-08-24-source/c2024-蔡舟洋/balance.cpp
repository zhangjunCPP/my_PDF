/*
no time to think,fk.

60pts.
*/
#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n;
vector<int> E[N];
int siz[N],son[N];
void dfs(int u,int dad,int S=0){
	siz[u]=1;for(int v:E[u]){
		if(v==dad)continue;
		dfs(v,u,S);siz[u]+=siz[v];
		son[u]=max(son[u],siz[v]);
	}son[u]=max(son[u],S-siz[u]);
}
int rt;
void get(int u,int dad){
	if(son[u]<son[rt])rt=u;
	for(int v:E[u]){
		if(v==dad)continue;
		get(v,u);
	}
}
void solve1(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)siz[j]=0,son[j]=0;
		int sizmax=0;
		for(int v:E[i]){
			dfs(v,i);
			dfs(v,i,siz[v]);
			if(siz[v]>siz[sizmax])sizmax=v;
		}
		rt=sizmax;
		get(rt,i);
		printf("%d\n",rt);
	}
}
void solve2(){
	for(int i=1;i<=n;i++){
		int lf=i-1,rt=n-i;
		if(lf<rt){
			printf("%d\n",(n-i+1)/2+i);
		}else{
			printf("%d\n",(i-1)/2+1);
		}
	}
}
void solve3(){
	printf("2\n");
	for(int i=2;i<=n;i++)puts("1");
}
int main(){
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	int fl1=1,fl2=1;
	scanf("%d",&n);for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
		fl1&=((u==i)&&(v==i+1));
		fl2&=((u==1)&&(v==i+1));
	}
	if(n<=5000)return solve1(),0;
	if(fl1)return solve2(),0;
	if(fl2)return solve3(),0;
	return 0;
}
/*
8
1 2
2 3
3 4
4 5
5 6
6 7
7 8

*/

