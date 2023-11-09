//the code is from chenjh
#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k,L;
struct Dragon{
	int d,b;
	bool w;
	bool die(){
		return (!d&&!w)||(d==L&&w);
	}
}a[MAXN];
int ans[MAXN];
int main(){
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
	scanf("%d%d%d",&n,&k,&L);
	for(int i=1;i<=n;i++){
		char op[3];
		scanf("%d %d %s",&a[i].d,&a[i].b,op);
		ans[a[i].b]=max(ans[a[i].b],max(a[i].d,L-a[i].d));
		a[i].w=op[0]=='D';
	}
	for(int i=0;i<k;i++)printf("%.1lf\n",(double)ans[i]);
	return 0;
}

