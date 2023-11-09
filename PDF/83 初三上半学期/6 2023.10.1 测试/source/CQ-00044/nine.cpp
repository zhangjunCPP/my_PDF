//#include<bits/stdc++.h>
//using namespace std;
//int n=200,m=200,mv=100,d=17;
//int dis[2000][2000];
//int main(){
//	freopen("biao","w",stdout);
//	memset(dis,-1,sizeof(dis));
//	queue<pair<int,int>>q;
//	q.emplace(mv,mv);dis[mv][mv]=0; 
//	for(int x,y;!q.empty();){
//		tie(x,y)=q.front(),q.pop();
//		for(int dx=-d;dx<=d;dx++)
//		for(int dy:{d-abs(dx),-(d-abs(dx))}){
//			int tx=x+dx,ty=y+dy;
//			if(tx>=0&&tx<n&&ty>=0&&ty<m&&dis[tx][ty]==-1)
//			dis[tx][ty]=dis[x][y]+1,q.emplace(tx,ty);
//		}
//	}
//	for(int i=0;i<n;puts(""),i++)
//	for(int j=0;j<m;j++)
//	putchar(".#"[dis[i][j]==3]);
////	printf("%d ",dis[i][j]);
//	return 0;
//}
//打表看着是个跟奇偶有关的
//也对,偶数时只能走到奇偶坐标一样的点上
//斯...想起来了,这不就是那个(x,y)->(x+y,x-y)的映射吗,*,这样每次就是在某个坐标上加/减2k了
//ooo不对
//
//#include<bits/stdc++.h>
//using namespace std;
//int main(){
//	return 0;
//} 
#include<bits/stdc++.h>
using namespace std;
int k,qx,qy,mv=500;
int dis[1010][1010];
pair<int,int>fr[1010][1010];
void print(int x,int y){
	if(x==mv&&y==mv)return;
	print(fr[x][y].first,fr[x][y].second);
	cout<<x-mv<<' '<<y-mv<<endl;
}
int main(){
	freopen("nine.in","r",stdin);
	freopen("nine.out","w",stdout);
	memset(dis,-1,sizeof(dis));
	cin>>k>>qx>>qy;
	if(k%2==0&&(qx&1)!=(qy&1))return cout<<-1,0;
	queue<pair<int,int>>q;
	q.emplace(mv,mv);dis[mv][mv]=0; 
	for(int x,y;!q.empty();){
		tie(x,y)=q.front(),q.pop();
		if(x==qx+mv&&y==qy+mv){print(x,y);return 0;}
		for(int dx=-k;dx<=k;dx++)
		for(int dy:{k-abs(dx),-(k-abs(dx))}){
			int tx=x+dx,ty=y+dy;
			if(tx>=0&&tx<1000&&ty>=0&&ty<1000&&dis[tx][ty]==-1)
			dis[tx][ty]=dis[x][y]+1,fr[tx][ty]={x,y},q.emplace(tx,ty);
		}
	}
	return 0;
}
