#include<bits/stdc++.h>
#define rep(i,x,y) for (int i = (x); i <= (y); ++i)
#define drep(i,x,y) for (int i = (x); i >= (y); --i)
#define go(i,u) for (int i = head[u]; i; i = edge[i].next)
#define MP make_pair
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int N = 1e5 + 2;
struct Node {
	string s;
	int id, opt;
}node[N << 1];
#define base1 100000007
int n, Q, slen;
int ob[N], ans[N];
map<string, int> mp;
inline bool nodecmp (Node a, Node b) {
	if (a.s != b.s) return a.s < b.s;
	else if (a.opt != b.opt) return a.opt < b.opt;
	return a.id < b.id;
}
vector<int> vecs, vecq;
int L, R, retp, mid, fg;
inline void calc (int l, int r, int dep) {
	//cout << l << " " << r << " " << dep << '\n';
	//rep (i, 1, 4) cout << ans[i] << " ";
	//cout << '\n';
	if (l >= r) return;
	fg = 0;
	rep (i, l, r) if (node[i].opt) {
		fg = 1; break; }
	if (!fg) return;
	int now = -1, lt = l;
	rep (i, l, r) {
		if ((int) node[i].s.size() >= dep) {
			//cout << i << '\n';
			now = node[i].s[dep - 1] - 'a';
			if (now != -1 && (i == r || node[i + 1].s[dep - 1] - 'a' != now)) {
				//cout << lt << " " << i << '\n';
				vecs.clear(), vecq.clear();
				rep (j, lt, i) {
					if (!node[j].opt) vecs.emplace_back(node[j].id);
					else vecq.emplace_back(node[j].id);
				}
				if (!vecs.empty()) sort(vecs.begin(), vecs.end());
				for (auto x : vecq) {
					L = 0, R = (int) vecs.size() - 1;
					retp = -1;
					while (L <= R) {
						mid = (L + R) >> 1;
						if (vecs[mid] <= ob[x]) retp = mid, L = mid + 1;
						else R = mid - 1;
					}
					ans[x] += retp + 1;
				}
				calc(lt, i, dep + 1);
				lt = i + 1;
			}
		}
		else lt = i + 1;
	}
}
inline void solve () {
	cin >> n;
	rep (i, 1, n) {
		cin >> node[i].s;
		node[i].id = i, node[i].opt = 0;
		if (!mp[node[i].s]) mp[node[i].s] = i;
	}
	scanf("%d", &Q);
	rep (i, 1, Q) {
		cin >> node[n + i].s;
		node[i + n].id = i, node[i + n].opt = 1;
		ob[i] = mp[node[n + i].s];
		if (!ob[i]) ob[i] = n;
	}
	sort(node + 1, node + n + Q + 1, nodecmp);
	//rep (i, 1, n + Q) cout << node[i].s << '\n';
	calc(1, n + Q, 1);
	rep (i, 1, Q) printf("%d\n", ans[i] + ob[i]);
}
inline void freo () {
	freopen("lihua.in", "r", stdin), freopen("lihua.out", "w", stdout); }
signed main () {
	freo();
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	//cin >> _;
	while (_--) solve();
return 0;
}
/*
5
jiarandaxiaojie
jiarenmensheidonga
jiangshuaisanjun
beimingningxiao
fenbenglixi
4
jianghua
jiaruo
beiguan
feng
*/
