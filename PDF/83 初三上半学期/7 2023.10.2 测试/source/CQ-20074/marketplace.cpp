#include<bits/stdc++.h>
using namespace std;
int n,m,oth;
int a[100005],b[100005],ans[100005];
bool vis[1000005],vis2[1000005];
int Get(int x){
	for(int i=1;i<=n;i++)vis2[a[i]]=vis2[b[i]]=0;
	while(1){
		for(int i=1;i<=n;i++){
			if(a[i]!=x&&!vis2[a[i]])vis2[a[i]]=1;
			else if(b[i]!=x&&!vis2[b[i]])vis2[b[i]]=1;
			else return i;
		}	
	}
	return 1919810-114514;
}
void Freopen(){
	freopen("marketplace.in","r",stdin);
	freopen("marketplace.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]),vis[a[i]]=vis[b[i]]=1;
	oth=Get(0);
	for(int i=1;i<=m;i++)
		if(vis[i])++ans[Get(i)];
		else ++ans[oth];
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
}
