#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=1e6+10;
int n,m,a[N],b[N],vis[M],ans[N];
int pd[M];
int get(int x){
	memset(vis,0,sizeof(vis));
	int i=1;
	while(1){
		if(i>n)i=1;
		if(a[i]!=x&&!vis[a[i]]){
			vis[a[i]]=1;
			if(x==0)pd[a[i]]=1;
		}
		else if(b[i]!=x&&!vis[b[i]]){
			vis[b[i]]=1;
			if(x==0)pd[b[i]]=1;
		}
		else{
			break;
		}
		i++;
	}
	return i;
}
void sol1(){
	for(int x=1;x<=m;x++){
//		memset(vis,0,sizeof(vis));
//		int i=1;
//		while(1){
//			if(i>n)i=1;
//			if(a[i]!=x&&!vis[a[i]]){
//				vis[a[i]]=1;
//			}
//			else if(b[i]!=x&&!vis[b[i]]){
//				vis[b[i]]=1;
//			}
//			else{
//				break;
//			}
//			i++;
//		}
//		ans[i]++;
		ans[get(x)]++;
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",ans[i]);
	}
}
void sol2(){
	int t=get(0);
	for(int i=1;i<=m;i++){
		if(!pd[i])ans[t]++;
		else ans[get(i)]++;
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",ans[i]);
	}
}
int c[M],tot,d[M];
void jump(int x,int t){
	if(d[x])return;
	int i=pd[x]%n;
	if(i==0)i=n;
	int y;
	if(x==a[i])y=b[i];
	else y=a[i];
	if(!pd[y]){
		d[x]=t;
		return;
	}
	else if(pd[y]<pd[x]){
		d[x]=i;
		return;
	}
	else{
		jump(y,t);
		d[x]=d[y];
	}
}
void sol3(){
	memset(vis,0,sizeof(vis));
	int t=1;
	while(1){
		if(t>n)t=1;
		if(!vis[a[t]]){
			vis[a[t]]=1;
			c[++tot]=a[t];
			pd[a[t]]=tot;
		}
		else if(!vis[b[t]]){
			vis[b[t]]=1;
			c[++tot]=b[t];
			pd[b[t]]=tot;
		}
		else{
			break;
		}
		t++;
	}
	for(int x=1;x<=m;x++){
		if(!pd[x])ans[t]++;
		else{
			jump(x,t);
			ans[d[x]]++;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",ans[i]);
	}
}
signed main(){
	freopen("marketplace.in","r",stdin);
	freopen("marketplace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
	}
	if(n<=2000&&m<=5000)sol1();
	else if(n<=2000)sol2();
	else sol3();
	return 0;
}
