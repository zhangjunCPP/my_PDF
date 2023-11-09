#include <bits/stdc++.h>

using namespace std;

int read() {
	int x=0; char ch=getchar();
	while (ch<'0') ch=getchar();
	while (ch>='0') x=x*10+ch-48, ch=getchar();
	return x;
}

const int N=29e5+5;
int n, tot=1, t[N][26], pre[N], id[N], sz[N];
char s[40];

void build(int len, int p) {
	int u=1;
	for (int i=1; i<=len; i++) {
		sz[u]++, pre[p]+=sz[u];
		int c=s[i]-'a';
		if (!t[u][c]) t[u][c]=++tot;
		u=t[u][c];
	}
	sz[u]++, pre[p]+=sz[u];
	if (!id[u]) id[u]=p;
}
int cmp(int len) {
	int u=1, flag=1, cnt=0;
	for (int i=1; i<=len; i++) {
		cnt+=sz[u]; //cout<<sz[u]<<" ";
		int c=s[i]-'a';
		if (!t[u][c]) {flag=0; break;}
		u=t[u][c];
	}
	if (flag) cnt+=sz[u];//, cout<<sz[u]<<" ";
//	cout<<'\n';
	if (flag&&id[u]) return pre[id[u]];
//	cout<<"second ";
	return cnt;
}

int main() {
	freopen("lihua.in", "r", stdin);
	freopen("lihua.out", "w", stdout);
	n=read();
	for (int i=1; i<=n; i++) {
		scanf("%s", s+1);
		build(strlen(s+1), i);
	}
	int Q=read();
	while (Q--) {
		scanf("%s", s+1);
		printf("%d\n", cmp(strlen(s+1)));
	}
	return 0;
}
