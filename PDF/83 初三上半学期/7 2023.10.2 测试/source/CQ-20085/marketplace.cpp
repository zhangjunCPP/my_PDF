#include<bits/stdc++.h>
using namespace std;
int n,m,luck,a[100001],b[100001],vis[1000001],ans[100001],now[1000001];
int check(int x){
	for(int i=1;i<=n;i++){
		if(!now[a[i]]&&a[i]!=x) now[a[i]]=1;
		else if((now[a[i]]||a[i]==x)&&!now[b[i]]&&b[i]!=x) now[b[i]]=1;
		else{
			for(int j=1;j<=n;j++) now[a[j]]=now[b[j]]=0;
			return i;
		}
		if(i==n) i=0;
	}
}
int main(){
	freopen("marketplace.in","r",stdin);
	freopen("marketplace.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]),vis[a[i]]=vis[b[i]]=1;
	luck=check(0);
	for(int i=1;i<=m;i++){
		if(!vis[i]) ans[luck]++;
		else ans[check(i)]++;
	}
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}
