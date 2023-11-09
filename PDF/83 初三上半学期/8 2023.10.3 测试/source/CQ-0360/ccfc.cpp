#include<bits/stdc++.h>
#define int long long
const int N=1e6+10,M=1e5+10,inf=1e9+7;
void Freopen();
void Ftest();
using namespace std;
char s[N];
string str[2050][2050];
signed main() {
	Freopen();
//	Ftest();
	scanf("%s",s+1);
	int n=strlen(s+1);
	if (n<=300) {
		for ( int i=1; i<=n; i++) {
			int ans=0;
			for ( int len=1; i+len*3<=n; len++)	 {
				string t,t1,t2;
				for ( int j=i; j<=i+len-1; j++) t+=s[j];
				for ( int j=i+len; j<=i+len*2-1; j++) t1+=s[j];
				for ( int j=n-len+1; j<=n; j++) t2+=s[j];
				if (t==t1&&t1==t2) ans++;
			}
			printf("%lld ",ans);
		}		
	}
	for ( register int i=1; i<=n; i++)
		for ( register int j=i; j<=n; j++)
			str[i][j]=str[i][j-1]+s[j];
	for ( register int i=1; i<=n; i++) {
		int ans=0;
		for ( register int len=1; i+len*3<=n; len++) {
			if (str[i][i+len-1]==str[i+len][i+2*len-1]&&str[i][i+len-1]==str[n-len+1][n])
				ans++;
		}
		printf("%lld ",ans);
	}
}
void Freopen() {
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
}
void Ftest() {
	freopen("ex_ccfc3.in","r",stdin);
	freopen("ccfc.out","w",stdout);
}

