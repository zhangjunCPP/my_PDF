#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}return x*f;}
inline void write(int x){if(x<0){x=~(x-1);putchar('-');}if(x>9)write(x/10);putchar(x%10+'0');}
#define put() putchar(' ')
#define endl puts("")

const int MAX = 1e6 + 10;

int cnt[MAX];

void solve(){
	int n = read(), m = read();
	int M = read(), N = read(), B = read();
	for(int i = 1; i < n; i++){
		int u = read(), v = read();
		cnt[u] ++, cnt[v] ++;
	}
	int ans = M * m - N * n + 0;
	// int maxn = 0;
	// for(int i = 1; i <= n; i++)	maxn = max(maxn, cnt[i]);
	// ans = max(ans, B * maxn - N);
	write(n), put(), write(ans), endl;
}

signed main(){
	freopen("subgraph.in", "r", stdin);
	freopen("subgraph.out", "w", stdout);
	int t = 1;
	while(t--)	solve();
	return 0;
}