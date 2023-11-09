#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
ll n, ans, depc = 0, hd[1000010], e[2000010][2], deg[1000010], dep[1000010], dis[1010][1010];
bool fla = true, flb = true, flc = true;
ll qpw(ll x, ll y){
	ll res = 1;
	while(y > 0){
		if(y & 1) res = res * x % mod;
		x = x * x % mod; y >>= 1;
	}
	return res;
}
void dfsc(ll u, ll fa){
	ll i, v;
	if(deg[u] == 1){
		if(depc == 0) depc = dep[u];
		else if(depc != dep[u]) flc = false;
	}
	for(i = hd[u]; i > 0; i = e[i][0]){
		v = e[i][1];
		if(v != fa){
			dep[v] = dep[u] + 1; dfsc(v, u);
		}
	}
}
int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	ll i, u, v, mx;
	scanf("%lld", &n);
	for(i = 1; i <= n; i++){
		hd[i] = 0; deg[i] = 0;
		if(n <= 1e3+5){
			for(u = 1; u <= n; u++) dis[i][u] = n + 1;
			dis[i][i] = 0;
		}
	}
	for(i = 1; i >> 1 < n - 1; i++){
		scanf("%lld%lld", &u, &v); deg[u]++; deg[v]++;
		if(n <= 1e3+5) dis[u][v] = 1, dis[v][u] = 1;
		e[i][0] = hd[u]; e[i][1] = v; hd[u] = i;
		i++;
		e[i][0] = hd[v]; e[i][1] = u; hd[v] = i;
		if(abs(u - v) != 1) fla = false;
		if(u != 1 && v != 1) flb = false;
	}
	if(deg[1] <= 2) flc = false;
	if(flc){
		for(i = 2; i <= n; i++){
			if(deg[i] > 2){ flc = false; break; }
		}
		if(flc){ dep[1] = 0; dfsc(1, 0); }
	}
	if(fla){
		ans = (n - 1) * qpw(2, n);
		for(i = 1; i << 1 <= n; i++){
			ans = (ans + mod - qpw(2, n - (i << 1) + 1)) % mod;
		}
	}else if(flb){
		if(n == 3) ans = 12;
		else ans = qpw(2, n + 1);
	}else if(flc){
		ans = depc * qpw(2, n + 1) % mod;
	}else{
		ans = 0;
		for(i = 1; i <= n; i++){
			for(u = 1; u <= n; u++){
				for(v = 1; v <= n; v++){
					dis[u][v] = min(dis[u][v], dis[u][i] + dis[i][v]);
				}
			}
		}
		for(i = 0; i < 1 << n; i++){
			mx = 0;
			for(u = 1; u <= n; u++){
				for(v = 1; v <= n; v++){
					if((i >> u - 1 & 1) == (i >> v - 1 & 1)) mx = max(mx, dis[u][v]);
				}
			}
			ans = (ans + mx) % mod;
		}
	}
	printf("%lld", ans);
	return 0;
}
