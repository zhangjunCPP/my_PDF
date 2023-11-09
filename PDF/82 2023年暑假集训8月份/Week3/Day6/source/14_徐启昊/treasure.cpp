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
using namespace std;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
void swap(int &a,int &b){a=a^b,b=a^b,a=a^b;}
void Freopen(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
}
const int N=1e6+100,inf=1e9+10;
int n,ans=inf,len;
int a[N],tag[N],t[N],vis[N];
void dfs1(int k){
	if(k==n+1){
		int r1,r2,r3;
		r1=r2=r3=0;
		For(i,1,n)
			if(tag[i]==1)r1+=a[i];
			else if(tag[i]==2)r2+=a[i];
			else if(tag[i]==3)r3+=a[i];
		int mdiv=max(r1,max(r2,r3))-min(r1,min(r2,r3));
		if(ans>mdiv){
			ans=mdiv;
			For(i,1,n)t[i]=tag[i];
		}
		return;	
	}
	tag[k]=1;
	dfs1(k+1);
	tag[k]=2;
	dfs1(k+1);
	tag[k]=3;
	dfs1(k+1);
	tag[k]=0;
}
void dfs2(int k,int r1,int r2,int res,int last){
	if(r1>res||r2>res)return;
	if(r1==res&&r2==res){
		For(i,1,n)
			if(!tag[i])cout<<"3 ";
			else cout<<tag[i]<<" ";	
		exit(0);
	}
	if(k>n)return;
	For(i,last,n){
		tag[i]=1;
		dfs2(k+1,r1+a[i],r2,res,i+1);
		tag[i]=2;
		dfs2(k+1,r1,r2+a[i],res,i+1);
		tag[i]=0;
	}
}
void chk(){
	if(n<=15){
		dfs1(1);
		For(i,1,n)cout<<t[i]<<" ";
		return;
	}
	if(n<=25){
		int res=0;
		For(i,1,n)res+=a[i];
		res/=3;
		dfs2(1,0,0,res,1);
	}
}
signed main(){
	Freopen();
    Genshin_Impact_starts;
    cin.tie(0),cout.tie(0);
	cin>>n;
	For(i,1,n)cin>>a[i];
	chk();
}
