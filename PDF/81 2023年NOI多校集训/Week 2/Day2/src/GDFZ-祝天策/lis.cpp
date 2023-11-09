#include<bits/stdc++.h>
#define ll long long
#define mem(u,v) memset(u,v,sizeof(u))
#define rep(i,a,b) for(ll i=(a),KK##i=(b);i<=KK##i;i++)
#define drep(i,a,b) for(ll i=(a),KK##i=(b);i>=KK##i;i--)
#define go(u) for(ll i=head[u],v=e[i].to;i;i=e[i].nxt,v=e[i].to)
#define writesp(x) write(x),putchar(' ')
#define writeln(x) write(x),puts("")
#define Il inline
using namespace std;
Il ll read(){ll sum=0,f=0;char ch=getchar();while(!isdigit(ch))f|=(ch=='-'),ch=getchar();while(isdigit(ch))sum=(sum<<1)+(sum<<3)+(ch^48),ch=getchar();return f?-sum:sum;}
void write(const ll x){if(x<0){putchar('-');write(-x);return;}if(x>9)write(x/10);putchar(x%10+'0');}
#define N 110000
ll n,x,y,tot,head[N],lsh[N],a[N],f[N],top,ans,ANS=1e18,sz,cnt;bool vis[N];
struct node{ll to,nxt;}e[N*2];
void add(ll f,ll to){e[++tot].to=to;e[tot].nxt=head[f];head[f]=tot;}
void dfs(ll u,ll fa){
	cnt++;
	bool flag=0,flag2=0;ll tmp1=0,tmp2=0;
	if(a[u]>f[top])f[++top]=a[u],flag=1;
	else{
		ll pos=lower_bound(f+1,f+top+1,a[u])-f;
		if(f[pos]>a[u])tmp1=pos,tmp2=f[pos],f[pos]=a[u],flag2=1;
	}
	ans=max(ans,top);
	go(u)if(v!=fa&&!vis[v])dfs(v,u);
	if(flag)top--;
	else if(flag2)f[tmp1]=tmp2;
}
void work(ll x){
	ans=0;
	vis[x]=1;
	rep(i,1,n)if(i!=x)dfs(i,0),assert(!top);
//	cout<<"WORK"<<x<<' '<<ans<<endl;
	vis[x]=0;
	ANS=min(ANS,ans);
}
int main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	n=read();rep(i,2,n)x=read(),y=read(),add(x,y),add(y,x);
	rep(i,1,n)a[i]=read(),lsh[i]=a[i];
	sort(lsh+1,lsh+n+1);sz=unique(lsh+1,lsh+n+1)-lsh-1;
	rep(i,1,n)a[i]=lower_bound(lsh+1,lsh+sz+1,a[i])-a;
	rep(i,1,n)work(i);
	writeln(ANS);
}
/*
5
1 2
2 3
3 4
4 5
1 2 3 4 5
*/
