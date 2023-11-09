//the code is from chenjh
#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
int a[MAXN];
struct TIC{
	int u,c;
	TIC(int _u=0,int _c=0):u(_u),c(_c){}
	bool operator < (const TIC& y)const{return c<y.c&&(c==y.c&&u<y.u);}
}t[MAXN];
int e;
int main(){
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=k;i++) scanf("%d%d",&t[i].u,&t[i].c);
	scanf("%d",&e);
	
	for(int i=1;i<=n;i++) printf("%d\n",e);
	return 0;
}

