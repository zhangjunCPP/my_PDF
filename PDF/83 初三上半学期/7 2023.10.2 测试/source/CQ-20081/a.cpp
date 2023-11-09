#include<bits/stdc++.h>
using namespace std;
#define read(x) scanf("%d",&x)
#define N 5005
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
int n,m,q;
pair<int,int>zs[N],yx[N];
int mx[]={1,1,0,-1,-1,-1,0,1};
int my[]={0,1,1,1,0,-1,-1,-1};
int mp[N][N];
void add(pair<int,int> a,pair<int,int> b){
	for(int i=a.first;i<=b.first;i++)
		for(int j=a.second;j<=b.second;j++)
			mp[i][j]++;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	read(n);
	read(m);
	read(q);
	for(int i=1;i<=n;i++){
		read(zs[i].first);
		read(zs[i].second);
		read(yx[i].first);
		read(yx[i].second);
		add(zs[i],yx[i]);
	}
	for(int i=1;i<=m;i++){
		int v,r,d;
		read(v);
		read(r);
		read(d);
		for(int i=1;i<=d;i++){
			zs[r].first+=mx[v];
			zs[r].second+=my[v];
			yx[r].first+=mx[v];
			yx[r].second+=my[v];
			add(zs[r],yx[r]);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		read(x);
		read(y);
		printf("%d\n",mp[x][y]);
	}
	return 0;
}
/*
1 8 3
2 1 2 1
0 1 1
1 1 1
2 1 1
3 1 1
4 1 1
5 1 1
6 1 1
7 1 1
1 1
2 1
4 2
*/
