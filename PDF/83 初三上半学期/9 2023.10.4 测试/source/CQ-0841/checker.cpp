#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define i64 __int128
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define lowbit(i) i&(-i)
int tot,len,a[100000][10],vis[2007][2007];
int main(){
//	freopen("chess.out","r",stdin);
//	freopen(".out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> tot >> len;
	for(int i=1;i<=tot;i++){
		for(int j=1;j<=len;j++){
			cin >> a[i][j];
		}
	}
	for(int i=1;i<=tot;i++){
		for(int j=1;j<=len;j++){
			for(int k=1;k<=len;k++){
				if(j==k) continue;
				if(vis[a[i][j]][a[i][k]]){
					cout << "Wrong answer:" << i <<" " << a[i][j] << ' ' << a[i][k] << " " << j << " " << k << "\n";
					return 0;
				}
				vis[a[i][j]][a[i][k]] = 1;
			}
		}
	}
	return 0;
}
