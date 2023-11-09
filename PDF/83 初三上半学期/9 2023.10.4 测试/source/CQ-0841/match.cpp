#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define i64 __int128
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define lowbit(i) i&(-i)
const int N = 2e5+7;
int n,k,q;
char s[N],c[N];
bool check(int l,int r){
	int mx = 0,mn = 1e9,len = r-l+1;
	for(int i=l,j=1;i<=r && j<=len;i++,j++){
		if(s[i]==c[j]) continue;
		mx = max(j,mx);
		mn = min(j,mn);
	}
	return mx-mn<k;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> k >> s+1;
	n = strlen(s+1);
	cin >> q;
	while(q--){
		cin >> c+1;
		int m = strlen(c+1),ans = 0;
		for(int i=1;i+m-1<=n;i++) if(check(i,i+m-1)) ans++;
		cout << ans << '\n';
	}
	return 0;
}

