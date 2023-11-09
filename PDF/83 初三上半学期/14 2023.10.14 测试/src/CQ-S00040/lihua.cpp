#include<bits/stdc++.h>
using namespace std;
const int N=1e5+15;
int n,Q;
string s[N],t;
signed main() {
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	scanf("%d",&n); for(int i=1;i<=n;i++) cin>>s[i];
	scanf("%d",&Q);
	while(Q--) {
		cin>>t; int len=t.size(); int ans=0;
		for(int i=1;i<=n;i++) { bool fbi=true; ans++;
			for(int j=0;j<min( (int)s[i].size(),len )&&fbi;j++) {
//				cout<<s[i][j]<<" "<<t[j]<<endl;
				if(s[i][j]==t[j])ans++;
				if(s[i][j]!=t[j]) fbi=false;
			} if((int)s[i].size()!=len) continue;
			if(fbi) break;
		} printf("%d\n",ans);
	}
	return 0;
} 
/*
8
majmunica
majmun
majka
malina
malinska
malo
maleni
malesnica
3
krampus
malnar
majmun
*/
