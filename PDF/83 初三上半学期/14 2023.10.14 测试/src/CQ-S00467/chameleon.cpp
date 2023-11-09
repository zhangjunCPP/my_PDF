#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
inline void Freopen(){
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
}
int n,k,L;
int d[MAXN],b[MAXN];
int ans[MAXN];
int main(){
	Freopen();
	scanf("%d%d%d",&n,&k,&L);
	for(int i=1;i<=n;i++){
		char ch;
		scanf("%d%d",&d[i],&b[i]); cin>>ch;
		ans[b[i]]+=L;
	}
	for(int i=0;i<k;i++) printf("%.1lf\n",(double)ans[i]);
	return 0;
} 
/*
2 3 10
0 0 D
10 1 L
*/
