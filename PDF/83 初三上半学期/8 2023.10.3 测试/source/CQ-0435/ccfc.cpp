#include <bits/stdc++.h>

using namespace std;

int read() {
	int x=0; char ch=getchar();
	while (ch<'0') ch=getchar();
	while (ch>='0') x=x*10+ch-48, ch=getchar();
	return x;
}

const int N=1e5+3, p=131;

char s[N];
unsigned long long h[N], bs[N];

unsigned long long ss(int l, int r) {
	return h[r]-h[l-1]*bs[r-l+1];
}

int n, L[N], lo[N];
vector<int> st[N];
set<int> id;

void solve(int p) {
	for (int x:st[p]) id.insert(x);
	int ans=0;
	for (int i:id) {
		if (lo[i+i-p+1]<=i+1) {
//			cout<<p<<" "<<i<<" "<<i+i-p+1<<'\n';
			ans++;
		}
	}
	printf("%d ", ans);
//	cout<<'\n';
	if (id.find(p)!=id.end()) id.erase(p);
}

int main() {
	freopen("ccfc.in", "r", stdin);
	freopen("ccfc.out", "w", stdout);
	scanf("%s", s+1);
	n=strlen(s+1);
	bs[0]=1;
	for (int i=1; i<=n; i++) {
		h[i]=h[i-1]*p+s[i]-'a'+1, bs[i]=bs[i-1]*p;
	}
	for (int i=1; i<=n; i++) {
		if (s[i]!=s[n]) continue;
		L[i]=i;
		int l=max(1, i-(n-i-1)/2+1), r=i;
		while (l<=r) {
			int mid=(l+r)/2;
			if (ss(mid, i)==ss(n-i+mid, n)) {
				L[i]=mid, r=mid-1;
			}
			else l=mid+1;
		}
		l=1, r=lo[i]=L[i];
		while (l<=r) {
			int mid=(l+r)/2;
			if (ss(mid, i)==ss(n-i+mid, n)) {
				lo[i]=mid, r=mid-1;
			}
			else l=mid+1;
		}
	}
	L[n]=L[n-1]=0;
	if (n-2>=1) L[n-2]=0;
/*	for (int i=1; i<=n; i++) {
		cout<<lo[i]<<" ";
	}
	cout<<'\n';*/
	for (int i=1; i<=n; i++) if (L[i]) {
		st[L[i]].push_back(i);
	}
	for (int i=1; i<=n; i++) if (!lo[i]) lo[i]=n+5;
	for (int i=1; i<=n; i++) solve(i);
	return 0;
}
/*

*/
