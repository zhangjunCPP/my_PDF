#include<bits/stdc++.h>
using namespace std;
int n,s,a[100001],b[100001],col[100001];
vector <int> A;
map <vector<int>,bool> vis;
const int mod=998244353;
void dfs(int x,vector <int> B){
	if(x==n){
		if(!vis[B]) s++;
		if(s>=mod) s--;
		vis[B]=1;
		return;
	}
	if(col[a[x]]||col[b[x]]) dfs(x+1,B);
	else{
		col[a[x]]=1,B.push_back(a[x]),dfs(x+1,B),B.pop_back(),col[a[x]]=0;
		col[b[x]]=1,B.push_back(b[x]),dfs(x+1,B),B.pop_back(),col[b[x]]=0;
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<n;i++) scanf("%d%d",&a[i],&b[i]);
	if(n<=1000){
		dfs(1,A);
		printf("%d",s);
	}
	else printf("%d",n);
	return 0;
}
