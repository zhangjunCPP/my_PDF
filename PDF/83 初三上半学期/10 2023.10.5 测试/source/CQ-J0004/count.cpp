#include <bits/stdc++.h>
#define int long long 
using namespace std;
int T,n,ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	//*
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	//*/
	cin >> T;
	while (T--){
		cin >> n,ans = 0;
		for (register int i = 1;i <= n;i++){
			for (register int j = 1;j <= n;j++){
				for (register int k = 1;k <= n;k++) ans += (i*j%k==0&&i*j/k<=n);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
