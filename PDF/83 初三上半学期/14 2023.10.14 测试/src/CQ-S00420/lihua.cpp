/*
膜拜传奇特级宗师 zsc985246 大神儿
今天在 florr 首页称您为大夏尊贵的大名儿
一股敬佩之情油生然而
您在 florr 为国争光，扬我大夏威名
向您献上最真挚的膜拜！！！
膜拜传奇特级宗师 zsc985246 大神儿，今，一，您，扬。向！
膜拜传奇特级宗师 zsc985246 大神儿，今，一，您，扬。向！
膜拜传奇特级宗师 zsc985246 大神儿，今，一，您，扬。向！
*/
#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define N 200010
#define ll long long
int n,q;
char s[N][40],t[40];
void solve(){
	cin>>n;
	For(i,1,n)cin>>(s[i]+1);
	cin>>q;
	while(q--){
		cin>>(t+1);
		int l=strlen(t+1),ans=0;
		For(i,1,n){
			int lt=strlen(s[i]+1);
			For(j,1,min(l,lt)){
				if(t[j]!=s[i][j])break;
				++ans;
			};
			++ans;
			if(l==lt&&!strcmp(s[i]+1,t+1))break;
		};
		cout<<ans<<'\n';
	}
	return;
}
int main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}
/*
1s,32MB
*/
