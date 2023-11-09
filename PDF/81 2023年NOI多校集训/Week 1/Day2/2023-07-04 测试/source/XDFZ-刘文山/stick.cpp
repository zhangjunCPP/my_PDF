#include<bits/stdc++.h>
using namespace std;
int n,m,q;
bool dp[51][5005];
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>q;
	while(q--){
		cin>>n>>m;	
		memset(dp,0,sizeof dp);
		dp[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<i;j++){
				for(int k=0;k<=(m<<1);k++){
					int cnt=i-j;
					if(k+cnt*(n-cnt)<=(m<<1)){
						dp[i][k+cnt*(n-cnt)]|=dp[j][k];
					}
				}
			}
		}
		cout<<dp[n][m<<1]<<endl;
	}
	return 0;
} 
