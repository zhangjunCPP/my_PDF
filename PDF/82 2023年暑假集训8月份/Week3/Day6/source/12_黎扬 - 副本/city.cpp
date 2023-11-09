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
int n,k,cnt2,first[200005],cnt[200005],cnt1[200005],c[200005],vis[200005],ans=1e9;
struct q1{
	int u,w,nex;
}a[400005];
void add(int u1,int w1){
	a[++cnt2]={u1,w1,first[u1]};
	first[u1]=cnt2;
}
void dfs(int u,int dad,int col){
	if(c[u]==col){
		for(int i=1;i<=k;i++){
			cnt1[i]+=cnt[i];
		}
	}
	for(int i=first[u];i;i=a[i].nex){
		if(a[i].w==dad)
			continue;
		cnt[c[a[i].w]]++;
		dfs(a[i].w,u,col);
		cnt[c[a[i].w]]--;
	}
}
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	n=read();
	k=read();
	for(int i=1,x,y;i<n;i++){
		x=read();
		y=read();
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++){
		c[i]=read(); 
	}
	for(int i=1;i<=n;i++){
		if(vis[c[i]])
			continue;
		vis[c[i]]=1;
		dfs(i,0,c[i]);
		int flag=0;
		for(int j=1;j<=k;j++){
			if(j==c[i]){
				cnt1[j]=0;
				continue;
			}
			flag+=(bool)cnt1[j];
			cnt1[j]=0;
		}
		ans=min(ans,flag);
	}
	work(ans);
	return 0;
}
