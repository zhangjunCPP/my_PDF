using namespace std;
#include<bits/stdc++.h>
#include<cstdio>
#include<string.h>
//#include<string>
//#include<iostream>
//#include<utility>
//#include<algorithm>
#define REG register
#define INL inline
#define MAX(x,y) (x<y?y:x)
#define MIN(x,y) (x<y?x:y)
#define ABS(x) (x<0?-x:x)
#define N 100005
#define int long long
#define INF 1145141919
#define EPS 0.00001
#define P 1000000007
template<typename T>INL T Max(REG T x,REG T y){return MAX(x,y);}
template<typename T>INL T Min(REG T x,REG T y){return MIN(x,y);}
template<typename T>INL T Abs(REG T x){return ABS(x);}
template<typename T>INL void Swap(REG T&x,REG T&y){x^=y^=x^=y;}
template<typename T>INL void Gcd(REG T x,REG T y){while(y^=x^=y^=x%=y);return x;}
template<typename T>
INL void read(REG T&x){
x=0;REG char c=getchar();/*REG T fl=1;*/
while(c<'0'||c>'9'){/*if(c == '-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}/*x*=fl;*/}
int n;
int fir[N],las[N<<1],t[N<<1],num;
INL void add(REG int u,REG int v){
t[++num]=v;las[num]=fir[u];fir[u]=num;
t[++num]=u;las[num]=fir[v];fir[v]=num;}
int f[N],siz[N],d[N],son[N],top[N];
void dfs(int u,int fa){
    f[u]=fa;
    siz[u]=1;
    for(int i=fir[u];i;i=las[i]){
        if(t[i] == fa)continue;
        d[t[i]]=d[u]+1;
        dfs(t[i],u);
        siz[u]+=siz[t[i]];
        if(siz[son[u]]<siz[t[i]])son[u] = t[i];
    }
}
void dfs2(int u,int fa,int tp){
    top[u]=tp;
    if(son[u]==0)return ;
    dfs2(son[u],u,tp);
    for(int i=fir[u];i;i=las[i]){
        if(t[i] == fa||t[i] == son[u])continue;
        dfs2(t[i],u,t[i]);
    }
}
int lca(int x,int y){
    while(top[x]!=top[y]){
        if(d[top[x]]>d[top[y]])x=f[top[x]];
        else y=f[top[y]];
    }
    if(d[x]<d[y])return x;
    else return y;
}
int Dis(int x,int y){
	return d[x]+d[y]-(d[lca(x,y)]<<1);
}
int dep[N];
int lf1[N],lf2[N];//最、次深的叶子 
int ans;
int a,b;
void xxrsb(int u){
	int mx=0;
	int mxx=0;
	lf1[u]=u;
	lf2[u]=u;
	for(int i=fir[u];i;i=las[i]){
		if(t[i] == f[u])continue;
		xxrsb(t[i]);
		if(mx<dep[t[i]]){
			lf2[u]=lf1[u]; 
			lf1[u]=lf1[t[i]];
			mxx=mx;
			mx=dep[t[i]];
		}else if(mxx<dep[t[i]]){
			mxx=dep[t[i]];
			lf2[u]=lf1[t[i]];
		}
	}
	dep[u]=mx+1;
	if(mx+mxx+1>ans){
		ans=mx+mxx+1;
		a=lf1[u];
		b=lf2[u];
	}
}
int qp(int a,int b){
	int num=1;
	while(b){
		if(b&1)
			num=num*a%P;
		a=a*a%P;
		b>>=1;
	}
	return num;
}
int du[N];//度数 
int xxr[N],rxx[N];//最远叶子/次远叶子 的距离 
int cnt[N];//次远叶子及以内的点数 
/* 
int vis[N];
int tot;
int rt;
struct idx{
	int id,dep,b;
	bool operator < (const idx& oth)const{
		return dep<oth.dep;
	}
}l[N];
void YLN(int u,int fa,int dep,int b){
	l[++tot]={u,dep,b};
	for(int i=fir[u];i;i=las[i]){
		if(t[i] == fa||vis[t[i]])continue;
		if(fa==rt)
			YLN(t[i],u,dep+1,t[i]);
		else YLN(t[i],u,dep+1,b);
	}
}
void solve(){
	sort(l+1,l+tot+1);
	for(int j=1;j<=tot;j++){
		for(int i=1;i<=tot;i++){
			if(l[i].b == l[j].b)continue;
			if(xxr[l[i].id]<l[i].dep+l[j].dep){
				rxx[l[i].id]=xxr[l[i].id];
				xxr[l[i].id]=l[i].dep+l[j].dep;
			}else if(rxx[l[i].id]<l[i].dep+l[j].dep){
				rxx[l[i].id]=l[i].dep+l[j].dep;
			}
		}
	}
}
int mx[N];
void findzx(int u,int fa,int sum){
	siz[u]=1;
	for(int i=fir[u];i;i=las[i]){
		if(t[i] == fa||vis[t[i]])continue;
		findzx(t[i],u,sum);
		mx[u]=Min(mx[u],siz[t[i]]);
		siz[u]+=siz[t[i]];
	}
	mx[u]=Max(mx[u],sum-siz[u]);
	if(rt>mx[u])rt=u;
}
void dfz(int u){
	vis[u]=1;
	YLN(u,0,0,0);
	solve();
	for(int i=fir[u];i;i=las[i]){
		if(vis[t[i]])continue;
		findzx(t[i],u,siz[t[i]]);
		dfz(rt);
	}
}
*/
int lf[N];
int ln;
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	read(n);
	int mxd=0;
	for(int i=1;i<n;i++){
		int x,y;
		read(x);
		read(y);
		add(x,y);
		du[x]++;
		du[y]++;
		mxd=Max(mxd,Max(du[x],du[y]));
	}
	dfs(1,0);
	dfs2(1,0,1);
	xxrsb(1);
	ans--;
	if(mxd<=2){
//		printf("%lld",((qp(2,n)-1-n)%P+P)%P);
		int sum=0;
//		for(int i=1;i<n;i++){
//			sum+=(n-i)*qp(2,i-1)%P*i%P;
//			sum%=P;
//		}
		for(int i=1;i<=n;i++){
			if(i-1>=n-i-1) 
				sum+=(i-1)*qp(2,Max(i-Max(n-i+1,2ll),0ll))%P;
			else
				sum+=n-i-1;
//			sum+=Max(i-1,n-i-1)*qp(2,Max(i-2,0ll))%P;
			sum%=P; 
		}
	//	for(int i=1;i<=n;i++){
	//		for(int j=i+1;j<=n;j++){
	//			sum+=qp(2,j-i-1)*(j-i);
	//			cout<<i<<","<<j<<"::"<<qp(2,j-i-1)*(j-i)<<endl;
	//		}
	//	}
		printf("%lld",(sum<<1)%P);
		return 0;
	}
	//--------------------------
	for(int i=1;i<=n;i++){
		if(i == a||i == b)continue;
		if(Dis(i,a)==ans||Dis(i,b) == ans){
			printf("%lld",ans*qp(2,n)%P); 
			return 0;
		}
	}
//	mx[0]=INF;
//	findzx(1,1,n);
//	dfz(rt);
	for(int i=1;i<=n;i++){
		if(du[i]<=1)lf[++ln]=i;
	}
	for(int j=1;j<=ln;j++){
		int x=Dis(a,lf[j]);
		if(xxr[a]<x){
			rxx[a]=xxr[a];
			xxr[a]=x;
		}else if(rxx[a]<x)rxx[a]=x;
		x=Dis(b,lf[j]);
		if(xxr[b]<x){
			rxx[b]=xxr[b];
			xxr[b]=x;
		}else if(rxx[b]<x)rxx[b]=x;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<i;j++){
//			int x=Dis(i,j);
//			if(x<=rxx[i])cnt[i]++;
//			if(x<=rxx[j])cnt[j]++;
//		}
//	}
	int sum=0;
	for(int i=rxx[a]+1;i<=xxr[a];i++){
		if(n-(xxr[a]-i+1)>=xxr[a]-i-1)
		sum+=i*qp(2,Max(n-(xxr[a]-i)-i-Max(n-i+1,2ll),0ll));
		else sum+=xxr[a]-i-1;
//		sum+=Max(i,xxr[a]-i-1);/*
//		sum+=Max(i-1,n-i-1)*qp(2,Max(i-2,0ll))%P;*/
		sum%=P;
	}
	sum+=qp(2,n-xxr[a]+rxx[a]);
	sum%=P;
	
	for(int i=rxx[b]+1;i<=xxr[b];i++){
		if(n-(xxr[b]-i+1)>=xxr[b]-i-1)
		sum+=i*qp(2,Max(n-(xxr[b]-i)-i-Max(n-i+1,2ll),0ll));
		else sum+=xxr[b]-i-1;
//		sum+=Max(i,xxr[a]-i-1);/*
//		sum+=Max(i-1,n-i-1)*qp(2,Max(i-2,0ll))%P;*/
		sum%=P;
	}
	sum+=qp(2,n-xxr[b]+rxx[b]); 
	sum%=P;
//	for(int i=1;i<=n;i++){
//		for(int j=rxx[i]+1;j<=xxr[i];j++){
//			sum+=qp(2,n-(xxr[i]-j))*j%P;
//			sum%=P;
//		}
//		sum+=qp(2,n-(xxr[i]-rxx[i]))%P;
//		sum%=P;
////		sum=qp(2,xxr[i])-1-(qp(2,rxx[i])-1)+(n-xxr[i]+rxx[i])*qp(1,n-xxr[i]+rxx[i]);
//	}
	printf("%lld",(sum<<1)%P);
    return 0;
}
/*

		for(int i=1;i<=n;i++){
			if(i-1>=n-i-1) 
				sum+=(i-1)*qp(2,Max(i-Max(n-i-1,2ll),0ll))%P;
			else
				sum+=n-i-1;
//			sum+=Max(i-1,n-i-1)*qp(2,Max(i-2,0ll))%P;
			sum%=P; 
		}
		
	//	for(int i=1;i<=n;i++){
	//		for(int j=i+1;j<=n;j++){
	//			sum+=qp(2,j-i-1)*(j-i);
	//			cout<<i<<","<<j<<"::"<<qp(2,j-i-1)*(j-i)<<endl;
	//		}
	//	}




//	for(int i=1;i<=n;i++){
//		sum+=qp(2,n-i)-1;
//		cout<<n-i<<endl;
//		for(int j=i+1;j<=n;j++){
//			sum+=qp(2,j-i-1);
//		}
//	}
	if(mxd<=2){
		printf("%lld",((qp(2,n)-1-n)%P+P)%P);
		return 0;
	}
*/
/*
6
1 2
2 3
3 4
4 5
3 6
*/
/*
1 2
1 3
2 6
2 4
2 5
*/

//sbsbsbsbssbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsb
//sbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsb
