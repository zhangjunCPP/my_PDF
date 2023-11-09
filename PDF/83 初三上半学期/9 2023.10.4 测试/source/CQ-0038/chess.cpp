#include<bits/stdc++.h>
#define int long long
const int N=1e6+10,M=1e5+10,inf=1e9;
void Freopen();
void Ftest();
int rd() {
	int x; scanf("%lld",&x);
	return x;
}
void wt( int x, int op=0) {
	if (!op) printf("%lld ",x);
	else printf("%lld\n",x);
}
using namespace std;
int p,k,ans;
int ksm( int a, int b) {
	int res=1;
	while (b) {
		if (b&1) res=res*a;
		a=a*a,b>>=1;
	}
	return res;
}
int col[N],vis[2300][2300],Ans[2030][2030];
void dfs( int dep, int n, int last, int sum) {
	if (ans<sum) {
		ans=sum;
		for ( int i=1; i<=p; i++)
			Ans[ans][i]=col[i];
	}
	ans=max(ans,sum);
	for ( int i=1; i<=dep-1; i++)
		for ( int j=1; j<=dep-1; j++)
			if (i!=j) if (vis[col[i]][col[j]]) return ;
	if (dep==p+1) {
		for ( int i=1; i<=p; i++)
			for ( int j=1; j<=p; j++)
				if (i!=j) vis[col[i]][col[j]]=1;
		dfs(1,n,1,sum+1);
		for ( int i=1; i<=p; i++)
			for ( int j=1; j<=p; j++)
				if (i!=j) vis[col[i]][col[j]]=0;		
	}
	for ( int i=last; i<=n; i++) {
		col[dep]=i;
		dfs(dep+1,n,i+1,sum);
	}
}
signed main() {
	Freopen();
//	Ftest();
	p=rd(),k=rd();
	if (k==1) {
		wt(1,1);
		for ( int i=0; i<p; i++) wt(i);
		return 0;
	}
	if (p==2) {
		int n=ksm(p,k);
		wt(n*(n-1)/2,1);
		for ( int i=0; i<n; i++)
			for ( int j=i+1; j<n; j++) 
				wt(i),wt(j,1);
		return 0;
	}
	int n=ksm(p,k);	
	dfs(1,n,1,0);
	cout<<ans;
	cout<<endl;
	for ( int i=1;i<=ans;i++){
		for(int j=1;j<=p;j++)
		cout<<Ans[i][j]<<" ";
		cout<<endl;
	}
}
void Freopen() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
}
void Ftest() {
//	freopen(".in","r",stdin);
	freopen("chess.out","w",stdout);
}

