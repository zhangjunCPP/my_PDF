#include <bits/stdc++.h>

using namespace std;

int read() {
	int x=0; char ch=getchar();
	while (ch<'0') ch=getchar();
	while (ch>='0') x=x*10+ch-48, ch=getchar();
	return x;
}

const int N=1e5+3;
int n, k, len;
double ans[50];
#define d first
#define c second
vector<pair<int, int> > L, R;

void solve1() {
	sort(R.begin(), R.end());
	for (auto i:R) ans[i.c]+=len-i.d;
	for (auto i:L) {
		cout<<"solve "<<i.d<<" "<<i.c<<'\n';
		int cur=i.c, las=i.d;
		for (int it=R.size()-1; it>=0; it--) {
			auto j=R[it];
			if (j.d>i.d) continue;
			cout<<"1111 "<<cur<<" "<<(las-j.d)/2.0<<'\n';
			ans[cur]+=(las-j.d)/2.0;
			cur=(cur+j.c)%k, las=j.d;
		}
		cout<<cur<<" "<<(las+i.d)/2.0<<'\n';
		ans[cur]+=(las+i.d)/2.0;
	}
	for (int i=0; i<k; i++) printf("%.1lf\n", ans[i]);
}

int cnt[50], sum[N];

void solve2() {
	if (R.empty()) {
		for (auto i:L) ans[i.c]+=i.d;
		for (int i=0; i<k; i++) printf("%.1lf\n", ans[i]);
		return;
	}
	sort(R.begin(), R.end());
	sort(L.begin(), L.end());
	for (auto i:R) ans[i.c]+=len-i.d;
	int p=0;
	while (p<L.size() && L[p].d<R[0].d) {
		ans[L[p].c]+=L[p].d, p++;
	}
//	cout<<L[3].c<<'\n';
	for (int i=0; i<R.size(); i++) {
		if (i) sum[i]=sum[i-1];
		sum[i]=(sum[i]+R[i].c)%k;
		while (p<L.size() && L[p].d<R[i].d) {
			ans[L[p].c]+=(L[p].d-R[i-1].d)/2.0;
//			cout<<(L[p].d-R[i-1].d)/2.0<<' ';
			L[p].c=(L[p].c+sum[i-1])%k;
			ans[L[p].c]+=(R[0].d+L[p].d)/2.0;
//			cout<<R[0].d<<" "<<(R[0].d+L[p].d)/2.0<<'\n';
			p++;
		}
	}
	int o=R.size()-1;
	while (p<L.size()) {
		ans[L[p].c]+=(L[p].d-R[o].d)/2.0;
//		cout<<(L[p].d-R[o].d)/2.0<<' ';
		L[p].c=(L[p].c+sum[o])%k;
		ans[L[p].c]+=(R[0].d+L[p].d)/2.0;
//		cout<<R[0].d<<" "<<(R[0].d+L[p].d)/2.0<<'\n';
		p++;
	}
//	cout<<"now "<<L[3].c<<'\n';
//	for (int i=0; i<k; i++) printf("%.1lf\n", ans[i]);
	p=L.size()-1;
//	cout<<'\n';
	for (int i=R.size()-1; i>=1; i--) {
		while (p>=0 && L[p].d>R[i].d) {
			cnt[L[p].c]++, p--;
		}
		for (int w=0; w<k; w++) {
//			if (i==2)
//				cout<<w<<" "<<(R[i].d-R[i-1].d)/2.0<<" "<<cnt[(w+sum[i-1])%k]<<'\n';
			ans[w]+=(R[i].d-R[i-1].d)/2.0*cnt[(w+sum[i-1])%k];
		}
	}
//	cout<<'\n';
	for (int i=0; i<k; i++) printf("%.1lf\n", ans[i]);
}

int main() {
	freopen("chameleon.in", "r", stdin);
	freopen("chameleon.out", "w", stdout);
//	freopen("data.in", "r", stdin);
//	freopen("chameleon4.in", "r", stdin);
	n=read(), k=read(), len=read();
	for (int i=1; i<=n; i++) {
		int d=read(), c=read();
		char t; cin>>t;
		if (t=='D') R.push_back({d, c});
		else L.push_back({d, c});
	}
//	if (R.size()<=30||n<=1000) solve1();
//	else solve2();
	solve2();
	return 0;
}
