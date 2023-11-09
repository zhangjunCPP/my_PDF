#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T&x){
x=0;/*T fl=-1;*/char c=getchar();while(c<'0'||'9'<c){/*if(c=='-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}/*x*=fl;*/}
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
#define N 100
pair<int,int>p[N];
int n;
int col[N];
int cnt;
int tot;
void dfs(int u){
	if(u==n){
		cnt++;
		return ;
	}
	if(col[p[u].first]==col[p[u].second]&&col[p[u].first]==0){
		col[p[u].first]=1;
		dfs(u+1);
		col[p[u].first]=0;
		col[p[u].second]=1;
		dfs(u+1);
		col[p[u].second]=0;
	}else{
		dfs(u+1);
	} 
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	read(n);
	for(int i=1;i<n;i++)read(p[i].first),read(p[i].second);
	dfs(1);
	printf("%d",cnt); 
	return 0;
}
/*
5
1 2
1 3
1 4
1 5
*/
