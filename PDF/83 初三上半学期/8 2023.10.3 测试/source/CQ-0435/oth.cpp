#include <bits/stdc++.h>

using namespace std;

int read() {
	int x=0; char ch=getchar();
	while (ch<'0') ch=getchar();
	while (ch>='0') x=x*10+ch-48, ch=getchar();
	return x;
}

const int N=1e6+3;
vector<int> a[N];
int n, m, id[N], t[N], vis[N];

int cmp(int i, int j) {
	if (a[i].size()==0) return 0;
	if (a[j].size()==0) return 1;
	for (int p=0; p<min(a[i].size(), a[j].size()); p++) {
		if (a[i][p]!=a[j][p]) return a[i][p]>a[j][p];
	}
	return a[i].size()>a[j].size();
}

int up(int p) {
	for (int i=p+1; i<=m; i++) {
		if (!t[i]) {
			t[i]=1, t[p]=0;
			break;
		}
		t[i]=0;
	}
	return t[p];
}

int main() {
	n=read(), m=read();
	for (int i=1; i<=n; i++) {
		int k=read();
		while (k--) a[i].push_back(read());
		reverse(a[i].begin(), a[i].end());
		id[i]=i;
	}
	sort(id+1, id+1+n, cmp);
	for (int i=1; i<=n; i++) cout<<id[i]<<" ";
	cout<<'\n';
	for (int i=n; i>=1; i--) {
		memset(t, 0, sizeof(t));
		for (auto x:a[id[i]]) t[x]=1;
		for (int p=1; p<=m; p++) if (t[p]&&vis[p]) {
			if (up(p)) return puts("-1"), 0;
		}
		for (int p=1; p<=m; p++) {
			vis[p]|=t[p];
		}
	}
	for (int i=m; i>=1; i--) putchar(vis[i]+'0'); 
	return 0;
}
/*

*/
