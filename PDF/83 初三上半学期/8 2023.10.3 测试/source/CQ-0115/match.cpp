#include<iostream>
using namespace std;
typedef long long ll;
const int N=1e3+5;
int n,m;
int a[N][N],nxt[N][N];
int cnt[N],req[N];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1,u,un;i<=n;i++){
		cin>>un;
		while(un--) 
			cin>>u,
			cnt[u]++,a[i][u]=1;
		for(int j=m;j>=1;j--)
			if(a[i][j]) nxt[i][j]=j;
			else nxt[i][j]=nxt[i][j+1];
	}
	for(int i=1;i<=m;i++){
		if(cnt[i]>1){
			int rem=0;
			for(int j=1;j<=n;j++)
				if(a[j][i]) {rem=i;break;}
			for(int j=1;j<=n;j++)
				if(j!=rem) a[j][i]=0,req[j]=i+1;
		}
		if(cnt[i]==0){
			for(int j=1;j<=n;j++)
				if(req[j]) a[j][i]=1,req[j]=0;
		}
	}
	for(int i=1;i<=n;i++)
		if(req[i]){cout<<-1;return 0;}
	for(int i=m;i>=1;i--){
		int rs=0;
		for(int j=1;j<=n;j++)
			if(a[j][i]){rs=1;break;}
		cout<<rs;
	}
	return 0;
}
/*

*/
