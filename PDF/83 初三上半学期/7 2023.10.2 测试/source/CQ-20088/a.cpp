#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+10,N=1e3;
const int MAXM=2e5+5e4+10;
template <typename T>
inline void read(T &x){
	bool f=0; x=0; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=1; ch=getchar();}
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x=f?-x:x;
}
template <typename T,typename ...Args>
inline void read(T &x,Args &...args){read(x); read(args...);}
int n,m,q,tot; 
//map<pair<int,int> ,int> tree; 
int tree[MAXN<<1][MAXN<<1];
//vector<int> tree[MAXM<<1];
int dir[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
struct node{
	int x1,y1,x2,y2;
}a[MAXM];
inline int lowbit(int x){return x&(-x);}
inline void update(int x,int y,int val){
	for(int i=x;i<=(N<<1);i+=lowbit(i))
		for(int j=y;j<=(N<<1);j+=lowbit(j))
			tree[i][j]+=val;
}
inline int query(int x,int y){
	int res=0;
	for(int i=x;i;i-=lowbit(i))
		for(int j=y;j;j-=lowbit(j))
			res+=tree[i][j];
	return res;
}
inline void add(int x1,int y1,int x2,int y2){
	update(x1,y1,1); update(x2+1,y1,-1); 
	update(x1,y2+1,-1); update(x2+1,y2+1,1); 
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	read(n,m,q);
	for(int i=1;i<=n;i++){
		int x1,y1,x2,y2; read(x1,y1,x2,y2);
		add(x1+N,y2+N,x2+N,y1+N); a[++tot]={x1+N,y2+N,x2+N,y1+N};
	}
	for(int i=1;i<=m;i++){
		int v,num,d; read(v,num,d);
		for(int j=0;j<d;j++){
			int dx1=a[num].x1+j*dir[v][0];
			int dy1=a[num].y1+j*dir[v][1];
			int dx2=a[num].x2+j*dir[v][0];
			int dy2=a[num].y2+j*dir[v][1];
//			printf("dx1:%d dy1:%d dx2:%d dy2:%d\n",dx1-N,dy1-N,dx2-N,dy2-N);	
			add(dx1,dy1,dx2,dy2);
		}
		a[num].x1+=d*dir[v][0];
		a[num].y1+=d*dir[v][1];
		a[num].x2+=d*dir[v][0];
		a[num].y2+=d*dir[v][1];
	}
//	for(int i=1;i<=5;i++){
//		for(int j=1;j<=5;j++){
//			printf("%d ",query(i+N,j+N));
//		}
//		printf("\n");
//	}
	while(q--){
		int px,py; read(px,py);
		printf("%d\n",query(px+N,py+N));
	}
	return 0;
}
/*
1 0 1
1 3 3 1 
2 3
*/
