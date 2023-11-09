#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define i64 __int128
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define lowbit(i) i&(-i)
const int N = 2077;
ll n,in[N],ord[N],rk[N],d[N],tot;
ll f[1<<21],w[1<<21][21];
struct node{
	ll l,r,c,p;
}a[N]; 
vector<int> e[N];
void add(int u,int v){
	e[u].pb(v),in[v]++;
}
void bfs(){
	queue<int> q;
	for(int i=1;i<=n;i++) if(!in[i]) q.push(i);
	while(q.size()){
		int u = q.front(); q.pop();
		rk[u] = ++tot; 
		for(int v:e[u]){
			in[v]--;
			if(!in[v]) q.push(v);
		}
	}
}
ll calc(){
	ll res = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(a[i].l<=a[j].p && a[j].p<=a[i].r) d[j] += a[i].c;
		}
	}
	for(int i=1;i<=n;i++){
		int id = ord[i];
		res += (a[id].r-a[id].l)*a[id].c-d[id];
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(a[id].l<=a[j].p && a[j].p<=a[id].r) d[j] -= a[id].c;
		}
	}
	return res;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n; 
	for(int i=1;i<=n;i++){
		cin >> a[i].l >> a[i].r >> a[i].c;
		a[i].p = i;
	} 
	if(n<=20){
		f[0] = 0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(a[i].l<=a[j].p && a[j].p<=a[i].r) w[(1<<(i-1))][j] = a[i].c;
			}
		}
		for(int i=1;i<(1<<n);i++){
			int k = 0;
			for(int j=1;j<=n;j++){
				if((1<<(j-1))&i){
					k = j;
					break;
				}
			}
			for(int j=1;j<=n;j++){
				if(w[i][j]) continue;
				if((1<<(j-1))&i) continue;
				w[i][j] = w[i^(1<<(k-1))][j]+w[(1<<(k-1))][j];
			}
		}
		for(int i=0;i<(1<<n);i++){
			for(int j=1;j<=n;j++){
				if((1<<(j-1))&i) continue;
				f[i|(1<<(j-1))] = max(f[i]+(a[j].r-a[j].l)*a[j].c-w[(i|(1<<(j-1)))^((1<<n)-1)][j],f[i|(1<<(j-1))]);
			}
		}
		cout << f[(1<<n)-1];
	}else{
		for(int i=1;i<=n;i++){
			node x = a[i];
			for(int j=i+1;j<=n;j++){
				node y = a[j];
				if(x.l<=y.p && y.p<=x.r && y.l <=x.p && x.p<=y.r){
					if(x.c==y.c) continue;
					if(x.c>y.c) add(i,j);
					else add(j,i);
				}else if((x.l<=y.p && y.p<=x.r) || (y.l <=x.p && x.p<=y.r)){
					if(x.l<=y.p && y.p<=x.r) add(i,j);
					else add(j,i);
				}
			}
		} 
		bfs();
		for(int i=1;i<=n;i++) ord[rk[i]] = i;
		cout << calc();
	}
	return 0;
}
//考虑如下贪心：
//贡献定义为w*(r-l)-sum_influence
//[l1,r1],[l2,r2]:
//互不相关：随意 
//1 包含 2，2 不包含 1：
//1使得2的贡献-w1
//2不影响1的贡献 
//因此1先算。
//2 包含 1，同理。
//换句话讲，要使得包含他人的，放在前面先算 
//互相包含：贡献较大的先算。  
//O(n^2)，那就建图。
//u->v表示u在v的前面。 
//有环啊，n^3也行啊
//有个性质还没用
//环的必要条件是最后一个需要和第一个有交，但也意味着环长至多为7
//每个点最多14条边 
//或者mst，但是这是有向图啊 
