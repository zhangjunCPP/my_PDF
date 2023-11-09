#include<bits/stdc++.h>
#define int long long
const int QWQ=1e6+5;
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
}
int n,a[QWQ],s[QWQ],res;
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
//	for (int i=1;i<=n;i++) cout<<s[i]<<' '; puts("");
	for (int i=1;i<=n;i++){
		int t=lower_bound(a+1,a+i+1,s[i]/i+1)-a;
//		cout<<s[i]/i+1<<' '<<t<<' '<<i-t+1<<'\n';
		res=max(res,i-t+1);
	} printf("%d",res);
	return 0;
}
