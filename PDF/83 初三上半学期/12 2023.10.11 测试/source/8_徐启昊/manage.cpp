/*
35分直接模拟，牛逼。 
60分呢，想要找到最小的时间，每次进来一个数，就调整最小值，1e8 1s能过！
只需要unique(a+1,a+m+1)-a-1即刻。 
*/ 
#include<bits/stdc++.h>
#define Genshin_Impact_starts ios::sync_with_stdio ( false )
//#define int long long
int rd() {
	int x; scanf("%d", &x);
	return x;
}
void Freopen() {
	freopen("manage.in", "r", stdin);
	freopen("manage.out", "w", stdout);
}
void Ft() {
	freopen("ex_manage3.in", "r", stdin);
//	freopen("ex_manage.out", "w", stdout);
}
using namespace std;
const int N=1e6+100, inf=1e9+10;
int n, m;
int a[N], t[N], q[N], sum[N];
void update( int k, int l, int r, int x, int v) {
	if (l==r) return sum[k]=v, void();
	int mid=l+r>>1;
	if (x<=mid) update(k*2, l, mid, x, v);
	else update(k*2+1, mid+1, r, x, v);
	sum[k]=min(sum[k*2], sum[k*2+1]);
}
int ask( int k, int l, int r, int x, int y) {
	if (x<=l&&r<=y) return sum[k];
	int mid=l+r>>1, mi=inf;
	if (x<=mid) mi=min(mi,ask(k*2, l, mid, x, y));
	if (mid<y) mi=min(mi,ask(k*2+1, mid+1, r, x, y));
	return mi;
}
void solve1() {
	for ( int i=0; i<=n*4; i++) sum[i]=inf;
	for ( int i=1; i<=m; i++) q[i]=a[i];
	for ( int k=1; k<=n; k++) {
		int ans=0, cnt=0;
		set< int>v;
		for ( int i=1; i<=m; i++) {
			if (cnt<k&&!v.count(a[i])) {
				cnt++;
				ans++;
				v.insert(a[i]);
				update(1, 1, n, a[i], i);
			}
			else if (v.count(a[i])) {
				update(1, 1, n, a[i], i);
			}
			else if (cnt==k&&!v.count(a[i])) {
				int tim=ask(1, 1, n, 1, n);
				int x=q[tim];
				update(1, 1, n, x, inf);
				v.erase(x);
				v.insert(a[i]);
				update(1, 1, n, a[i], i);
				ans++;
			}
		}
		cout<<ans<<" ";
	}	
}
void solve2() {
	int mm=unique(a+1, a+m+1)-a-1;
//	for ( int i=1; i<=mm; i++) cout<<a[i]<<" ";
//	cout<<endl;
	for ( int k=1; k<=n; k++) {
		for ( int i=1; i<=n; i++) t[i]=0;
		for ( int i=1; i<=mm; i++) q[i]=a[i];
		int mi=1, cnt=0, ans=0;
		for ( int i=1; i<=mm; i++) {
			int x=a[i];
			if (!t[x]&&cnt<k) {
				cnt++;
				ans++;
				t[x]=i;
			}
			else if (t[x]) {
				int lt=t[x];
				t[x]=i;
				if (lt==mi) mi=i-cnt+1;
			}
			else if (!t[x]&&cnt==k) {
				ans++;
				t[q[mi]]=0;
				t[x]=i;
				mi=i-k+1;
			}
		}
		cout<<ans<<" ";
	}
}
signed main() {
	Freopen();
//	Ft();
	cin>>n>>m;
	for ( int i=1; i<=m; i++) cin>>a[i];
	if (m<=4000) return solve1(), 0;
	if (m<=10000) return solve2(), 0; 
}
/*
4 6
2 1 2 2 1 4

5 3 3 3
*/

