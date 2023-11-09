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
#define N 1100000
#define pii pair<ll,ll>
#define MP make_pair
#define fi first
#define se second
ll n,m,M,nn,B,tot=1,head[N],del[N],ANS=-8e18,KK,fa[N],in[N],IN[N],x,y,nd[N],cut[N],ed[N],tmp[N];bool vis[N];
queue<ll>q;
vector<pii>vec[N];
struct node{ll to,nxt;}e[N*2];
void add(ll f,ll to){e[++tot].to=to;e[tot].nxt=head[f];head[f]=tot;}
ll getf(ll x){return fa[x]==x?x:fa[x]=getf(fa[x]);}
//void merge(ll x,ll y){x=getf(x),y=getf(y);if(x!=y)fa[x]=y;}
int main(){
	freopen("subtree.in","r",stdin);
	freopen("subtree.out","w",stdout);
	n=read();m=read();M=read(),nn=read(),B=read();
//	puts("FDKJFD");
	rep(i,1,m)x=read(),y=read(),add(x,y),add(y,x),IN[x]++,IN[y]++;
	rep(i,1,n+1)in[i]=IN[i],fa[i]=i;
	rep(k,1,n){
		rep(i,1,n)if(!vis[i]&&in[i]<=k)q.push(i),vis[i]=1,fa[i]=getf(i+1);
		while(!q.empty()){
			ll u=q.front();q.pop();
			go(u){
				if(!del[i])in[v]--,del[i]=del[i^1]=1,vec[k].push_back(MP(u,v));
				if(!vis[v]&&in[v]<=k)q.push(v),vis[v]=1;
			}
		}
	}
//	rep(k,1,n){
//		for(ll i=1;i<=n;i=getf(i+1)){
//			if(!vis[i]&&in[i]<=k)q.push(i),vis[i]=1,fa[i]=getf(i+1);
//		}
//		while(!q.empty()){
//			ll u=q.front();q.pop();
//			go(u){
//				if(!del[i])in[v]--,del[i]=del[i^1]=1,vec[k].push_back(MP(u,v));
//				if(!vis[v]&&in[v]<=k)q.push(v),vis[v]=1;
//			}
//		}
//	}
//	puts("FDLKJFD");
	rep(i,1,n)fa[i]=i,nd[i]=1,in[i]=0,cut[i]=IN[i],vis[i]=0;
	drep(k,n,1){
		ll kkk=0;
		for(ll j=0;j<(ll)vec[k].size();j++){
			x=vec[k][j].fi,y=vec[k][j].se;
//			cout<<"ADD"<<x<<" "<<y<<endl;
			in[x]++,in[y]++;
			ll xx=x,yy=y;
			x=getf(x),y=getf(y);
			if(x!=y){
				fa[x]=y;
				nd[y]+=nd[x];
				ed[y]+=ed[x];
				cut[y]+=cut[x];
				ed[y]++;
				cut[y]-=2;
			}
			else{
				ed[x]++;
				cut[y]-=2;
			}
			if(getf(xx)==xx)tmp[++kkk]=xx;
			if(getf(yy)==yy)tmp[++kkk]=yy;
//			rep(i,1,n)cout<<cut[getf(i)]<<' ';puts("");
		}
		rep(i,1,kkk)if(!vis[tmp[i]]){
			vis[tmp[i]]=1;
			if(getf(tmp[i])==tmp[i]){
				x=tmp[i];
				ll ans=M*ed[x]-nn*nd[x]+B*cut[x];
//				cout<<"DE"<<k<<' '<<x<<" "<<ed[x]<<" "<<nd[x]<<' '<<cut[x]<<' '<<ans<<endl;
				if(ans>ANS)ANS=ans,KK=k;
			}
		}
		rep(i,1,kkk)vis[tmp[i]]=0;
	}
	writesp(KK),writeln(ANS);
}
/*
12 10
-1336000 -6611820 654847323
8 11
6 12
5 7
9 3
9 5
3 2
9 7
4 2
7 8
7 2
*/
