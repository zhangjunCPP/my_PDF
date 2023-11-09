#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
inline void work(int k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
int n,m,cnt,val[100005],val1[100005],first[1000005],ans[100005],vis[1000005],sum[1000005],las,du[1000005],tim[1000005];
int h[1000005][2],sum1[1000005],vis2[1000005],flag;
struct q1{
	int u,w,v,nex;
}a[200005];
void add(int u1,int w1,int v1){
	a[++cnt]={u1,w1,v1,first[u1]};
	first[u1]=cnt;
}
int cmp(int flag,int las,int t){
	return (flag==3?t:(flag==2?min(las,t):las));
}
int dfs(int u,int last_val,int t){
	if(tim[u])
		return vis[u];
	tim[u]=t;
	int f=0;
	for(int i=first[u];i;i=a[i].nex){
		if(tim[a[i].w]==t){
			if(a[i].v<h[a[i].w][0]){
				h[a[i].w][1]=h[a[i].w][0];
				h[a[i].w][0]=a[i].v;
			}
			else if(a[i].v<h[a[i].w][1])
				h[a[i].w][1]=a[i].v;
			if(h[a[i].w][1]){
				vis[u]=min(vis[u],h[a[i].w][1]);
				f=1;
			}
			continue;
		}
		if(a[i].v<last_val){
			vis[u]=min(vis[u],last_val);
			f=1;
			continue;
		}
		h[a[i].w][0]=a[i].v;
		f|=dfs(a[i].w,a[i].v,t);
		vis[u]=min(vis[a[i].w],vis[u]);
	}
	if(!f)
		vis[u]=min(vis[u],cmp(flag,las,sum1[u]));
	return f;
}
int main(){
//	freopen("marketplace.in","r",stdin);
//	freopen("marketplace.out","w",stdout);
	n=read();
	m=read();
	memset(sum1,31,sizeof(sum1));
	for(int i=1,x,y;i<=n;i++){
		x=read();
		y=read();
		sum[x]++;
		sum[y]++;
		sum1[x]=min(sum1[x],i);
		sum1[y]=min(sum1[y],i);
		du[y]++;
		val[i]=x,val1[i]=y;
	}
	for(int i=n;i;i--){
		add(val[i],val1[i],i);
	}
	if(n<=2000&&m<=5000){
		for(int i=1;i<=m;i++){
			int flag=0;
			for(int j=1;j<=m;j++){
				vis[j]=0;
			}
			for(int j=1;j<=n;j++){
				if(val[j]!=i&&!vis[val[j]])
					vis[val[j]]=1;
				else if(val1[j]!=i&&!vis[val1[j]])
					vis[val1[j]]=1;
				else{
					ans[j]++;
					flag=1;
					break;
				}
			}
			if(!flag){
				for(int j=1;j<=n;j++){
					if(val[j]!=i&&!vis[val[j]])
						vis[val[j]]=1;
					else if(val1[j]!=i&&!vis[val1[j]])
						vis[val1[j]]=1;
					else{
						ans[j]++;
						flag=1;
						break;
					}
				}
			}
			if(!flag)
				ans[1]++;
		}
		for(int i=1;i<=n;i++){
			work(ans[i]);
			putchar('\n');
		}
		return 0;
	}
	for(int j=1;j<=n;j++){
		if(!vis[val[j]])
			vis[val[j]]=1;
		else if(!vis[val1[j]])
			vis[val1[j]]=1;
		else{
			las=j;
			flag=1;
			break;
		}
	}
	if(!flag){
		for(int j=1;j<=n;j++){
			if(!vis[val[j]])
				vis[val[j]]=1;
			else if(!vis[val1[j]])
				vis[val1[j]]=1;
			else{
				las=j;
				flag=2;
				break;
			}
		}
	}
	memset(h,127,sizeof(h));
	if(!flag){
		for(int i=1;i<=m;i++){
			if(!sum[i])
				ans[1]++;
		}
		for(int i=1;i<=n;i++){
			work(2+ans[i]);
			putchar('\n');
		}
		return 0;
	}
	if(!flag){
		flag=3;
		las=1;
	}
	memset(vis,127,sizeof(vis));
	for(int i=1;i<=m;i++){
		if(!sum[i])
			ans[las]++;
		else if(!du[i])
			dfs(i,0,i);
	}
	for(int i=1;i<=n;i++){
		if(!tim[val[i]])
			dfs(val[i],0,val[i]);
		if(!tim[val1[i]])
			dfs(val1[i],0,val1[i]);
	}
	for(int i=1;i<=m;i++){
		if((flag==1&&vis[i]>las))
			vis[i]=las;
		if(sum[i])
			ans[vis[i]]++;
	}
	for(int i=1;i<=n;i++){
		work(ans[i]);
		putchar('\n');
	}
	return 0;
}
