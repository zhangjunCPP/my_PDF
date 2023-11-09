//the code is from chenjh
#include<cstdio>
#include<bitset>
#include<vector>
#define MAXN 500005
typedef std::bitset<22> B;
using std::vector;
int n;
int a[MAXN],g[MAXN];
B t[MAXN][20];
inline B query(int l,int r){
	int k=g[r-l+1];
	return t[l][k]|t[r-(1<<k)+1][k];
}
int mex(int l,int r){B ret(query(l,r));return ret.flip()._Find_first();}
int ans=0;vector<int> av;
void dfs(int pos,int s,vector<int>&v){
	if(pos>n){
		if(s>ans) ans=s,av=v;
		return;
	}
	v.push_back(pos);
	for(int i=1,mi=mex(pos,n),j=pos;i<=mi;i++){
		for(;j<=n && mex(pos,j)<i;j++);
		if(j>n) break;
		if(mex(pos,j)==i)
			/*printf("%d -> %d\n",pos,j),*/dfs(j+1,s+i,v);
	}
	if(s>ans)dfs(n+1,s,v);
	v.pop_back();
}
int main(){
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);
	scanf("%d",&n);
	bool fl=1;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),t[i][0][a[i]]=1,fl&=a[i]>0;
	if(fl) return puts("0 1\n1"),0;
	for(int i=2;i<=n;i++) g[i]=g[i>>1]+1;
	for(int k=1;k<=g[n];k++)for(int i=1,mi=n+1-(1<<k);i<=mi;i++)t[i][k]=t[i][k-1]|t[i+(1<<(k-1))][k-1];
	vector<int> v;v.clear();
	dfs(1,0,v);
	printf("%d %d\n",ans,(int)av.size());
	for(int x:av) printf("%d ",x);
	return 0;
}

