#include<iostream>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n;
char s[N];
namespace sol1{
	#define hash _GrassWondersuki
	typedef unsigned long long ull;
	const ull P=137;
	ull hash[N],pl[N];
	bool pd(int p1,int p2,int len){
		ull w1=hash[p1+len-1]-hash[p1-1]*pl[len];
		ull w2=hash[p2+len-1]-hash[p2-1]*pl[len];
		return w1==w2;
	}
	void solve(){
		pl[0]=1;
		for(int i=1;i<=n;i++)
			pl[i]=pl[i-1]*P,
			hash[i]=hash[i-1]*P+(ull)s[i];
		for(int i=1;i<=n;i++){
			ll rs=0;
			for(int len=1;i+len*3-1<n;len++)
				rs+=(pd(i,n-len+1,len)&pd(i,i+len,len));
			cout<<rs<<' ';
		}
		return ;
	}
}
int main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>s+1;
	n=strlen(s+1);
	sol1::solve();
	return 0;
}
/*
ouvouvouvouvou
*/
