#include<bits/stdc++.h>
using namespace std;
inline int rd(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w;
}
inline void wr(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)wr(x/10);
	putchar(x%10+'0');
}
inline void FRE(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
}
const int N=1e7,M=2.5e5+5;
int n,m,q,tot;
int way[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
struct node{
	int x1,y1,x2,y2;
}eg[N];
map<int,int> sum[M];
inline void add(int x,int y,int vl){
	for(int i=x;i<=M;i+=i&(-i)){
		for(int j=y;j<=M;j+=j&(-j)){
			sum[i][j]+=vl;
		}
	}
}
inline int query(int a,int b){
	int res=0;
	for(int i=a;i;i-=i&(-i)){
		for(int j=b;j;j-=j&(-j)){
			res+=sum[i][j];
		}
	}
	return res;
}
int main(){
	FRE();
	n=rd(),m=rd(),q=rd();
	for(int i=1;i<=n;++i){
		int a=rd(),b=rd();
		int c=rd(),d=rd();
		eg[i]={a,b,c,d};
	}
	tot=n;
	for(int i=1;i<=m;++i){
		int id=rd(),s=rd(),d=rd();
		int a=eg[s].x1,b=eg[s].y1;
		int c=eg[s].x2,D=eg[s].y2;
		int f1=way[id][0],f2=way[id][1];
		for(int j=0;j<=d;++j){
			if(j==d)eg[s]={a+j*f1,b+j*f2,c+j*f1,D+j*f2};
			else eg[++tot]={a+j*f1,b+j*f2,c+j*f1,D+j*f2};
		}
	}
	if(m==0){
		for(int i=1;i<=n;++i){
			int a=eg[i].x1,b=eg[i].y1,c=eg[i].x2,d=eg[i].y2;
			add(a,b,1);add(a,d+1,-1);add(c+1,b,-1);add(c+1,d+1,1);
		}
		for(int i=1;i<=q;++i){
			int x=rd(),y=rd();
			printf("%d\n",query(x,y));
		}
		return 0;
	}
	while(q--){
		int x=rd(),y=rd();
		int ans=0;
		for(int i=1;i<=tot;++i){
			if(eg[i].x1<=x&&x<=eg[i].x2&&eg[i].y1<=y&&y<=eg[i].y2){
				ans++;
			}
		}
		wr(ans);putchar('\n');
	}
}
/*
2 0 10
1 1 2 2
2 1 3 2
2 1
2 2 
1 2
2 1
*/

