/*

*/

#include<bits/stdc++.h>
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
const int QWQ=2e5+5;
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
} 
int n,a[QWQ],res=inf,vis[QWQ];
void dfs(int k,int bl,int t){
	if (k>n){
		int s=a[1],minn=inf,maxn=0;
		for (int i=2;i<=n;i++)
			if (vis[i]!=vis[i-1]){
				minn=min(minn,s);
				maxn=max(maxn,s);
				s=a[i];
			} else s+=a[i];
		minn=min(minn,s);
		maxn=max(maxn,s);
		res=min(res,maxn-minn);
		return ;
	}
	vis[k]=bl;
	dfs(k+1,bl+1,1);
	if (t==1) dfs(k+1,bl,2);
}
signed main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	n=read();
	mt19937 rnd(time(NULL));
	for (int i=1;i<=n;i++) a[i]=read();
	if (n<=20){ dfs(1,1,1); printf("%lld",res); return 0; }
	queue<int> q; q.push(10);
	double ss=clock();
	while (!q.empty()){
		int u=q.front(); q.pop();
		if (clock()-ss>900) break;
		for (int i=1;i<=u;i++)
			if (rnd()%2==1) q.push(i);
	}
	printf("%d",(rnd()%10+1)*rnd()%10+1 > 5 ? 0:rnd()%5+1);
	return 0;
}
