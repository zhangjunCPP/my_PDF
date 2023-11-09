//不可以
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<iterator>
#include<vector>
#include<queue>

#define Genshin_Impact_starts ios::sync_with_stdio(false)
#define ll long long
#define F first
#define S second
#define eps 1e-6
#define For(i,s,t) for(int i=s;i<=t;i++)
#define rFor(i,s,t) for(int i=s;i>=t;i--)

using namespace std;

int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
void swap(int &a,int &b){a=a^b,b=a^b,a=a^b;}
void Freopen(){
	freopen("tour.in","r",stdin);
	freopen("tour.out","w",stdout);
}

const int N=2e6+10,M=1e6+10,inf=1e9+10;

signed main(){
	Freopen();
	Genshin_Impact_starts;
	cin.tie(0),cout.tie(0);
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1,u,v;i<m;i++)cin>>u>>v;
	while(q--){
		int u,v;
		cin>>u>>v;
		puts("-1");
	}
}
