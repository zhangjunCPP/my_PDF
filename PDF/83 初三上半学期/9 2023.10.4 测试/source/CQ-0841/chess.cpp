#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define i64 __int128
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define lowbit(i) i&(-i)
const int N = 2077;
int n,p,k,tot;
vector<int> ans[N*N];
void solve(int l,int r){
	if(r-l+1==p){
		tot++;
		for(int i=l;i<=r;i++) ans[tot].pb(i);
		return ;
	}
	int len = (r-l+1),c = (len/p);
	for(int i=l;i+c-1<=r;i+=c) solve(i,i+c-1);	
	for(int i=0;i<c;i++){
		for(int j=0;j<c;j++){
			tot++;
			ans[tot].pb(l+i),ans[tot].pb(l+c+j);
			int now = j,dep = 1;
			while(dep+1<p){
				dep++;
				now = (now+i)%c;
				ans[tot].pb(l+c*dep+now);
			}
		}
	}
	return ;
}
//¹òÁË,ÕâÊÇT1°¡ 
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d %d",&p,&k); 
	n = 1;
	for(int i=1;i<=k;i++) n *= p;
	solve(0,n-1);
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++){
		for(int x:ans[i]) printf("%d ",x);
		printf("\n");
	}
	return 0;
} 
