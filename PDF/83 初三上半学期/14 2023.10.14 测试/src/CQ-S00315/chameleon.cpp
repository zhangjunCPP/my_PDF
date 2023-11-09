#include<bits/stdc++.h>
const int QWQ=1e5+5;
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<1)+(x<<3)+(ch^48); ch=getchar(); }
	return x*f;
}
struct dots{ double pos; int col; } ls[QWQ],rs[QWQ];
int n,k,l,cntl,cntr; char ch[5]; double res[55],ca[QWQ];
inline bool cmp(dots x,dots y){ return x.pos<y.pos; }
signed main(){
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
	n=read(),k=read(),l=read();
	for (int i=1;i<=n;i++){
		int x=read(),y=read(); scanf("%s",ch);
		if (ch[0]=='L') ls[++cntl]={x,y};
		if (ch[0]=='D') rs[++cntr]={x,y};
	} 
	sort(ls+1,ls+cntl+1,cmp);
	sort(rs+1,rs+cntr+1,cmp);
	for (int i=1;i<=cntr;i++)
		res[rs[i].col]+=l-rs[i].pos; 
	for (int i=1;i<=cntl;i++){
		double now=ls[i].pos,move=0.0;
		int nowc=ls[i].col,cur=cntr;
		while (rs[cur].pos>now) cur--;
		if (!cur){ res[nowc]+=now; continue; }
		do{
			double dis=(now-rs[cur].pos-move)/2.0;
			res[nowc]+=dis,now-=dis,move+=dis;
			nowc=(nowc+rs[cur].col)%k,cur--;
		} while (cur>0);
		if (now>0) res[nowc]+=now;
	}
	for (int i=0;i<k;i++)
		printf("%.1lf\n",res[i]);
	return 0;
}
