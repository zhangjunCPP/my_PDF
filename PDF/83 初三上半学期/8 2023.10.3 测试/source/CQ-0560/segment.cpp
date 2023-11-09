//the code is from chenjh
#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int n;
int a[MAXN];
int ans=0;
inline int Max(int&x,const int y){return x=x>y?x:y;}
inline int Min(int&x,const int y){return x=x<y?x:y;}
void dfs(const int pos,const int mx,const int mn){
	if(pos>1 && mx-mn>=ans) return;
	if(pos>n){Min(ans,mx-mn);return;}
	if(pos<n) dfs(pos+2,max(mx,a[pos]+a[pos+1]),min(mn,a[pos]+a[pos+1]));
	dfs(pos+1,max(mx,a[pos]),min(mn,a[pos]));
}
void dfs1(const int pos,const int mx,const int mn){
	if(mx-mn>=ans) return;
	if(pos>n){Min(ans,mx-mn);return;}
	if(pos<n) dfs1(pos+2,max(mx,a[pos]+a[pos+1]),min(mn,a[pos]+a[pos+1]));
	dfs1(pos+1,max(mx,a[pos]),min(mn,a[pos]));
}
int main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	scanf("%d",&n);
	int mx=0,mn=2000000000;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),Max(mx,a[i]),Min(mn,a[i]);
	ans=mx-mn;
//	fprintf(stderr,"%d\n",ans);
	if(n<=18)dfs(1,0,2000000000);
//	else dfs1(1,0,2000000000);
	printf("%d\n",ans);
	return 0;
}

