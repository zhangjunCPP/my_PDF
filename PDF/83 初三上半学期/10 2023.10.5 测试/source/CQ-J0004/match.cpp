#include <bits/stdc++.h>
using namespace std;
int T,n,m,edge[1000005],be,x,y,maxx;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	//*
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	//*/
	cin >> T;
	while (T--){
		cin >> n >> m,maxx = 0;
		for (register int i = 1;i <= m;i++) cin >> x >> y,edge[be+x]++,edge[be+y]++;
		for (register int i = 1;i <= n;i++) maxx = max(maxx,edge[be+i]);
		cout << maxx << "\n",be = n;
	}
	return 0;
}
