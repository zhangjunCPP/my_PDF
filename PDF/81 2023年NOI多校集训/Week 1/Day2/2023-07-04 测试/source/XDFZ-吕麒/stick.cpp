#include<bits/stdc++.h>
#define _fre(s,b) (b+1)&&(freopen(s".in","r",stdin),0),(b+1&&b)&&(freopen(s".out","w",stdout),0)
int n,m,q;
std::set<int> S[30];
void dfs(int x,int p,int n){
	if(!x) return void(S[n].emplace(p));
	for(int i=1;i<=x;++i) dfs(x-i,p+(x-i)*i,n);
}
short used[505][100005];
bool find(int x,int p){
	if(!p) return true;
	if(!x||x*(x-1)/2<p) return false;
	if(x<=20) return S[x].find(p)!=S[x].end();
	if(used[x][p]) return used[x][p]==2?true:false;
	for(int i=x;i;--i) if(find(x-i,p-(x-i)*i)) return used[x][p]=2,true;
	return used[x][p]=1,false;
}
signed main(){
	_fre("stick",1);
	for(int i=1;i<=20;++i) dfs(i,0,i);
	for(std::scanf("%d",&q);q--;){
		std::scanf("%d%d",&n,&m);
		if(m>n*(n-1)/2){
			puts("0");
			goto nxt;
		}
		std::puts(find(n,m)?"1":"0");
		nxt:;
	}
	return 0;
}
/*
- max_x=x*(x-1)/2
then nothing...
cut the tree to solve the 80pts...
*/
