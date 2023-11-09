#include<bits/stdc++.h>
#define ppc(x) __builtin_popcount(x)
#define lowbit(x) (-x & x)
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
const int M = 1 << 7 | 5;

char buf[1 << 23], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1 ++)
int read() {
	int s = 0, w = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') w = -1; ch = getchar(); }
	while(isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return s * w;
}
void file() {
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
}

ll f[N][M][M], g[M][M], h[M][M], c[N];
int l[N], r[N];
int n;

bool cmax(ll &a, ll b) { return a < b ? a = b, 1 : 0; }

int getl(int i) {
	int A = (1 << 7) - 1;
	int B = (1 << (7 - (i - l[i]))) - 1;
	return A - B;
}
int getr(int i) {
	return (1 << (r[i] - i)) - 1;
}
int calc(int i, int s1, int s2) {
	int L = getl(i), R = getr(i);
	L &= s1, R &= s2;
	
//	printf("%d %d %d->%d\n", i, s1, s2, ppc(L) + ppc(R));
	
	return ppc(L) + ppc(R);
}

bool vis[N];
void BF() {
	vector<int> vec;
	for(int i = 0; i < n; ++ i)
		vec.push_back(i);
	ll ans = 0;
	do {
		ll res = 0;
		for(int i = 1; i <= n; ++ i) vis[i] = true;
		for(int i = 0; i < n; ++ i) {
			int cur = vec[i] + 1, cnt = 0;
			vis[cur] = false;
			for(int j = l[cur]; j <= r[cur]; ++ j)
				cnt += vis[j];
			res += 1ll * cnt * c[cur];
		}
		ans = max(ans, res);
	} while(next_permutation(vec.begin(), vec.end()));
	printf("%lld\n", ans);
}

void check(int i, int s1, int s2) {
	
	printf("%d %d %d\n", i, s1, s2);
	for(int j = 0; j <= 6; ++ j) {
		if(i - j - 1 <= 0 && ((s1 >> (6 - j)) & 1)) s1 ^= (1 << (6 - j));
		if(i + j + 1 >= n + 1 && ((s2 >> j) & 1)) s2 ^= (1 << j);
	}
	
	vector<int> vec;
	for(int i = 0; i < n; ++ i)
		vec.push_back(i);
	ll ans = 0;
	do {
		ll res = 0, t1, t2;
		for(int i = 1; i <= n; ++ i) vis[i] = true;
		for(int _ = 0; _ < n; ++ _) {
			int cur = vec[_] + 1, cnt = 0;
			vis[cur] = false;
			
			for(int j = l[cur]; j <= r[cur]; ++ j)
				cnt += vis[j];
			if(cur <= i) res += 1ll * cnt * c[cur];
			
			if(cur == i) {
				t1 = 0, t2 = 0;
				for(int j = 0; j <= 6; ++ j) {
					if(cur - j - 1 >= 1) t1 |= ((1 << (6 - j)) * vis[cur - j - 1]);
					if(cur + j + 1 <= n) t2 |= ((1 << j) * vis[cur + j + 1]);
				}
				
				if(s1 != t1 || s2 != t2) { res = 0;/* for(auto v : vec) cout << v+1<<" ";cout<<endl;*/break; }
			}
		}
		ans = max(ans, res);
		
		if(res) {
			for(auto v : vec) cout << v+1<<" ";
			cout << " -> "<<res << "  " << t1 << " " << t2 << endl;
		}
		
	} while(next_permutation(vec.begin(), vec.end()));
//	printf("%lld ", f[i][s1][s2]);
//	printf("%lld\n", ans);
	printf("%d %d %d\n", i, s1, s2);
	printf("%lld %lld\n", f[i][s1][s2], ans);
	assert(f[i][s1][s2] == ans);
}

signed main() {
	freopen("data.in", "r", stdin);
	n = read();
	for(int i = 1; i <= n; ++ i)
		l[i] = read(), r[i] = read(), c[i] = read();
		
//	if(n <= 10) return BF(), 0;
		
	int lim = (1 << 7) - 1;
		
	for(int i = 1; i <= n; ++ i)
		for(int s1 = 0; s1 <= lim; ++ s1)
			for(int s2 = 0; s2 <= lim; ++ s2)
				f[i][s1][s2] = -1e16;
				
	for(int s2 = 0; s2 <= lim; ++ s2)
		f[1][0][s2] = c[1] * calc(1, 0, s2);
	for(int i = 1; i < n; ++ i) {
		for(int s1 = 0; s1 <= lim; ++ s1)
			for(int s2 = 0; s2 <= lim; ++ s2)
				g[s1][s2] = h[s1][s2] = -1e16;
		
		for(int s1 = 0; s1 <= lim; ++ s1)
			for(int s2 = 0; s2 <= lim; ++ s2) {
				int t1 = s1 >> 1, t2 = s2 >> 1;
				if(s2 & 1) 
					cmax(h[t1][t2 | (1 << 6)], f[i][s1][s2]);
				else cmax(g[t1 | (1 << 6)][t2], f[i][s1][s2]);
			}
		for(int s1 = 0; s1 <= lim; ++ s1)
			for(int s2 = 0; s2 <= lim; ++ s2) 
				for(int i = 0; i < 7; ++ i) {
					if(s1 >> i & 1) cmax(g[s1][s2], g[s1 - (1 << i)][s2]);
					if(s2 >> i & 1)	cmax(g[s1][s2], g[s1][s2 - (1 << i)]);
				}
		for(int s1 = lim; s1 >= 0; -- s1)
			for(int s2 = lim; s2 >= 0; -- s2) 
				for(int i = 0; i < 7; ++ i) {
					if(s1 >> i & 1) cmax(h[s1 - (1 << i)][s2], h[s1][s2]);
					if(s2 >> i & 1)	cmax(h[s1][s2 - (1 << i)], h[s1][s2]);
				}
			
		for(int s1 = 0; s1 <= lim; ++ s1)
			for(int s2 = 0; s2 <= lim; ++ s2)
				f[i + 1][s1][s2] = max(g[s1][s2], h[s1][s2]) + c[i + 1] * calc(i + 1, s1, s2);
//				printf("%d %d %d= %lld\n",i + 1, s1, s2, f[i+1][s1][s2]);
	}
	
//	for(int i = 1; i <= n; ++ i)
//		for(int s1 = 0; s1 <= lim; ++ s1)
//			for(int s2 = 0; s2 <= lim; ++ s2)
//				check(i, s1, s2);

	cout << f[2][1 << 6][3] << endl;
	check(2, 1<<6, 3);
//	check(3, 32, 0);
	
	ll ans = 0;
	for(int s1 = 0; s1 <= lim; ++ s1)
		ans = max(ans, f[n][s1][0]);
	printf("%lld\n", ans);
	return 0; 
} 
/*
16:00 GGG
16:10:
5
1 3 3
2 4 4
1 3 5
2 4 3
3 5 2

*/
