#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

char buf[1 << 23], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1 ++)
int read() {
	int s = 0, w = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') w = -1; ch = getchar(); }
	while(isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return s * w;
}
void file() {
	freopen("segment.in", "r", stdin);
	freopen("segment.out", "w", stdout);
}

int a[N];
int n;

vector<int> vec;
#define ask(x) lower_bound(vec.begin(), vec.end(), (x)) - vec.begin()
bool vis[N];
bool check(int l, int r) {
	
	if(vec[l] == 9 && vec[r] == 21)  {
		for(int i = 1; i <= n; ++ i)
			cout<<a[i]<<" ";
			puts("");
		}
	vis[0] = vis[n + 1] = true;
	for(int i = 1; i <= n; ++ i) vis[i] = false;
	for(int i = 1; i <= n; ++ i) {
		int cur = ask(a[i]);
		
//		if(vec[l] == 9 && vec[r] == 21) cout << i << endl;
		
		if(l <= cur && cur <= r) continue;
		
		if(!vis[i - 1]) {
			cur = ask(a[i - 1] + a[i]);
			if(l <= cur && cur <= r) {
				vis[i - 1] = vis[i] = true;
				continue;
			}	
		}
				
		
		cur = ask(a[i] + a[i + 1]);
		
		if(vec[l] == 9 && vec[r] == 21 && i == 3)
			cout << a[i] << " " << a[i + 1] << endl,
			cout << a[i] + a[i + 1] << endl;
		
		if(l <= cur && cur <= r) 
			vis[i] = vis[i + 1] = true, ++ i;
		else {
			if(vec[l] == 9 && vec[r] == 21)
				cout<< i<<endl;
			return false;
		}
	}
	return true;
}
void BF() {
	for(int i = 1; i <= n; ++ i)
		vec.push_back(a[i]), vec.push_back(a[i] + a[i + 1]);
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	
	int mn = *min_element(a + 1, a + 1 + n), mx = *max_element(a + 1, a + 1 + n);
	int ans = mx - mn;
	
	for(int l = 0; l < vec.size(); ++ l)
		for(int r = l; r < vec.size(); ++ r)
			if(check(l, r)) { ans = min(ans, vec[r] - vec[l]);break;}
	
	printf("%d\n", ans);
}

signed main() {
	freopen("data.in", "r", stdin);
	n = read();
	for(int i = 1; i <= n; ++ i)
		a[i] = read();
	
	if(n <= 2000) return BF(), 0;

	return 0;
}
