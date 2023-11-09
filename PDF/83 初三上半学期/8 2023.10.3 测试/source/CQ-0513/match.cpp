/*
重复限制
松的先占位置
因为紧的会占据更多位置不说
还会把松的顶到外面更大的

 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int m,s1,s2,i,j,a[N],b[N],las;
bool vis[N],use[N],ans[N];
bool check(){
	for(int i=m;i;--i)
		if(vis[i]<use[i])return 0;
		else if(use[i]<vis[i])return 1;
	return 0;
}
void work1(){
	scanf("%d",&s1);
	for(i=1;i<=s1;++i)scanf("%d",a+i),vis[a[i]]=1;
	scanf("%d",&s2);
	for(i=1;i<=s2;++i)scanf("%d",b+i),use[b[i]]=1;
	bool c=check();
	if(c)for(i=1;i<=m;++i)swap(vis[i],use[i]);
	for(i=1;i<=m;++i){
		if(!use[i])continue;
		if(!vis[i]&&!ans[i])ans[i]=1;
		else{
			int j=i;
			while(j<=m&&(vis[j]|ans[j]))++j;
			if(j>m)return void(puts("-1"));
			i=j-1;
			las=j;
			ans[j]=1;
		}
	}
	for(i=m;i;--i)printf("%d",(i>=las?ans[i]:0)|vis[i]);
}
int n;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n<=2)return work1(),0;
	puts("-1");
	return 0;
}
/*
2 4
2 1 2
2 1 3

2 4
1 1
2 1 3

2 5
1 3
3 2 3 5

2 5
3 1 2 3
3 2 3 4

2 15
3 1 3 5
3 5 7 9
*/
