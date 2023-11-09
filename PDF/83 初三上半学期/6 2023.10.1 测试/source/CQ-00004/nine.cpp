#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<1)+(x<<3)+(ch^48); ch=getchar(); }
	return x*f;
} int ttt;
inline int abs(const int x){ return x<0 ? -x:x; }
map<pair<int,int>,int> mp;
struct node{ int x,y; };
queue<node> q; map<pair<int,int>,pair<int,int> > sp;
int upx,upy,downx,downy,k,tx,ty;
inline bool cheak(int x,int y){
	return x<downx||y<downy||x>upx||y>upy;
}
void print(pair<int,int> u){
	if (!u.first&&!u.second) return ;
	print(sp[u]);
	printf("%d %d\n",u.first,u.second);
}
inline void out(){
	print({tx,ty});
}
signed main(){
	freopen("nine.in","r",stdin);
	freopen("nine.out","w",stdout);
	k=read(),tx=read(),ty=read();
	upx=abs(tx)+k,upy=abs(ty)+k,downx=-abs(tx)-k,downy=-abs(ty)-k;
	if (k==1){ printf("%d",abs(tx)+abs(ty)); return 0; }
//	if (abs(tx)>10||abs(ty)>10||k>10){ printf("-1"); return 0; }
	q.push({0,0}); mp[{0,0}]=0;
	while (!q.empty()){
		if (ttt>4000000){ printf("-1"); return 0; }
		node now=q.front(); q.pop();
		int pd=mp[{now.x,now.y}]+1;
		for (int i=k,j=0;i;i--,j++){
			int px=now.x+i,py=now.y+j;
			if (cheak(px,py)||mp[{px,py}]==1) continue;
			mp[{px,py}]=pd;
			sp[{px,py}]={now.x,now.y};
			if (px==tx&&py==ty){ printf("%d\n",pd); out(); return 0; } 
			q.push({px,py}),ttt++;
		}
		for (int j=k,i=0;j;j--,i--){
			int px=now.x+i,py=now.y+j;
			if (cheak(px,py)||mp[{px,py}]==1) continue;
			mp[{px,py}]=pd;
			sp[{px,py}]={now.x,now.y};
			if (px==tx&&py==ty){ printf("%d\n",pd); out(); return 0; } 
			q.push({px,py}),ttt++;
		}
		for (int i=-k,j=0;i<=-1;i++,j--){
			int px=now.x+i,py=now.y+j;
			if (cheak(px,py)||mp[{px,py}]==1) continue;
			mp[{px,py}]=pd;
			sp[{px,py}]={now.x,now.y};
			if (px==tx&&py==ty){ printf("%d\n",pd); out(); return 0; } 
			q.push({px,py}),ttt++;
		}
		for (int j=-k,i=0;j>=-1;i++,j++){
			int px=now.x+i,py=now.y+j;
			if (cheak(px,py)||mp[{px,py}]==1) continue;
			mp[{px,py}]=pd;
			sp[{px,py}]={now.x,now.y};
			if (px==tx&&py==ty){ printf("%d\n",pd); out(); return 0; } 
			q.push({px,py}),ttt++;
		}
	} 
	return 0;
}
/*
11 1 -2

#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<1)+(x<<3)+(ch^48); ch=getchar(); }
	return x*f;
} int ttt;
inline int abs(const int x){ return x<0 ? -x:x; }
map<pair<int,int>,int> mp[2];
struct node{ int x,y,who; };
queue<node> q; map<pair<int,int>,pair<int,int>> sp;
int upx,upy,downx,downy,k,x,y;
inline bool cheak(int x,int y){
	return x<downx||y<downy||x>upx||y>upy;
}
void print(pair<int,int> u){
	if (!u.first&&!u.second) return ;
	print(sp[u]);
	printf("%d %d\n",u.first,u.second);
}
inline void out(){
	print({x,y});
}
signed main(){
	k=read(),x=read(),y=read();
	upx=abs(x)+k,upy=abs(y)+k,downx=-abs(x)-k,downy=-abs(y)-k;
	if (k==1){ printf("%d",abs(x)+abs(y)); return 0; }
//	if (abs(x)>10||abs(y)>10||k>10){ printf("-1"); return 0; }
	q.push({0,0,0}),q.push({x,y,1});
	mp[0][{0,0}]=mp[1][{x,y}]=0;
	while (!q.empty()){
		if (ttt>1000000){ printf("-1"); return 0; }
		node now=q.front(); q.pop();
		int pt=now.who,pd=mp[pt][{now.x,now.y}]+1;
		for (int i=k,j=0;i;i--,j++){
			int px=now.x+i,py=now.y+j;
			if (cheak(px,py)||mp[pt][{px,py}]==1) continue;
			mp[pt][{px,py}]=pd;
			if (pt) sp[{now.x,now.y}]={px,py};
			else sp[{px,py}]={now.x,now.y};
			cout<<now.x<<' '<<now.y<<"->"<<px<<' '<<py<<endl;
			if (mp[pt^1].find({px,py})!=mp[pt^1].end())
				{ printf("%d\n",pd+mp[pt^1][{px,py}]); out(); return 0; } 
			q.push({px,py,pt}),ttt++;
		}
		for (int j=k,i=0;j;j--,i--){
			int px=now.x+i,py=now.y+j;
			if (cheak(px,py)||mp[pt][{px,py}]==1) continue;
			mp[pt][{px,py}]=pd;
			if (pt) sp[{now.x,now.y}]={px,py};
			else sp[{px,py}]={now.x,now.y};
			cout<<now.x<<' '<<now.y<<"->"<<px<<' '<<py<<endl;
			if (mp[pt^1].find({px,py})!=mp[pt^1].end())
				{ printf("%d\n",pd+mp[pt^1][{px,py}]); out(); return 0; } 
			q.push({px,py,pt}),ttt++;
		}
		for (int i=-k,j=0;i<=-1;i++,j--){
			int px=now.x+i,py=now.y+j;
			if (cheak(px,py)||mp[pt][{px,py}]==1) continue;
			mp[pt][{px,py}]=pd;
			if (pt) sp[{now.x,now.y}]={px,py};
			else sp[{px,py}]={now.x,now.y};
			cout<<now.x<<' '<<now.y<<"->"<<px<<' '<<py<<endl;
			if (mp[pt^1].find({px,py})!=mp[pt^1].end())
				{ printf("%d\n",pd+mp[pt^1][{px,py}]); out(); return 0; } 
			q.push({px,py,pt}),ttt++;
		}
		for (int j=-k,i=0;j>=-1;i++,j++){
			int px=now.x+i,py=now.y+j;
			if (cheak(px,py)||mp[pt][{px,py}]==1) continue;
			mp[pt][{px,py}]=pd;
			if (pt) sp[{now.x,now.y}]={px,py};
			else sp[{px,py}]={now.x,now.y};
			cout<<now.x<<' '<<now.y<<"->"<<px<<' '<<py<<endl;
			if (mp[pt^1].find({px,py})!=mp[pt^1].end())
				{ printf("%d\n",pd+mp[pt^1][{px,py}]); out(); return 0; } 
			q.push({px,py,pt}),ttt++;
		}
	} 
	printf("*");
	return 0;
}
/*
11 1 -2
*/
*/
