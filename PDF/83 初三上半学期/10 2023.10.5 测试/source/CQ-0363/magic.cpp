#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
typedef long long ll;
const int E=1e6+17;
const int N=1019;
int v[E<<1],nxt[E<<1],head[E],tot;
int rdu[N],l[N],r[N],c[N];
int vv[N][N],n,stk[N],top;
bool vis[N];
ll ans;
queue<int>q;
void add(int fr,int to){
//	printf("%d %d\n",fr,to);
	v[++tot]=to;
	nxt[tot]=head[fr];
	head[fr]=tot;
	return;
}
signed main(){
//	freopen("D:\\down\\magic\\magic2.in","r",stdin);
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&l[i],&r[i],&c[i]);
		for(int j=l[i];j<=r[i];j++){
			if(i!=j){
				vv[i][j]=c[i];
			}
		}
	}
//	printf("%d %d\n",vv[6][8],vv[8][6]);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
//			if(i==j)continue;
			if(vv[i][j]>vv[j][i]){
				add(i,j);
				rdu[j]++;
			}
			if(vv[j][i]>vv[i][j]){
				add(j,i);
				rdu[i]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(rdu[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int pos=q.front();
		q.pop();
		stk[++top]=pos;
		for(int i=head[pos];i!=0;i=nxt[i]){
			rdu[v[i]]--;
			if(rdu[v[i]]==0){
				q.push(v[i]);
			}
		}
	}
	while(top<n){
		int mx=0;
		for(int i=1;i<=n;i++){
			if(rdu[i]>0&&c[i]>c[mx]){
				mx=i;
			}
		}
		rdu[mx]=0;
		q.push(mx);
		while(!q.empty()){
			int pos=q.front();
			q.pop();
			stk[++top]=pos;
			for(int i=head[pos];i!=0;i=nxt[i]){
				rdu[v[i]]--;
				if(rdu[v[i]]==0){
					q.push(v[i]);
				}
			}
		}
	}
//	for(int i=1;i<=top;i++){
//		printf("%d ",stk[i]);
//	}
//	printf("\n");
	for(int i=1;i<=top;i++){
		int now=stk[i];
		vis[now]=true;
		for(int j=l[now];j<=r[now];j++){
			if(!vis[j]){
				ans+=c[now];
			}
		}
	}
	printf("%lld",ans);
}
