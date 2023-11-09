#include<bits/stdc++.h> 
using namespace std;
int n,m;
int vis[1000005];
vector<int> p[3];
void Freopen(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d%d",&n,&m);
	for(int i=0,len,x;i<n;i++){
		scanf("%d",&len);
		while(len--){
			scanf("%d",&x);
			p[i].push_back(x);
		}
		sort(p[i].begin(),p[i].end(),[](int a,int b){return a>b;});
	}
	if(n==1){
		for(int x:p[0])vis[x]=1;
		for(int i=1;i<=m;i++)printf("%d",vis[i]);
	}
	else if(n==2){
		for(int i=0,j=0;i<p[0].size();i++){
			for(;j<p[1].size()&&p[1][j]>p[0][i];j++)vis[p[1][j]]=1;
			if(p[1][j]==p[0][i]){
				string a,b;
				for(int k=i;k<p[0].size();k++)a+=p[0][k];
				for(int k=j;k<p[1].size();k++)b+=p[1][k];
				if(a<b){
					for(int k=i;k<p[0].size();k++)vis[p[0][k]]=1;
				}
				else{
					for(int k=j;k<p[1].size();k++)vis[p[1][k]]=1;
				}
				int x=p[1][j];
				for(int i=x+1;i<m;i++)if(!vis[i])vis[i]=1;
				for(int i=0;i<m;i++)printf("%d",vis[i]);
				return 0;
			}
			vis[p[0][i]]=1;
		}
		for(int i=0;i<m;i++)printf("%d",vis[i]);
	}
}
