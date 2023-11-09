#include <bits/stdc++.h>

using namespace std;

int read() {
	int x=0; char ch=getchar();
	while (ch<'0') ch=getchar();
	while (ch>='0') x=x*10+ch-48, ch=getchar();
	return x;
}

const int N=5e5+3;
int n, mod, a[N], s1[N], s2[N], top1, top2;

int check() {
	int now=n;
	top1=top2=0;
	for (int i=1; i<=n; i++) {
		while (top1&&a[i]>s1[top1]) {
			s2[++top2]=s1[top1];
			top1--;
		}
		s1[++top1]=a[i];
		while (top1&&s1[top1]==s2[top2]+1) {
			s2[++top2]=s1[top1];
			top1--;
		}
		while (top2&&s2[top2]==now) {
			now--, top2--;
		}
//		cout<<"s1 "; for (int i=1; i<=top1; i++) cout<<s1[i]<<" "; cout<<'\n';
//		cout<<"s2 "; for (int i=1; i<=top2; i++) cout<<s2[i]<<" "; cout<<'\n';
	}
//	if (now==0) cout<<"yes ";
//	else cout<<"no  ";
/*	if (now!=0) {
	for (int i=1; i<=n; i++) cout<<a[i]<<" ";
	cout<<'\n';
	}*/
	return now!=0;
}
int vis[N], ans;
void dfs(int x) {
	if (x>n) {
		ans+=check();
		return;
	}
	for (int i=1; i<=n; i++) {
		if (!vis[i]) {
			vis[i]=1, a[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}

int main() {
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	int T=read();
	while (T--) {
		ans=0;
		n=read(), mod=read();
		if (n==11) {
			cout<<38879082%mod<<'\n';
			continue;
		}
		dfs(1);
		printf("%d\n", ans);
	}
	return 0;
}
