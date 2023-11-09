#include<bits/stdc++.h>
using namespace std;
int n,m,a[2004],b[2004];
int vis[2004][2],ans[2004],vis2[5004];
signed main(){
	freopen("marketplace.in","r",stdin);
	freopen("marketplace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d%d",&a[i],&b[i]);
	for(int hutao=1;hutao<=m;++hutao){
		memset(vis,0,sizeof(vis));memset(vis2,0,sizeof(vis2));
		int id=-1;
		for(int i=1;i<=n;++i){
			if(!vis[i][0]&&a[i]!=hutao&&!vis2[a[i]])vis[i][0]=1,vis2[a[i]]=1;
			else if(!vis[i][1]&&b[i]!=hutao&&!vis2[b[i]])vis[i][1]=1,vis2[b[i]]=1;
			else{id=i;break;}
		}
		if(id!=-1)ans[id]++;
		else{
			for(int i=1;i<=n;++i){
				if(!vis[i][0]&&a[i]!=hutao&&!vis2[a[i]])vis[i][0]=1,vis2[a[i]]=1;
				else if(!vis[i][1]&&b[i]!=hutao&&!vis2[b[i]])vis[i][1]=1,vis2[b[i]]=1;
				else{id=i;break;}
			}
			if(id==-1){
				for(int i=1;i<=n;++i){
					if(!vis[i][0]&&a[i]!=hutao&&!vis2[a[i]])vis[i][0]=1,vis2[a[i]]=1;
					else if(!vis[i][1]&&b[i]!=hutao&&!vis2[b[i]])vis[i][1]=1,vis2[b[i]]=1;
					else{id=i;break;}
				}
			}
			ans[id]++;
		}
	}
	for(int i=1;i<=n;++i)printf("%d\n",ans[i]);
	return 0;
}
