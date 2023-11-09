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
int n,k,m,n1,n2;
char s[10];
struct G{
	int x,c;
}a1[N],a2[N];
namespace f1{
	ll len[50];
	void f1(){
		For(i,1,n2){
			ll lx=0,ly=a2[i].c;
			For(j,1,n1)if(a1[j].x<a2[i].x){
				len[ly]+=a2[i].x-a1[j].x-lx;
				lx=a2[i].x-a1[j].x;
				ly=(ly+a1[j].c)%k;
			};
			len[ly]+=a2[i].x*2-lx;
		};
		For(i,1,n1)len[a1[i].c]+=(m-a1[i].x)*2;
		For(i,0,k-1){
			cout<<len[i]/2<<(len[i]&1?".5\n":".0\n");
		};
	}
}
void solve(){
	cin>>n>>k>>m;
	For(i,1,n){
		int x,y;
		cin>>x>>y>>s;
		if(s[0]=='D')a1[++n1]={x,y};
		else a2[++n2]={x,y};
	};
	sort(a1+1,a1+1+n1,[](G x,G y){
		return x.x>y.x;
	});
	sort(a2+1,a2+1+n2,[](G x,G y){
		return x.x<y.x;
	});
	f1::f1();
	return;
}
int main(){
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}
/*
1s,64MB
*/
