#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<iterator>
#include<vector>
#include<queue>

#define Genshin_Impact_starts ios::sync_with_stdio(false)
#define ll long long
#define F first
#define S second
#define eps 1e-6
#define For(i,s,t) for(int i=s;i<=t;i++)
#define rFor(i,s,t) for(int i=s;i>=t;i--)

using namespace std;

int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
void swap(int &a,int &b){a=a^b,b=a^b,a=a^b;}
void Freopen(){
	freopen("klein.in","r",stdin);
	freopen("klein.out","w",stdout);
}

const int N=2e6+10,M=1e6+10,inf=1e9+10;
int n,q;
int dis[150][150];
int id[150][150];

signed main(){
	Freopen();
	Genshin_Impact_starts;
	cin.tie(0),cout.tie(0);
	memset(dis,0x3f,sizeof(dis));
	cin>>n>>q;
	int cnt=0;
	For(i,0,n)For(j,0,n)id[i][j]=++cnt;
	For(i,0,n)For(j,0,n){
			if(i>=1){
				dis[id[i][j]][id[i-1][j]]=dis[id[i-1][j]][id[i][j]]=1;
				dis[id[i][0]][id[i][n]]=dis[id[i][n]][id[i][0]]=1;
			}
			if(j>=1){
				dis[id[i][j]][id[i][j-1]]=dis[id[i][j-1]][id[i][j]]=1;
				dis[id[0][j]][id[n][n-j]]=dis[id[n][n-j]][id[0][j]]=1;
			}
		}
	For(k,1,n*n+2*n+1)For(i,1,n*n+2*n+1)For(j,1,n*n+2*n+1){
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	while(q--){
		int a1,b1,a2,b2;
		cin>>a1>>b1>>a2>>b2;
		cout<<dis[id[a1][b1]][id[a2][b2]]<<endl;
	}
}
/*
10 5
1 9 10 1
7 4 5 4
1 1 3 1
6 6 0 2
10 2 6 1

2
2
2
7
5
*/