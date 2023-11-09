//the code is from chenjh
#include<bits/stdc++.h>
#define MAXN 2005
using namespace std;
int p,k,n;
int qpow(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*a)if(b&1)r*=a;
	return r;
}
vector<vector<int> > ans;
void dfs(vector<vector<int> >&w){
//	for(const vector<int>&e:w){
//		for(const int x:e) printf("%d ",x);
//		putchar('\n');
//	}
	int l=w.size();
	vector<vector<int> > v;
	v.resize(l);
	for(int i=0;i<l;i++) v[i].resize(p);
	for(int _=0;_<l;_++){
		for(const vector<int>&e:w) ans.emplace_back(e);
		for(int i=0;i<l;i++)for(int j=0;j<p;j++) v[i][j]=w[(i+j)%l][j];
		w=v;
	}
	if(l==1) return;
	vector<vector<int> > nx;
	for(int j=0;j<p;j++){
		nx.clear();
		vector<int> tmp;
		for(int i=0;i<l;i+=p){
			tmp.clear();
			for(int k=0;k<p;k++) tmp.emplace_back(w[i+k][j]);
//			ans.emplace_back(tmp);
			nx.emplace_back(tmp);
		}
		dfs(nx);
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&p,&k);
	n=qpow(p,k);
//	for(int i=0;i<n;i++){
//		if(i && !(i%p)) putchar('\n');
//		printf("%d ",i);
//	}
	vector<vector<int> > w;
	w.resize(n/p);
	for(int i=0,mi=n/p,t=0;i<mi;i++){
		w[i].resize(p);
		for(int j=0;j<p;j++) w[i][j]=t++;
	}
	dfs(w);
	printf("%zu\n",ans.size());
	for(const vector<int>&e:ans){
		for(const int x:e) printf("%d ",x);
		putchar('\n');
	}
//	fprintf(stderr,"size: %zu\n",sizeof ans);
	return 0;
}

