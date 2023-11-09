#include<bits/stdc++.h>
using namespace std;
const int N=1000000+10;
int T,n,m;
int sum[N];
struct node{
	int nt,to;
}a[N*2];
int head[N],at;
inline void add(int x,int y){
	a[++at].to=y,a[at].nt=head[x],head[x]=at;
}
bool v[N];

bool dfs(int now){
	int y,yy;
	for(int i=head[now];i;i=a[i].nt){
		y=a[i].to;
		for(int j=head[y];j;j=a[j].nt){
			yy=a[j].to;
			for(int k=head[yy];k;k=a[k].nt){
				if(a[k].to==now){
					return 1;
				}
			}
		}
		if(v[y]) continue;
		v[y]=1;
		dfs(now);
	}
	return 0;
}

bool check(){
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			if(dfs(i)) return 1;
		}
	}
	return 0;
}

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(head,0,sizeof(head));
		memset(sum,0,sizeof(sum));
		memset(v,0,sizeof(v));
		scanf("%d%d",&n,&m);
		if(m==0){
			cout<<0<<endl;
			continue;
		}
		bool f1=1,f2=1,f3=1;
		if(m!=n-1) f2=0;
		if(m!=n) f3=0;
		int x,y;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
			sum[x]++,sum[y]++;
			if(!(x==1&&y==i+1))f1=0;
			if(!(x==i&&y==i+1))f2=0;
			if(!(x==i&&y==((i%n)+1)))f3=0;
		}
		if(f1)cout<<m<<endl;
		else if(f2)cout<<2<<endl;
		else if(f3){
			if(n==1) cout<<0<<endl;
			else if(n==3) cout<<m<<endl;
			else cout<<2<<endl;
		}
		else{
			int ans=0;
			for(int i=1;i<=n;i++) ans=max(ans,sum[i]);
			if(ans==2){
				if(check()) ans=3;
			}
			cout<<ans<<endl; 
		}
	}
	return 0;
} 

