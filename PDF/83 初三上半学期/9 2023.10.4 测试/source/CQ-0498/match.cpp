#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int k,q,n;
string s,p;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>k>>s>>q;
	s=' '+s;
	n=s.size();
	while(q--){
		cin>>p;
		p=' '+p;
		int m=p.size(),ans=0;
		for(int i=1;i<=n-m+1;i++){
			string t=' '+s.substr(i,p.size()-1);
			int maxn=-1,minn=0x3f3f3f3f;
			for(int j=1;j<=m;j++) if(p[j]!=t[j]){
				maxn=max(j,maxn);
				minn=min(j,minn);
			}
			if(maxn==-1||maxn-minn<k) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
2
baccbcbabc
7
a
abc
aaa
bbb
abbb
acbbc
iamasuperlongstring

*/
