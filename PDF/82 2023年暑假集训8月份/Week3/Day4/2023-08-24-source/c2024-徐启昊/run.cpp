/*
真的没有什么思路，直接包搜
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<iterator>
#include<vector>
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
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
void swap(int &a,int &b){a=a^b,b=a^b,a=a^b;}
void Freopen(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
}
const int N=5000+100,inf=1e9+10,dt=2000;
int p,a,mx,mi=inf;
int vis[N][N];
int h[N];
vector<int>ans;
void dfs(int k,int x,int y,int fy){
	mx=max(mx,x),mi=min(mi,x);
	if(abs(x-0)+abs(y-0)>(p-k))return;
	if(k==p){
		if(x!=0||y!=0)return;
		int res=0;
		For(i,mi+dt,mx+dt)res+=h[i];
		if(res==a){
			for(auto v:ans)cout<<v;
			exit(0);
		}
		return;
	}
	if(vis[x+dt][y+dt])return;
	vis[x+dt][y+dt]=1;
	int tmp=h[x+dt];
	if(k>0){
		if(fy==1)h[x+dt]=h[x+dt]+1;
		if(fy==2)h[x+dt]=h[x+dt]-1;
		if(fy==3)h[x+dt]=h[x-1+dt];
		if(fy==4)h[x+dt]=h[x+1+dt];
	}
	if(fy==1){
		ans.push_back(1);
		dfs(k+1,x-1,y,4);
		ans.pop_back();
		ans.push_back(2);
		dfs(k+1,x,y+1,1);
		ans.pop_back();
		ans.push_back(3);
		dfs(k+1,x+1,y,3);
		ans.pop_back();	
	}
	else if(fy==2){
		ans.push_back(1);
		dfs(k+1,x+1,y,3);
		ans.pop_back();
		ans.push_back(2);
		dfs(k+1,x,y-1,2);
		ans.pop_back();
		ans.push_back(3);
		dfs(k+1,x-1,y,4);
		ans.pop_back();			
	}
	else if(fy==3){
		ans.push_back(1);
		dfs(k+1,x,y+1,1);
		ans.pop_back();
		ans.push_back(2);
		dfs(k+1,x+1,y,3);
		ans.pop_back();
		ans.push_back(3);
		dfs(k+1,x,y-1,2);
		ans.pop_back();			
	}
	else{
		ans.push_back(1);
		dfs(k+1,x,y-1,2);
		ans.pop_back();
		ans.push_back(2);
		dfs(k+1,x-1,y,4);
		ans.pop_back();
		ans.push_back(3);
		dfs(k+1,x,y+1,1);
		ans.pop_back();			
	}
	vis[x+dt][y+dt]=0;
	h[x+dt]=tmp;
}
//1up 2down 3right 4left
signed main(){
	Freopen();
    Genshin_Impact_starts;
    cin.tie(0),cout.tie(0);
	cin>>p>>a;
	dfs(0,0,0,1);
	cout<<"Impossible";
}
