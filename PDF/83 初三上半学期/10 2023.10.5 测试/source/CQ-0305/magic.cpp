//the code is from chenjh
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
struct Ball{
	int l,r,c;
	Ball(int _l=0,int _r=0,int _c=0):l(_l),r(_r),c(_c){}
}a[1005];
LL d[1005],e[1005],f[1005];//d 可得到，e 可释放，f 当前魔法量。
bool vis[1005];//是否为稳定态。 
int p[1005];
void solve1(){
	for(int i=1;i<=n;i++) p[i]=i;
	LL ans=0;
	do{
		memset(vis,0,sizeof(bool)*(n+1));
		LL w=0;
		for(int i=1;i<=n;i++){
			vis[p[i]]=1;
			for(int j=a[p[i]].l;j<=a[p[i]].r;j++)if(!vis[j]) w+=a[p[i]].c;
		}
		if(w>ans) ans=w;
	}while(next_permutation(p+1,p+n+1));
	printf("%lld\n",ans);
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].c);
		for(int j=a[i].l;j<=a[i].r;j++)if(i!=j)d[j]+=a[i].c;
		e[i]=(LL)a[i].c*(a[i].r-a[i].l);
	}
	if(n<=10){solve1();return 0;}
	for(int _=n;_--;){
//		for(int i=1;i<=n;i++) fprintf(stderr,"%lld ",d[i]);
//		fprintf(stderr,"\n");
//		for(int i=1;i<=n;i++) fprintf(stderr,"%lld ",e[i]);
//		fprintf(stderr,"\n");
//		for(int i=1;i<=n;i++) fprintf(stderr,"%lld ",f[i]);
//		fprintf(stderr,"\n\n");
		int i=0;
		for(int j=1;j<=n;j++)
			if(!vis[j] && (!i||(__int128)e[j]*(e[i]+d[i])>(__int128)e[i]*(e[j]+d[j])))i=j;
		vis[i]=1;
		for(int j=a[i].l;j<=a[i].r;j++)if(!vis[j])d[j]-=a[i].c,f[j]+=a[i].c;
		for(int j=1;j<=n;j++)if(!vis[j] && a[j].l<=i && i<=a[j].r) e[j]-=a[j].c;
		e[i]=d[i]=0;
		fprintf(stderr,"%d\n",i);
	}
	LL ans=0;
	for(int i=1;i<=n;i++) ans+=f[i];
	printf("%lld\n",ans); 
	return 0;
}

