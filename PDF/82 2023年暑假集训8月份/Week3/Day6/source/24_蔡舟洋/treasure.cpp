#include<bits/stdc++.h>
using namespace std;
const int N=26;
int n;
struct node{
	int a,id;
}d[N];
int a[N];
bool cmp(node a,node b){return a.a<b.a;}
int ans=1e9;
int bl[N],pos[N],k;
int max(int a,int b){return a>b?a:b;}
int abs(int a){return a<0?-a:a;}
void dfs(int p,int t1,int t2,int t3){
	if(p==n+1){
		int tmp=max(abs(t1-t2),max(abs(t1-t3),abs(t2-t3)));
		if(tmp<ans){
			ans=tmp;
			for(int i=1;i<=n;i++)pos[i]=bl[i];
		}
		return;
	}
	if(t1<=k&&t1+a[p]<=t2)bl[p]=1,dfs(p+1,t1+a[p],t2,t3);
	if(t2<=k&&t2+a[p]<=t3)bl[p]=2,dfs(p+1,t1,t2+a[p],t3);
	if(t3<=k)bl[p]=3,dfs(p+1,t1,t2,t3+a[p]);
}
int main(){
	freopen("treasure.in","w",stdin);
	freopen("treasure.out","r",stdout);
	scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&d[i].a),k+=d[i].a,d[i].id=i;
	k/=3;
//	int p=clock();
	sort(d+1,d+1+n,cmp);reverse(d+1,d+1+n);
	for(int i=1;i<=n;i++)a[i]=d[i].a;
//	cerr<<k<<endl;
	dfs(1,0,0,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)if(d[j].id==i){
			printf("%d ",pos[j]);
			break;
		}
	}
//	cerr<<endl<<clock()-p;
	return 0;
}

