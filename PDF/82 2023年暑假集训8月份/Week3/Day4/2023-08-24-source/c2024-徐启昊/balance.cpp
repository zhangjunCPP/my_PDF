/*
三秒，1e9，能过！
两个性质：一个菊花，一个链。
菊花就输出1，链的话就讨论一下。 
40分到手。 
*/
#include<bits/stdc++.h>
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
using namespace std;
void Freopen(){
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
}
const int N=1e6+100,inf=1e9+10;
int n;
vector<int>G[N];
int u[N],v[N],fa[N],vis[N];
void dfs(int u,int fu){
	fa[u]=fu;
	for(auto v:G[u]){
		if(v==fu)continue;
		dfs(v,u);
	}
}
int cnt;
void Dfs(int u,const int &x,const int &y){
	if(u==x||u==y)return;
	vis[u]=1;
	cnt++;
	for(auto v:G[u]){
		if(v==fa[u])continue;
		Dfs(v,x,y);
	}
}
void chk(){
	int fl=1;
	For(i,1,n-1)if(u[i]!=i||v[i]!=i+1)fl=0;
	if(fl){
		For(i,1,n){
			int q=i-1,h=n-i;
			if(q<h){
				if(h%2==0)cout<<i+h/2<<endl;
				else cout<<i+h/2+1<<endl;
			}
			else if(q>h){
				if(q%2==0)cout<<i-q/2<<endl;
				else cout<<i-q/2-1<<endl;				
			}
			else{
				if(h%2==0)cout<<i+h/2<<endl;
				else cout<<i+h/2+1<<endl;
			}
		}
		return; 
	}
	if(G[1].size()==n-1){
		cout<<2<<endl;
		For(i,2,n)cout<<1<<endl;
		return;
	}
	For(i,1,n){
		int res=inf,id=0;	
		For(j,1,n){
			For(k,1,n)vis[k]=0;
			if(i==j)continue;
			int s=0;
			For(k,1,n)if(!vis[k]){
				cnt=0;
				Dfs(k,i,j);
				s=max(s,cnt);
			}
			if(res>s)res=s,id=j;
		}
		cout<<id<<endl;
	}
}
signed main(){
	Freopen();
    Genshin_Impact_starts;
    cin.tie(0),cout.tie(0);
	cin>>n;
	For(i,1,n-1)cin>>u[i]>>v[i],G[u[i]].push_back(v[i]),
		G[v[i]].push_back(u[i]);
	dfs(1,0);
	chk();
}
