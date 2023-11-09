#include<bits/stdc++.h>
clock_t cl=clock();
#define ll long long
#define mem(u,v) memset(u,v,sizeof(u))
#define rep(i,a,b) for(int i=(a),KK##i=(b);i<=KK##i;i++)
#define drep(i,a,b) for(int i=(a),KK##i=(b);i>=KK##i;i--)
#define go(u) for(int i=head[u],v=e[i].to;i;i=e[i].nxt,v=e[i].to)
#define writesp(x) write(x),putchar(' ')
#define writeln(x) write(x),puts("")
#define Il inline
using namespace std;
Il ll read(){ll sum=0,f=0;char ch=getchar();while(!isdigit(ch))f|=(ch=='-'),ch=getchar();while(isdigit(ch))sum=(sum<<1)+(sum<<3)+(ch^48),ch=getchar();return f?-sum:sum;}
void write(const ll x){if(x<0){putchar('-');write(-x);return;}if(x>9)write(x/10);putchar(x%10+'0');}
#define N 1100000
ll ans,m2[N];
int n,x,y,a[N],b[N],dep[N],ps,ps2,mx,f[N][22],tot,head[N],s[N],s1[N],s2[N],kkk,k1,k2,A[N],B[N],GS[N];bool vis[N];
const ll mod=1e9+7;
struct node{int to,nxt;}e[N*2];
void add(int f,int to){e[++tot].to=to;e[tot].nxt=head[f];head[f]=tot;}
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;f[u][0]=fa;
	go(u)if(v!=fa)dfs(v,u);
}
void dfs2(int u,int fa){
	dep[u]=dep[fa]+1;f[u][0]=fa;
	rep(i,1,20)f[u][i]=f[f[u][i-1]][i-1];
	go(u)if(v!=fa)dfs2(v,u);
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	drep(i,20,0)if(dep[f[x][i]]>=dep[y])x=f[x][i];
	if(x==y)return x;
	drep(i,20,0)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
int gt(int x,int y){
	drep(i,20,0)if(dep[f[x][i]]>dep[y])x=f[x][i];
	return x;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read();rep(i,2,n)x=read(),y=read(),add(x,y),add(y,x);
	m2[0]=1;rep(i,1,n)m2[i]=m2[i-1]*2%mod;
//	cout<<clock()-cl<<endl;
	dfs(1,0);
	mx=ps=0;rep(i,1,n)if(dep[i]>mx)mx=dep[i],ps=i;
	dfs(ps,0);mx=ps2=0;
	rep(i,1,n)if(dep[i]>mx)mx=dep[i],ps2=i;
//	cout<<clock()-cl<<endl;
	mx--;
	if(mx%2==0){
		int tt=ps2;
		rep(_,1,mx/2)tt=f[tt][0];
		dfs2(tt,0);
	}
	else dfs2(1,0);
//	cout<<clock()-cl<<endl;
//	return 0;
	rep(i,1,n)a[i]=dis(ps,i),b[i]=dis(ps2,i);
	rep(i,1,n)if(a[i]<b[i])B[b[i]]++;
	rep(i,1,n)if(a[i]>b[i])A[a[i]]++;
	rep(i,1,n)GS[max(a[i],b[i])]++;
	rep(i,1,n)GS[i]+=GS[i-1];
	int tt=0;
	rep(i,1,n)tt=max(tt,min(a[i],b[i]));
//	rep(i,1,n)cout<<a[i]<<" "<<b[i]<<endl;
	bool flag=0;
	rep(i,1,n)if(a[i]==tt&&b[i]>=tt)flag=1;
	rep(i,1,n)if(a[i]>=tt&&b[i]==tt)flag=1;
	rep(i,tt,mx-1){
//		cout<<"DE"<<i<<endl;
		int s=GS[i];
		if(i==tt&&!flag)continue;
		if(i==tt){
			ans=(ans+i*m2[s]%mod)%mod;
//			cout<<ans<<endl;
			continue;
		}
		if(!(A[i]+B[i]))continue;
		ans=(ans+m2[s-A[i]-B[i]]*(m2[A[i]+B[i]]-1)%mod*i%mod)%mod;
//		cout<<ans<<endl;
	}
	rep(i,1,n)if(a[i]==mx||b[i]==mx)s[++kkk]=i;
	s1[++k1]=s[1];
	rep(i,2,kkk)if(dis(s[1],s[i])==mx)s2[++k2]=s[i];else s1[++k1]=s[i];
//	cout<<k1<<' '<<k2<<endl;
	int cnt=0;
	rep(i,1,kkk){
		int t=gt(s[i],tt);
//		cout<<"DE"<<s[i]<<" "<<t<<endl;
		if(!vis[t])cnt++,vis[t]=1;
	}
	if(mx%2==0&&cnt>2){
		assert(!ans);
		ans=1ll*mx*m2[n-1];
//		puts("FDLKFDK");
	}
	else{
		ans=(ans+(m2[n-1]-m2[n-k1-k2]+mod)%mod*mx%mod)%mod;
	}
	writeln(ans*2%mod);
}
/*
3
1 2
1 3

4
1 2
1 3
1 4

5
1 2
1 3
3 4
3 5

4
1 2
2 3
3 4

15
1 2
1 3
3 4
4 5
5 6
3 7
3 8
7 9
5 10
9 11
8 12
8 13
1 14
12 15

6
1 2
1 3
1 4
2 5
2 6

7
1 2
2 3
1 4
1 5
3 6
3 7
*/
