#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
using ull=unsigned long long;
const int Maxn=1e5+5;
const int Pri=1789;
char s[Maxn];
ull P[Maxn]={1};
ull H[Maxn];
inline ull calc(int l,int r){
	return H[r]-H[l-1]*P[r-l+1];
}
int a[Maxn];
int ans[Maxn];
int main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	cin>>(s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;++i)P[i]=P[i-1]*Pri;
	for(int i=1;i<=n;++i)H[i]=H[i-1]*Pri+s[i];
	for(int i=3;i<=n;++i)
		for(int j=i;j<n;++j){
			int m=n-j;if(i<=(m<<1))continue;
			if(calc(j+1,n)!=calc(i-m-m,i-m-1))continue;
			if(calc(j+1,n)!=calc(i  -m,i  -1))continue;
			++ans[i-m-m];
		}
	for(int i=1;i<=n;++i)cout<<ans[i]<<' ';
	cout<<'\n';
	return 0;
}
