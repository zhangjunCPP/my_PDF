#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define Maxn 2500
int x,y,k;
int dis[5005][5005],tot;
pair<int,int> lst[5005][5005],out[1000005];
int go[4][2]={{1,-1},{1,1},{-1,1},{-1,-1}};
void Freopen(){
	freopen("nine.in","r",stdin);
	freopen("nine.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d%d%d",&k,&x,&y);
	queue< pair<int,int> > Q;
	memset(dis,-0x3f,sizeof(dis));
	dis[Maxn][Maxn]=0;
	Q.push({Maxn,Maxn});
	while(Q.size()){
		int x=Q.front().first,y=Q.front().second;
		//printf("%d %d %d\n",x,y,dis[x][y]);
		Q.pop();
		for(int i=0;i<=k;i++){
			for(int j=0;j<4;j++){
				int tx=x+go[j][0]*i,ty=y+go[j][1]*(k-i);
				if(tx<1||ty<1||tx>5000||ty>5000||dis[tx][ty]!=dis[0][0])continue;
				dis[tx][ty]=dis[x][y]+1;
				lst[tx][ty]={x,y};
				Q.push({tx,ty});
			}
		}
	}
	if(dis[x+Maxn][y+Maxn]==dis[0][0])puts("-1");
	else{
		while(x!=Maxn||y!=Maxn){
			out[++tot]={x,y};
			int tx=lst[x][y].first,ty=lst[x][y].second;
			x=tx,y=ty;
		}
		for(int i=tot;i>=1;i--)
			printf("%d %d\n",out[i].first-Maxn,out[i].second-Maxn);
		
	}
	
}
