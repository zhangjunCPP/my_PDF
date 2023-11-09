#include<bits/stdc++.h>
#define l1(i) a[i].l1
#define l2(i) a[i].l2
#define r1(i) a[i].r1
#define r2(i) a[i].r2
#define v(i) ques[i].v
#define id(i) ques[i].id
#define d(i) ques[i].d
const int QWQ=2.5e5+5;
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
} int p10[105][105];
struct user{ int v,id,d; } ques[1005];
struct mari{ int l1,l2,r1,r2; } a[QWQ];
int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,1,1,1,0,-1,-1,-1};
int n,m,q; mari b[1005];
inline void get_10(){
	for (int o=1;o<=n;o++){
		l1(o)=read(),r1(o)=read();
		l2(o)=read(),r2(o)=read();
		for (int i=l1(o);i<=l2(o);i++)
		for (int j=r1(o);j<=r2(o);j++)
			p10[i][j]++;
	} while (m--){
		int v=read(),id=read(),d=read();
		for (int k=1;k<=d;k++){
			int tl=l2(id)+dx[v]*k;
			int tr=r2(id)+dy[v]*k;
			for (int i=l1(id)+dx[v]*k;i<=tl;i++)
			for (int j=r1(id)+dy[v]*k;j<=tr;j++)
				p10[i][j]++;
		}
		l1(id)+=dx[v]*d,l2(id)+=dx[v]*d;
		r1(id)+=dy[v]*d,r2(id)+=dy[v]*d;
	} while (q--){
		int tx=read(),ty=read();
		printf("%d\n",p10[tx][ty]);
	}
}
bool in_it(int i,int x,int y){
	if (v(i)==0) return l1(i)<=x&&l2(i)+d>=x&&r1(i)<=y&&r2(i)>=y;
	if (v(i)==2) return l1(i)<=x&&l2(i)>=x&&r1(i)<=y&&r2(i)+d>=y;
	if (v(i)==4) return l1(i)-d<=x&&l2(i)>=x&&r1(i)<=y&&r2(i)>=y;
	if (v(i)==6) return l1(i)<=x&&l2(i)>=x&&r1(i)-d<=y&&r2(i)>=y;
	//pass
	return 0;
}
inline void get_20(){
	for (int i=1;i<=n;i++){
		l1(o)=read(),r1(o)=read();
		l2(o)=read(),r2(o)=read();
	} for (int i=1;i<=m;i++)
		v(i)=read(),id(i)=read(),d(i)=read();
	while (q--){
		int tx=read(),ty=read(),res=0;
		for (int i=1;i<=n;i++)
			if (l1(i)<=tx&&l2(i)>=tx&&r1(i)<=ty&&r2(i)<=ty) res++;
		for (int i=1;i<=n;i++) b[i]=a[i];
		for (int i=1;i<=m;i++){
			if (in_it(i,tx,ty)){
				
			}
			l1(id(i))+=dx[v(i)]*d(i),l2(id(i))+=dx[v(i)]*d(i);
			r1(id(i))+=dy[v(i)]*d(i),r2(id(i))+=dy[v(i)]*d(i);
		} for (int i=1;i<=n;i++) a[i]=b[i];
		printf("%d\n",res);
	}
}
inline void get_10s(){
	
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	n=read(),m=read(),q=read();
	if (n<=100&&m<=100&&q<=100){ get_10(); return 0; }
//	if (n<=1000&&m<=1000&&q<=1000){ get_20(); return 0; }
	if (!m){ get_10s(); return 0; } 
	return 0;
}
