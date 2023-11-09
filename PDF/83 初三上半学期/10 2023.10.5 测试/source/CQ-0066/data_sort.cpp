#include<bits/stdc++.h>
using namespace std;
int n=1e3;
bool vis[1000000];
int main(){
	srand(time(0));
//	freopen(".in","r",stdin);
	freopen("sort.in","w",stdout);
	cout<<n<<endl;
	for(int i=1;i<=n;++i){
		int t=1ll*rand()*rand()%n+1;
		while(vis[t]) t=1ll*rand()*rand()%n+1;
		cout<<t<<endl,vis[t]=true;
	}

	return 0;
}
