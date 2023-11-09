#include<bits/stdc++.h>
using namespace std;
const int N=1e5+15;
const int ABC=40;
char ch[N];
int n;
vector<int> wh[ABC];
signed main() {
//	freopen("ex_ccfc3.in","r",stdin);
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	cin>>(ch+1); n=strlen(ch+1);
	for(int i=1;i<=n;i++) wh[ch[i]-'a'].push_back(i);
	for(int i=1;i<=n;i++) {
		int ccf=ch[i]-'a',num=0; int ans=0;
		for(int j=0;j<(int)wh[ccf].size();j++) {
			int h=wh[ccf][j];
			if(h<=i) continue;
			num++;
			if(num<2) continue;
			int len=n-h+1;
			if( i+len+len-1>=h-1 ) continue;
			bool fbi=true;
			for(int k=i;k<=i+len-1;k++) {
				if( ch[k]==ch[k+len] && ch[k]==ch[h+(k-i+1)-1] ) continue;
				fbi=false; break;
			} if(fbi) {
				ans++; //cout<<len<<" ";
//				for(int k=i;k<=n;k++) cout<<ch[k];
//				puts("");
			}
		} printf("%d ",ans);
	}
	return 0;
}
