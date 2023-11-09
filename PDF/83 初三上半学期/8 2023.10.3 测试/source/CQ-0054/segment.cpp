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

void BBF() {
	int lim = 1 << (n - 1), ans = 1e9 + 5;
	for(int s = 0; s < lim; ++ s) {
		bool fg = true;
		for(int i = 1; i <= n - 2; ++ i)
			if((s >> (i - 1)) & 1)
				if((s >> i) & 1) fg = false;
		if(!fg) continue;
		
		vector<int> vec;
		for(int i = 1; i <= n; ++ i)
			if(i < n && ((s >> (i - 1)) & 1))
				vec.push_back(a[i] + a[i + 1]), ++ i;
			else vec.push_back(a[i]);
		int mn = *min_element(vec.begin(), vec.end());
		int mx = *max_element(vec.begin(), vec.end());
		ans = min(ans, mx - mn);
	}
	printf("%d\n", ans);
}

signed main() {
	file();
	n = read();
	for(int i = 1; i <= n; ++ i)
		a[i] = read();
		
	if(n <= 18) return BBF(),0;
	
	return 0;
}
