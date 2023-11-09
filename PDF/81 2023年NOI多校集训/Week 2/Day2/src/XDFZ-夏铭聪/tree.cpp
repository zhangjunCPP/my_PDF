#include<stdio.h>
#include<algorithm>

#define int long long
template<typename dy> dy max(dy x,dy y){return x>y?x:y;}
template<typename dy> dy min(dy x,dy y){return x<y?x:y;}
const int N=1e6+5,mod=1e9+7;
struct dy{
    int v,next;
}edge[N<<1];
int head[N],cnt=1;
void add(int u,int v){
    edge[cnt].v=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
int n,f[N][35],deep[N];
void dfs(int u,int dad){
	deep[u]=deep[dad]+1;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].v;
		if(v!=dad)
		{
			f[v][0]=u;
			for(int i=1;i<=20;i++) f[v][i]=f[f[v][i-1]][i-1];
			dfs(v,u);
		}
	}
	return ;
}
int dis(int x,int y){
	int tmp=deep[x]+deep[y];
	if(deep[x]<deep[y]) std::swap(x,y);
	for(int i=20;i>=0;i--) if(deep[f[x][i]]>=deep[y]) x=f[x][i];
	if(x==y) return tmp-deep[x]*2;
	for(int i=20;i>=0;i--) if(f[x][i]!=f[y][i]) {x=f[x][i];y=f[y][i];}
	return tmp-deep[f[x][0]]*2;
}
int s1[N],s2[N],ci1,ci2,ans,c[N];
void get_(int i){
	if(i>n)
	{
		// for(int i=0;i<ci1;i++) printf("%d ",s1[i]);  printf("\n");
		// for(int i=0;i<ci2;i++) printf("%d ",s2[i]);  printf("\n");
		
		int sum1=0,sum2=0,l1=0,r1=0,l2=0,r2=0;
		for(int i=0;i<ci1;i++) for(int j=i+1;j<ci1;j++)
		{
			int t=dis(s1[i],s1[j]);
			if(sum1<t)
			{
				sum1=t;
				l1=s1[i];r1=s1[j];
			}
		}
		for(int i=0;i<ci2;i++) for(int j=i+1;j<ci2;j++)
		{
			int t=dis(s2[i],s2[j]);
			if(sum2<t)
			{
				sum2=t;
				l2=s2[i];r2=s2[j];
			}
		}
		// printf("%lld %lld %lld %lld %lld\n",l1,r1,l2,r2,max(sum1,sum2));
		// c[max(sum1,sum2)]++;
		
		(ans+=max(sum1,sum2)%mod)%=mod;
		// printf("%d\n",max(sum1,sum2));
		// printf("-----------\n");
		return;
	}
	s1[ci1++]=i;
	get_(i+1);
	ci1--;
	
	s2[ci2++]=i;
	get_(i+1);
	ci2--;
}
int zj,S,du[N];
void get_zj(int u,int dad){
	deep[u]=deep[dad]+1;
	if(deep[u]>zj){zj=deep[u];S=u;}
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].v;
		if(v!=dad) get_zj(v,u);
	}
}
int ksm(int x,int y){
	int s=1;
	while(y)
	{
		if(y&1) (s*=x%mod)%=mod;
		(x*=x%mod)%=mod;y>>=1;
	}
	return s;
}
bool ch=1;
bool check(){
	int t=0;
	for(int i=2;i<=n;i++) if(du[i]==1) {t=deep[i];break;}
	for(int i=2;i<=n;i++) if(du[i]>2||(du[i]==1&&deep[i]!=t)) return 0;
	return 1;
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%lld%lld",&u,&v);
		add(u,v);add(v,u);if(u!=i||v!=i+1) ch=0;
		du[u]++;du[v]++;
	}
	dfs(1,0);
	// printf("%lld\n",dis(5,6));
	// return 0;
	if(ch)
	{
		get_zj(1,0);zj=0;int l=S;
		get_zj(S,0);int r=S;zj--;
		ans=zj%mod*ksm(2,n-1)%mod;
		if(n&1)
		{
			int t=(n-1)>>1,num[N]={0,4,12};
			for(int i=3;i<=t;i++) {num[i]=num[i-1]*4%mod;}
			for(int i=t;i>=1;i--) (ans+=num[i]*((zj-t+i-1)%mod)%mod)%=mod;
			printf("%d\n",ans);
		}
		else
		{
			int t=(n+1)>>1,num[N]={0,2,6};
			for(int i=3;i<=t;i++) {num[i]=num[i-1]*4%mod;}
			for(int i=t;i>=1;i--) (ans+=num[i]*((zj-t+i-1)%mod)%mod)%=mod;
			printf("%d\n",ans);
		}
	}
	else if(du[1]==n-1) printf("%d\n",ksm(2,n+1)%mod);
	else if(du[1]>2&&check())
	{
		get_zj(1,0);zj=0;int l=S;
		get_zj(S,0);int r=S;zj--;
		printf("%d\n",zj*ksm(2,n)%mod);
	}
	else
	{
		get_(1);
		printf("%lld\n",ans);
	}
	// get_zj(1,0);zj=0;int l=S;
	// get_zj(S,0);int r=S;zj--;
	// printf("%d\n",zj);
	// for(int i=zj;i>=0;i--) printf("%lld ",c[i]);
	// printf("%d",zj%mod*ksm(2,n)%mod);
    return 0;
}