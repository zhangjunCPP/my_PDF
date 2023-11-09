//the code is from chenjh
#include<cstdio>
#include<cstdlib>
#define MAXN 250005
using namespace std;
int n,m,Q;
const int dx[8]={1,1,0,-1,-1,-1,0,1},dy[8]={0,1,1,1,0,-1,-1,-1};
struct Square{
	int X1,Y1,X2,Y2;
	Square(int _X1=0,int _Y1=0,int _X2=0,int _Y2=0):X1(_X1),Y1(_Y1),X2(_X2),Y2(_Y2){}
}s[MAXN];
struct Change{
	int v,r,d;
	Change(int _v=0,int _r=0,int _d=0):v(_v),r(_r),d(_d){}
}c[MAXN];
struct Question{
	int x,y;
	Question(int _x=0,int _y=0):x(_x),y(_y){}
	bool operator < (const Question&nxt){return x<nxt.x||(x==nxt.x&&y<nxt.y);} 
}q[MAXN];
long long ans[MAXN];
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=n;i++) scanf("%d%d%d%d",&s[i].X1,&s[i].Y1,&s[i].X2,&s[i].Y2);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&c[i].v,&c[i].r,&c[i].d);
	for(int i=1;i<=Q;i++) scanf("%d%d",&q[i].x,&q[i].y);//,q[i].id=i;
//	sort(q+1,q+Q+1);
	for(int i=1;i<=Q;i++)
		for(int j=1;j<=n;j++)ans[i]+=(s[j].X1<=q[i].x && q[i].x<=s[j].X2 && s[j].Y1<=q[i].y && q[i].y<=s[j].Y2);

	for(int i=1;i<=m;i++){
		Change nc=c[i];
		auto&ns=s[nc.r];
		for(int j=1;j<=nc.d;j++){
			ns.X1+=dx[nc.v],ns.X2+=dx[nc.v],
			ns.Y1+=dy[nc.v],ns.Y2+=dy[nc.v];
			for(int k=1;k<=Q;k++)ans[k]+=(ns.X1<=q[k].x && q[k].x<=ns.X2 && ns.Y1<=q[k].y && q[k].y<=ns.Y2);
		}
	}
	for(int i=1;i<=Q;i++) printf("%lld\n",ans[i]);
	return 0;
}

