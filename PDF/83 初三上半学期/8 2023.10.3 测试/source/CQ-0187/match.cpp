#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int ans[N],vis[N];
vector<int>a[N];
void solve1(int n,int m){
	if(n==1){
		for(int x:a[1]){
			ans[x]=1;
		}
		for(int i=m;i;i--)printf("%d",ans[i]);
		return;
	}
	if(!a[2].size())swap(a[2],a[1]);
	if(!a[1].size()){
		for(int x:a[1]){
			ans[x]=1;
		}
		for(int i=m;i;i--)printf("%d",ans[i]);
		return;
	}
	if(a[2].back()<a[1].back())swap(a[2],a[1]);
	int op=0;
	for(int x:a[1])vis[x]=1;
	for(int i=1;i<=a[1].back();i++)if(!vis[i]){op=i;break;}
	if(op){
		for(int i=a[1].back();i>=op;i--)ans[i]=vis[i];
		ans[op]=1;
	}else{
		if(a[1].back()==m){cout<<-1;return;}
	}
	
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		for(int j=1;j<=x;j++){
			int y;
			scanf("%d",&y);
			a[i].push_back(y);
		}
	}
	//if(n<=2){solve1(n,m);return 0;}
	cout<<-1;
	return 0;
}
