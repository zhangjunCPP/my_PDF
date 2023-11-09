/*
前面20分很好拿。
三十分直接全排列模拟。 
拿到之后先去想后面的暴力。 
50分到手 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<iterator>
#include<stack>
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
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
}
const int N=1e6+100,inf=1e9+10;
int n,v[N],vis[N],a[N],ans,an[N];
stack<int>s;
void dfs(int k){
	if(k==n+1){
		while(s.size())s.pop();
		int res=0;
		For(i,1,n)
			while(1){
				if(s.empty()){s.push(a[i]);break;}
				if(a[i]<s.top()){
					res+=v[a[i]];
					s.pop();
				}
				else{
					s.push(a[i]);
					break;
				}
			}
		if(res>ans){
			ans=res;
			For(i,1,n)an[i]=a[i];
		}
		return;
	}
	For(i,1,n){
		if(!vis[i]){
			vis[i]=1;
			a[k]=i;
			dfs(k+1);
			vis[i]=0;
		}
	}
}
void chk(){
	int f1=1,f2=1;
	For(i,1,n){
		if(v[i]!=i)f1=0;
		if(v[i]!=n+1-i)f2=0;
	}
	if(f1){
		int res=0;
		For(i,1,n-1)res+=v[i];
		cout<<res<<endl;
		rFor(i,n,1)cout<<v[i]<<" ";
		return;
	}
	if(f2){
		cout<<(n-1)*n<<endl;
		For(i,2,n)cout<<i<<" ";
		cout<<1<<endl<<" ";
		return;
	}
	dfs(1);
	cout<<ans<<endl;
	For(i,1,n)cout<<an[i]<<" ";
}
signed main(){
	Freopen();
    Genshin_Impact_starts;
    cin.tie(0),cout.tie(0);
	cin>>n;
	For(i,1,n)cin>>v[i];
	chk();
}
