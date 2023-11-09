#include<bits/stdc++.h>
using namespace std;
namespace IO_ER{
	#define LL long long
	#define db double
	#define In inline
	#define ULL unsigned LL
	#define Re register
	#define f(a,b,i) for(Re int i=a;i<=b;i++)
	#define ff(a,b,i) for(Re int i=a;i<b;i++)
	#define f_(a,b,i) for(Re int i=a;i>=b;i--)
	#define ff_(a,b,i) for(Re int i=a;i>b;i--)
	const int inf=0x3f3f3f3f;
	const int INF=0x7f7f7f7f;
	const LL infll=0x3f3f3f3f3f3f3f3fll;
	const LL INFll=0x7f7f7f7f7f7f7f7fll;
	template<typename T>void read(T &x){
		static bool fl;
		static char ch;
		x=0;
		fl=0;
		ch=getchar();
		while(ch<'0'||ch>'9'){
			if(ch=='-')fl=1;
			ch=getchar();
		}
		while('0'<=ch&&ch<='9'){
			x=x*10+(ch^48);
			ch=getchar();
		}
		if(ch=='.'){
			ch=getchar();
			static db d;
			d=1.0;
			while('0'<=ch&&ch<='9'){
				x+=d*(ch^48);
				d*=0.1;
				ch=getchar();
			}
		}
		x=fl?-x:x;
	}
	template<typename T,typename ...Args>void read(T &x,Args &...args){
		read(x);
		read(args...);
	}
}
using namespace IO_ER;

#define N 1000050

int n,m;

vector<int>e[N];

int du[N];

typedef pair<int,int> Pi;

unordered_map<LL,int>vis;

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
//	freopen("D:\\down\\match\\match2.in","r",stdin);
	int Ti;
	read(Ti);
	while(Ti--){
		read(n,m);
		f(1,n,i){
			e[i].clear();
			du[i]=0;	
		}
		vis.clear();
		int u,v;
		f(1,m,i){
			read(u,v);
			e[u].emplace_back(v);
			e[v].emplace_back(u);
			if(u>v)swap(u,v);
			vis[1ll*u*inf+v]=1;
			du[u]++;
			du[v]++;
		}
		int ans=0;
		f(1,n,i)ans=max(ans,du[i]);
		if(ans!=2){
			printf("%d\n",ans);
			continue;
		}
		f(1,n,i){
			if(du[i]!=2)continue;
			int x=e[i][0],y=e[i][1];
			if(x>y)swap(x,y);
			if(vis[1ll*x*inf+y]){
				printf("%d\n",3);
				goto A;
			}
		}
		puts("2"); 
		A:;
	}
	
	return 0;
}
/*
16
7 3
7 5
5 1
1 7
1 0
1 0
3 3
1 2
2 3
3 1
10 5
3 7
9 5
6 1
6 8
1 7
6 1
6 3
1 0
21 9
21 16
14 20
14 6
4 17
17 5
4 9
18 3
15 8
12 15
1 0
8 0
3 0
1 0
6 1
3 2
1 0
19 1
19 17
13 8
11 13
6 5
6 10
4 11
2 6
11 2
10 7
2 9
1 0
*/

