#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T&x){
x=0;char c=getchar();/*T fl=1;*/while(c<'0'||'9'<c){/*if(c=='-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}/*x*=fl*/}
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
#define N 100005
#define INF 2000000000
int n;
int a[N];
int ans=INF;
void dfs(int u,int mx,int mn){
	if(u==n+1){
		ans=Min(ans,mx-mn);
		return ;
	}
	if(mx-mn>ans)return ;
	dfs(u+1,Max(mx,a[u]),Min(mn,a[u]));
	if(u<n)dfs(u+2,Max(mx,a[u]+a[u+1]),Min(mn,a[u]+a[u+1]));
}
int main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	read(n); 
	for(int i=1;i<=n;i++)read(a[i]);
	dfs(1,-INF,INF);
	printf("%d",ans);
	return 0;
}
/*
5
2 2 3 5 2
*/
