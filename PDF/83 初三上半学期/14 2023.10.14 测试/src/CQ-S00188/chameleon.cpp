/*
星铁启动！！！
T1是什么机霸？？
这道题让我想起了一道题，两个人相撞后转向其实可以看做穿了过去。
向左的人变成向右的人的颜色，其实就可以看作向右的人一直向右。
那么对于向右的人可以直接算。 

那么左边的人呢？
模拟一下即可。
*/
#include <bits/stdc++.h>
//#define int long long
void Freopen();
void Ft();
int rd();
const int N=2e5+10, M=2e5+10, inf=1e9+10;
using namespace std;
int n, k, l, cl, cr;
struct node {
	int d, b; char op;	
} a[N], p[N];
int vis[N], tot;
bool cmp( node a, node b) {
	return a.d<b.d; 
}
double ans[N];
int search( int x) {
	int l=0, r=cr;
	while (l<r) {
		int mid=l+r+1>>1;
		if (p[mid].d<=x) l=mid;
		else r=mid-1;
	}
	return l;
}
void solve1() {
	int col;
	for ( int i=0; i<k; i++) if (vis[i]) col=i;
	if (!col) {
		for ( int i=1; i<=cl; i++) ans[a[i].b]+=a[i].d;
		return ;
	}
	int last=0;
	for ( int i=1; i<=cl; i++) {
		int d=a[i].d, b=a[i].b;
		int id=search(d);
		if (!id) {
			ans[b]+=d;
			continue ;
		}
		int b1=b; double d1=0;
		for ( int j=id; j>last; j--) {
			double x=(double)(d-p[j].d)/2-d1;
			ans[b1]+=x;
			b1=(b1+p[j].b)%k;
			d1+=x;
		}
		ans[b1]+=(double)(d)-d1;
	}	
}
void solve2() {
	for ( int i=1; i<=cl; i++) {
		int d=a[i].d, b=a[i].b;
		int id=search(d);
		if (!id) {
			ans[b]+=d;
			continue ;
		}
		int b1=b; double d1=0;
		for ( int j=id; j; j--) {
			double x=(double)(d-p[j].d)/2-d1;
			ans[b1]+=x;
			b1=(b1+p[j].b)%k;
			d1+=x;
		}
		ans[b1]+=(double)(d)-d1;
	}	
}
signed main() {
	Freopen();
//	Ft();
	n=rd(), k=rd(), l=rd();
	for ( int i=1, d, b; i<=n; i++) {
		char op;
		d=rd(), b=rd(), cin>>op;
		if (op=='D') p[++cr]={d, b, op};
		else a[++cl]={d, b, op};
		if (!vis[b]) tot++, vis[b]++;
	}
	sort(a+1, a+cl+1, cmp);
	sort(p+1, p+cr+1, cmp);
	for ( int i=1; i<=cr; i++) ans[p[i].b]+=l-p[i].d;
	if (tot==1) solve1();
	else solve2();
	for ( int i=0; i<k; i++) printf("%.1lf\n", ans[i]);
}
/*
4 3 7
1 0 D
3 0 D
4 1 L
6 2 D

2 3 10
0 0 D
10 1 L

*/
void Freopen() {
	freopen("chameleon.in", "r", stdin);
	freopen("chameleon.out", "w", stdout);
}
void Ft() {
	freopen("chameleon.in", "r", stdin);
	freopen("chameleon.out", "w", stdout);
}
int rd() {
	int x; scanf("%d", &x);
	return x;
}

