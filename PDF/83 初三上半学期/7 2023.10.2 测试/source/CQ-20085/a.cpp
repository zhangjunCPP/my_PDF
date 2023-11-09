#include<bits/stdc++.h>
using namespace std;
int n,m,q,v,r,d,px,py,a1[250001],b1[250001],a2[250001],b2[250001],dx[8]={1,1,0,-1,-1,-1,0,1},dy[8]={0,1,1,1,0,-1,-1,-1};
struct tree{
	int T[5001];
	void add(int x,int v){
		for(int i=x;i<=5000;i+=i&-i) T[i]+=v;
	}
	int ask(int x){
		int res=0;
		for(int i=x;i>=1;i-=i&-i) res+=T[i];
		return res;
	}
}t[5001];
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%d%d%d%d",&a1[i],&b1[i],&a2[i],&b2[i]);
	for(int i=1;i<=n;i++) for(int j=a1[i];j<=a2[i];j++) t[j].add(b1[i],1),t[j].add(b2[i]+1,-1);
	while(m--){
		scanf("%d%d%d",&v,&r,&d);
		for(int i=1;i<=d;i++){
			a1[r]+=dx[v],b1[r]+=dy[v],a2[r]+=dx[v],b2[r]+=dy[v];
			for(int j=a1[r];j<=a2[r];j++) t[j].add(b1[r],1),t[j].add(b2[r]+1,-1);
		}
	}
	while(q--){
		scanf("%d%d",&px,&py);
		printf("%d\n",t[px].ask(py));
	}
	return 0;
}
