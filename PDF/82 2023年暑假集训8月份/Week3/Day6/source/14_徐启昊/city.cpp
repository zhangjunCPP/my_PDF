#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<iterator>
#include<vector>
#include<stack>
#include<map>
#define Genshin_Impact_starts ios::sync_with_stdio(false)
#define int long long
#define F first
#define S second
#define eps 1e-6
#define RE register
#define IN inline
#define For(i,s,t) for(register int i=s;i<=t;i++)
#define rFor(i,s,t) for(register int i=s;i>=t;i--)
#define eFor(i,u) for(register int i=head[u];i;i=nxt[i])
#define ls k<<1
#define rs k<<1|1
using namespace std;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
void swap(int &a,int &b){a=a^b,b=a^b,a=a^b;}
void Freopen(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
}
const int N=1e6+100,inf=1e9+10;
int n,k;
int c[N],vis[N];
vector<int>G[N],K[N];
map<pair<int,int>,int>key;
struct Tree{
    int fa[N],dep[N],siz[N],son[N];
    void dfs(int u,int fu){
        siz[u]=1,dep[u]=dep[fu]+1,fa[u]=fu;
        for(auto v:G[u]){
            if(v==fu)continue;
            dfs(v,u);
            siz[u]+=siz[v];
            if(siz[v]>siz[son[u]])son[u]=v;
        }
    }
    int top[N],dfn[N],seq[N],tot;
    void dfs2(int u,int topt){
        top[u]=topt,dfn[u]=++tot,seq[tot]=u;
        if(son[u])dfs2(son[u],topt);
        for(auto v:G[u]){
            if(v==son[u]||v==fa[u])continue;
            dfs2(v,v);
        }
    }
    int lca(int u,int v){
        int tu=top[u],tv=top[v];
        while(tu!=tv){
            if(dep[tu]<dep[tv]){
                swap(u,v);
                swap(tu,tv);
            }
            u=fa[tu];
            tu=top[u];
        }
        if(dep[u]>dep[v])swap(u,v);
        return u;
    }
    int sum[N],lazy[N],L[N],R[N];
    void pushup(int k){sum[k]=sum[ls]+sum[rs];}
    void pushdown(int k,int l,int r){
        if(!lazy[k])return;
        int mid=l+r>>1;
        lazy[ls]+=lazy[k];
        lazy[rs]+=lazy[k];
        sum[ls]+=lazy[k]*(mid-l+1);
        sum[rs]+=lazy[k]*(r-mid);
        lazy[k]=0;
    }
    void build(int k,int l,int r){
        L[k]=l,R[k]=r;
        lazy[k]=0,sum[k]=0;
        if(l==r)return;
        int mid=l+r>>1;
        build(ls,l,mid);
        build(rs,mid+1,r);
        pushup(k);
    }
    void update(int k,int x,int y,int c){
        int l=L[k],r=R[k];
        if(x<=l&&r<=y){
            sum[k]+=c*(r-l+1);
            lazy[k]+=c;
            return;
        }
        pushdown(k,l,r);
        int mid=l+r>>1;
        if(x<=mid)update(ls,x,y,c);
        if(y>mid)update(rs,x,y,c);
        pushup(k);
    }
    int ask(int k,int x){
        int l=L[k],r=R[k];
        if(l==r&&l==x)return sum[k];
        pushdown(k,l,r);
        int mid=l+r>>1,res=0;
        if(x<=mid)res+=ask(ls,x);
        else res+=ask(rs,x);
        return res;
    }
    void change(int u,int v){
        int tu=top[u],tv=top[v];
        while(tu!=tv){
            if(dep[tu]<dep[tv]){
                swap(u,v);
                swap(tu,tv);
            }
            update(1,dfn[tu],dfn[u],1);
            u=fa[tu];
            tu=top[u];
        }
        if(dep[u]>dep[v])swap(u,v);
        update(1,dfn[u],dfn[v],1);
    }
}T;
signed main(){
	Freopen();
    Genshin_Impact_starts;
    cin.tie(0),cout.tie(0);
	cin>>n>>k;
	For(i,1,n-1){
		int u,v;cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	For(i,1,n)cin>>c[i],K[c[i]].push_back(i);
	if(n<=2000){
		T.dfs(1,0);
		T.dfs2(1,1);
		int ans=inf,res,last;
		For(i,1,k){
			res=0,last=100;
			T.build(1,1,n);
			For(j,1,n)vis[j]=0;
			vector<int>O;
			key.clear();
			for(auto l:K[i])O.push_back(l);
			while(last!=res){
				last=res;
				for(auto l:O)
					for(auto r:O){
						if(key.count({l,r}))continue;
						key[{l,r}]=1;key[{r,l}]=1;
						vis[l]=vis[r]=1;
						T.change(l,r);
					}
				O.clear();
				For(j,1,n){
					if(vis[j])continue;
					if(T.ask(1,T.dfn[j])){
						res++;
						for(auto v:K[c[j]])vis[v]=1,O.push_back(v);
					}
				}
			}
			ans=min(ans,res);
		}
		cout<<ans;	
		return 0;	
	}
	else puts("0");
}
