//the code is from chenjh
#include<bits/stdc++.h>
#define MAXN 5000005
using namespace std;
typedef stack<int,vector<int> > mystack;
int n,p;
int a[MAXN];
vector<int> c;
bool check(){
	c.resize(n);
	for(int i=1;i<=n;i++) c[i-1]=a[i];
	mystack s1,s2,b;
	for(int r=n,t=1;(int)b.size()<n;){
		if(!s2.empty() && s2.top()==r)s2.pop(),b.emplace(r--);
		else if(!s1.empty() && s1.top()==t) s2.push(t++),s1.pop();
		else if(!c.empty() && (s1.empty() || c.back()<s1.top())) s1.push(c.back()),c.pop_back();
		else return 1;
	}
	return 0;
}
void solve(){
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++) a[i]=i;
	int ans=0;
	do{
		if((ans+=check())>=p) ans-=p;
	}while(next_permutation(a+1,a+n+1));
	printf("%d\n",ans);
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--) solve();
	return 0;
}

