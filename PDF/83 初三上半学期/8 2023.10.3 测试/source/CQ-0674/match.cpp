#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;

int v[maxn], ans1[maxn], ans2[maxn];
vector<int> p[maxn];

int main() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++) {
		int k; cin>>k;
		p[i].resize(k+1);
		for(int j=1;j<=k;j++) cin>>p[i][j], v[p[i][j]]|=(1<<i-1);
	}
	int lst=m+1;
	for(int i=m;i>=1;i--) {
		if(v[i]==0) lst=i;
		else if(v[i]==1||v[i]==2) ans1[i]=ans2[i]=1;
		else {
			if(lst==m+1) {
				cout<<"-1\n";
				exit(0);
			}
			ans1[lst]=ans2[lst]=1;
			for(int j=lst-1;j>=1;j--) {
				if(v[j]==1) ans1[j]=1, ans2[j]=0;
				else if(v[j]==2) ans2[j]=1, ans1[j]=0;
				else if(v[j]==3) ans1[j]=ans2[j]=1;
			}
			break;
		}
	}
	int flag=0;
	for(int i=m;i>=1;i--) {
		if(ans1[i]!=ans2[i]) {
			flag=(ans1[i]<ans2[i]);
			break;
		}
	}
	for(int i=m;i>=1;i--) {
		if(flag) cout<<ans1[i];
		else cout<<ans2[i];
	}
	cout<<'\n';
	return 0;
}
