#include<bits/stdc++.h>
using namespace std;
const int N=2023;
int n,a[N],s[N],ans;
bool vis[N];
void dfs(int now) {
	if(now>n) {
		int u=1,d=1,i=1;
		while(i<=n) {
			int now; bool f=false;
			if( s[i+1]==s[i]+1 && i<n ) {
				now=i; f=true;
				while( s[i+1]==s[i]+1 && i<n ) u++,i++;
				for(int j=now;j<=i;j++) if(a[j]!=u) return ;
				u=1; i++; 
			}
			
			
			if(s[i+1]==s[i]-1 && i<n ) {	
				now=i; f=true;
				while( s[i+1]==s[i]-1 && i<n ) d++,i++;
				for(int j=now;j<=i;j++) if(a[j]!=d) return ;
				d=1; i++;
			}
			if(!f) {
				if(a[i]==1) { i++; continue; }
				else return ;
			}
		}
		//for(int i=1;i<=n;i++) cout<<s[i]<<" ";
		//puts("");
		ans++; return ;
	}
	for(int i=1;i<=n;i++) {
		if(!vis[i]) {
			s[now]=i; vis[i]=true;
			dfs(now+1);
			vis[i]=false;
		}
	}
}
int main() {
	freopen("gap.in","r",stdin);
	freopen("gap.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1); printf("%d",ans);
	return 0;
}
