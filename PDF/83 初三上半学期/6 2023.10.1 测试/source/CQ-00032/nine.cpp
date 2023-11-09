using namespace std;
#include<bits/stdc++.h>
#define int long long 
#define LL int
#define N 100005
#define INF (1e18)
#define M 100005
#define P 1000000007
template<typename T>
void read(T&x){x=0;char c=getchar();int fl=1;
while(c<'0'||'9'<c){if(c=='-')fl=-1;c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}x*=fl;}
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
int tx,ty;
int k;
int c(int x,int y){
//	return 0;
	return (abs(x-tx)+abs(y-ty)+k-1)/k;
}
struct st{
	int x,y,stp;
	bool operator < (const st& oth) const{
		return stp+c(x,y)>stp+c(oth.x,oth.y);
	} 
};
map<pair<int,int>,pair<int,int> >s;
priority_queue<st> q;
int mv[]={1,0,-1,0};
const int IMX=2147483647;
int bfs(){
	q.push({0,0,0});
	while(!q.empty()){
		st u=q.top();
		q.pop();
		if(u.x==tx&&u.y==ty)return u.stp;
		if(clock()>1200)return -1;
		for(int i=0;i<=3;i++){
			for(int j=0;j<=k;j++){
				int nx=u.x+j*mv[i],ny=u.y+(k-j)*mv[3-i];
				if(s.find({nx,ny})!=s.end())continue;
				if(nx<-IMX||nx>IMX||ny<-IMX||ny>IMX)continue;
				q.push({nx,ny,u.stp+1});
				s[{nx,ny}]={u.x,u.y};
				if(nx==tx&&ny==ty)return u.stp+1;
				if(clock()>1200)return -1;
			}
		}
	}
	return -1;
}
signed main(){
	freopen("nine.in","r",stdin);
	freopen("nine.out","w",stdout);
	read(k);
	read(tx);
	read(ty);
	printf("%lld\n",bfs());
	stack<pair<int,int> > stk;
	pair<int,int> p={tx,ty};
	if(s.find(p)==s.end())return 0;
	while(p!=pair<int,int>{0,0}){
		stk.push(p);
		p=s[p];
	}
	while(stk.size()){
		printf("%lld %lld\n",stk.top().first,stk.top().second);
		stk.pop();
	}
	return 0;
}
/*
11 1 -2

*/
