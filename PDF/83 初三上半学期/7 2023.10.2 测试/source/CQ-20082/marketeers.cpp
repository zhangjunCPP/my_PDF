#include<bits/stdc++.h>
using namespace std;
const int N=5e5+55;
int n;
struct node { int k; vector<int> s; } S[N];
vector<int> ant;
int ans,a[N];
void dfs(int now) {
	if(now>n) {
		vector<int> nor; bool fbi=true;
		for(int i=1;i<=n;i++) { int x=0;
			for(int j=i+1;j<=n;j++) if(a[i]>a[j]) x++;
			if(ans&&fbi&&x<ant[i-1]) return;
			if(ans&&x>ant[i-1]) fbi=false;
			nor.push_back(x);
		} if( nor>ant ) ant=nor,ans=1;
		else if(nor==ant) ans++;
		return ;
	} for(int i=0;i<S[now].k;i++) {
		a[now]=S[now].s[i];
		dfs(now+1); 
	}
}
inline int read() {
	int x=0; bool f=false; char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') f=false; ch=getchar(); }
	while(ch>='0'&&ch<='9') { x=(x<<1)+(x<<3)+ch-48; ch=getchar(); }
	return ( f ? -x : x );
}
signed main() {
	freopen("marketeers.in","r",stdin);
	freopen("marketeers.out","w",stdout);
//	scanf("%d",&n);
	n=read();
	for(int i=1;i<=n;i++) {
//		scanf("%d",&S[i].k);
		S[i].k=read();
		for(int j=1;j<=S[i].k;j++) {
			int xp=read(); //scanf("%d",&xp);
			S[i].s.push_back(xp);
		}
	}
	dfs(1);
	printf("%d\n",ans);
//	int tim=clock(); cout<<tim<<" ";
	return 0;
}
/*
10
5
1 2 3 4 5
5
1 2 3 4 5
5
1 2 3 4 5
5
1 2 3 4 5
5
1 2 3 4 5
5
1 2 3 4 5
5
1 2 3 4 5
5
1 2 3 4 5
5
1 2 3 4 5
5
1 2 3 4 5










4
5
7 11 3 10 1 
3
8 6 4 
1
15
3
1 5 99





4
2
2 1 
3
5 1 6 
1
3
3
6 5 7
*/
