#include<bits/stdc++.h>
using namespace std;
int rd(int x=0,char c=getchar()){int f=1;while(!isdigit(c))f=(c=='-'?1:-1),c=getchar();while(isdigit(c))x=x*10+c-48,c=getchar();return x*f;}
const int N=5e5+5;
int n,q,m;
vector<pair<int,int> >E[N]; 
int s,t,ans;
void dfs(int u,long long x){
	if(x>m)return;
	if(u==t)ans=ans>x?ans:x;
	for(auto v:E[u])dfs(v.first,x*v.second);
}
int main(){
	freopen("tour.in","r",stdin);
	freopen("tour.out","w",stdout);
	int p=clock();
	n=rd(),m=rd(),q=rd();
	for(int i=2;i<=m;i++){
		int u=rd(),v=rd();
		E[u].push_back({v,i});
		E[v].push_back({u,i});
	}
	while(q--){
		s=rd(),t=rd();
		ans=-1;dfs(s,1);
		printf("%d\n",ans);
	}
	cout<<clock()-p<<endl;
	return 0;
}

