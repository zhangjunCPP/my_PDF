#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=998244353;
typedef long long ll;
struct Edge{int v,id;bool operator <(const Edge x)const{return id<x.id;}};
int n;
ll dp[1000005][3],g[3],sum[1000005]; 
/*
0表示u没有被染色且最快的边染色了  
1表示u被染色了，且染色u的这一条边比(u,fa)快，
2表示u被染色了，且染色u的这一条边比(u,fa)慢， 
*/ 
vector<Edge> G[1000005];
int init(int u,int t){
	sort(G[u].begin(),G[u].end());
	for(int i=0;i<(int)G[u].size();i++)if(G[u][i].id==t)return i;
	return G[u].size();
}
void add(ll &x,ll y){x=(x+y)%p;}
void dfs(int u,int t){	
	dp[u][0]=1;
	int pos=init(u,t);
	ll f=1;sum[u]=1;
	for(int i=0;i<pos;i++){//这些都是比t快的边 
		int v=G[u][i].v;
		dfs(v,G[u][i].id);
		f=f*dp[v][0]%p;
		sum[u]=(dp[v][0]+dp[v][1]+dp[v][2])%p*sum[u]%p;
		
		add(g[0],(dp[v][0]+dp[v][1])%p*dp[u][0]%p);//u必须不染，这条边不染，那么dp[v][1],这条边染，下面的边不被他限制，那么dp[v][0] 
		
		if((*G[v].begin()).id==G[u][i].id)add(g[0],sum[v]);//u不染，这条边染，下面的被这条边限制 
		
		add(g[1],(dp[v][0]+dp[v][1]+dp[v][2])%p*dp[u][1]%p);//u染了，这条边肯定不染，那么dp[v][0/1/2] 
		
		add(g[1],(dp[v][0]+dp[v][2])%p*dp[u][0]%p);//u没染，这条边必须染u，那么dp[v][0/2] 
		
		for(int i=0;i<3;i++)dp[u][i]=g[i],g[i]=0;
	}
	for(int i=pos+1;i<(int)G[u].size();i++){
		int v=G[u][i].v;
		dfs(v,G[u][i].id);
		f=f*dp[v][0]%p;
		sum[u]=(dp[v][0]+dp[v][1]+dp[v][2])%p*sum[u]%p;
		add(g[0],(dp[v][0]+dp[v][1])%p*dp[u][0]%p);//u不染，这条边不染，那么dp[v][1] ,这条边染，下面的边不被他限制，那么dp[v][0]
		if((*G[v].begin()).id==G[u][i].id)add(g[0],sum[v]);//u不染，这条边染，下面的被这条边限制 
		add(g[1],(dp[v][0]+dp[v][1]+dp[v][2])%p*dp[u][1]%p);//u必须染了，这条边肯定不染，那么dp[v][0/1/2] 
		add(g[2],(dp[v][0]+dp[v][1]+dp[v][2])%p*dp[u][2]%p);//u染，这条边肯定不染，那么dp[v][0/1/2]
		add(g[2],(dp[v][0]+dp[v][2])%p*dp[u][0]%p);//u不染，这条边必须染u,那么dp[v][0/2]
		for(int i=0;i<3;i++)dp[u][i]=g[i],g[i]=0;
	}
	sum[u]=(sum[u]-f+p)%p;
}
void Freopen() {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
}
signed main(){
	Freopen();
	scanf("%lld",&n); 
	for(int i=1,u,v;i<n;i++){
		scanf("%lld%lld",&u,&v);
		G[u].push_back({v,i});
		G[v].push_back({u,i});
	}
	dfs(1,0x7fffffff);
	printf("%lld\n",(dp[1][0]+dp[1][1])%p);
}
/*
100
71 53
77 6
71 2
69 41
27 14
2 30
29 37
94 5
6 21
89 11
76 43
40 93
73 95
41 26
17 39
57 25
57 1
24 13
65 31
67 1
76 31
46 9
17 81
1 41
38 54
90 57
9 86
11 46
61 1
16 51
59 83
41 46
79 51
41 8
25 77
34 16
51 55
48 41
42 92
47 21
63 83
59 46
81 1
5 81
26 51
41 38
85 59
73 71
3 89
88 18
19 97
99 29
97 77
15 12
10 41
2 61
13 37
69 43
13 100
42 53
69 27
34 13
45 57
22 86
84 78
71 15
97 66
18 46
35 1
70 21
69 91
21 56
87 42
7 59
68 81
74 65
36 72
91 60
1 80
58 33
51 40
75 39
33 9
51 62
61 84
72 33
26 52
57 44
50 51
86 96
49 51
53 64
1 20
98 63
32 59
1 23
82 31
28 46
59 4

*/
