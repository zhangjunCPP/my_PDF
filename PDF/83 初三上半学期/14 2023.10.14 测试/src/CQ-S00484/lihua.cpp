#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
string s[100001],q[100001];
signed main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	cin>>m;
	if(n<=3000){
		for(int i=1;i<=m;i++){
			cin>>q[i];
			int ans=0,ff=0;
			for(int j=1;j<=n;j++){
				int val=0,f=0;
				for(int k=0;k<s[j].size();k++){
					val++;
					if(s[j][k]!=q[i][k]){
						f=1;
						break;
					}
				}
				ans+=val;
				if(!f){
					ans++;
					if(q[i].size()==s[j].size()){
						cout<<ans<<endl;
						ff=1;
						break;
					}
				}
			}
			if(!ff) cout<<ans<<endl;
		}
	}
	return 0;
}

