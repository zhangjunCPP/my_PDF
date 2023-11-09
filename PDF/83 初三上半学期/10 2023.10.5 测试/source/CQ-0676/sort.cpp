#include <bits/stdc++.h>

using namespace std;

int read() {
	int x=0; char ch=getchar();
	while (ch<'0') ch=getchar();
	while (ch>='0') x=x*10+ch-48, ch=getchar();
	return x;
}

const int N=7e5+3, M=40*N;
int n, pos[N], a[N];
int tot, rt[N], ls[M], rs[M], cnt[M];

void build(int p, int &i, int l, int r, int x) {
	i=++tot;
	if (l==r) return cnt[i]=1, void();
	ls[i]=ls[p], rs[i]=rs[p];
	int mid=l+r>>1;
	if (x<=mid) build(ls[p], ls[i], l, mid, x);
	else build(rs[p], rs[i], mid+1, r, x);
	cnt[i]=cnt[ls[i]]+cnt[rs[i]];
}
int ask(int p, int i, int l, int r, int x) {
	if (l==r) return a[l];
	int mid=l+r>>1;
	int lw=cnt[ls[i]]-cnt[ls[p]];
//	cout<<l<<" "<<mid<<" "<<lw<<'\n';
	if (x<=lw) return ask(ls[p], ls[i], l, mid, x);
	return ask(rs[p], rs[i], mid+1, r, x-lw);
}

long long ans;

void solve(int l, int r) {
	if (r-l<=0) return;
	ans+=r-l+1;
	int k=(r-l)/2+1;
	int p=ask(rt[l-1], rt[r], 1, n, k);
//	cout<<l<<" "<<r<<" "<<p<<" "<<k<<'\n';
	solve(l, p-1), solve(p+1, r);
}

int main() {
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	n=read();
	for (int i=1; i<=n; i++) {
		a[i]=read(), pos[a[i]]=i;
	}
//	cout<<"read over\n";
	for (int i=1; i<=n; i++) {
		build(rt[i-1], rt[i], 1, n, pos[i]);
	}
//	cout<<"build over\n";
	solve(1, n);
	cout<<ans;
	return 0;
}

