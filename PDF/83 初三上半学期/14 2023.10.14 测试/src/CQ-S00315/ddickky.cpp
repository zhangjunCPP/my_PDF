#include<bits/stdc++.h>
#define int long long
const int mod=998244353;
const int QWQ=2e5+5;
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<1)+(x<<3)+(ch^48); ch=getchar(); }
	return x*f;
} int l,r,sl,s[20],res; bool v[20];
int n,q,a[QWQ],d[20][20];
void dfs(int k){
	if (k>r){
		sl=0;
		for (int i=l;i<=r;i++)
			if (v[i]) s[++sl]=a[i];
		if (!sl) return ;
		int cgd=s[1];
		for (int i=2;i<=sl;i++)
			cgd=__gcd(cgd,s[i]);
		res=res*cgd%mod;
		return ;
	}
	v[k]=1;
	dfs(k+1);
	v[k]=0;
	dfs(k+1);
}
void pre_work(){
	for (l=1;l<=n;l++)
	for (r=l;r<=n;r++){
		res=1;
		for (int i=l;i<=r;i++) v[i]=0;
		dfs(l);
		d[l][r]=res;
	}
}
signed main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	n=read(),q=read();
	for (int i=1;i<=n;i++) a[i]=read();
	if (n<=20){
		pre_work();
		while (q--){
			int l=read(),r=read();
			printf("%lld\n",d[l][r]);
		}
	} else{
		while (q--){
			int l=read(),r=read();
		}
	}
	return 0;
}
