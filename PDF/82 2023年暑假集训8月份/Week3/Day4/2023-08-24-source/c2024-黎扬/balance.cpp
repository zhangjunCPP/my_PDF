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
int n,cnt,first[300005],s[300005],sum[300005],mx,mx2,now,num,ans,f,f1;
struct q1{
	int u,w,nex;
}a[600005];
void add(int u1,int w1){
	a[++cnt]={u1,w1,first[u1]};
	first[u1]=cnt;
}
void dfs(int u,int dad,int id){
	s[u]=1;
	for(int i=first[u];i;i=a[i].nex){
		if(a[i].w==dad)
			continue;
		dfs(a[i].w,u,id);
		s[u]+=s[a[i].w];
		if(u==id){
			sum[s[a[i].w]]++;
			if(mx<s[a[i].w]){
				mx2=mx;
				mx=s[a[i].w];
			}
			else if(mx2<s[a[i].w])
				mx2=s[a[i].w];
		}
	}
}
void dfs1(int u,int dad,int id){
	for(int i=first[u];i;i=a[i].nex){
		if(a[i].w==dad)
			continue;
		dfs1(a[i].w,u,id);
	}
	int g=now;
	for(int i=first[u];i;i=a[i].nex){
		if(a[i].w==dad)
			continue;
		g=max(g,s[a[i].w]);
	}
	g=max(g,s[id]-s[u]);
	if(num>g){
		num=g;
		ans=u;
	}
}
int main(){
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	n=read();
	for(int i=1,x,y;i<n;i++){
		x=read();
		y=read();
		if(x!=1||y!=i+1)
			f=1;
		if(x!=i||y!=i+1)
			f1=1;
		add(x,y);
		add(y,x);
	}
	if(!f){
		work(2);
		putchar('\n');
		for(int i=2;i<=n;i++){
			work(1);
			putchar('\n');
		}
		return 0;
	}
	if(!f1){
		for(int i=1;i<=n;i++){
			if(i-1>n-i)
				work(i/2);
			else
				work((n+i+1)/2);
			putchar('\n'); 
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			s[j]=0;
			sum[j]=0;
		}
		mx=mx2=ans=0;
		num=1e9;
		dfs(i,0,i);
		for(int j=first[i];j;j=a[j].nex){
			if(s[a[j].w]!=mx)
				now=mx;
			else{
				if(sum[mx]>1)
					now=mx;
				else
					now=mx2;
			}
			dfs1(a[j].w,i,a[j].w);
		}
		work(ans);
		putchar('\n');
	}
	return 0;
}
