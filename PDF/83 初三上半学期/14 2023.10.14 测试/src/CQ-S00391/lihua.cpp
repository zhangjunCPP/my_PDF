#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=1e5+10;
string s[maxn],str;
int n,q;
signed main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i];
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>str;
		int tmp=0;
		for(int j=1;j<=n;j++){
			bool f=1;
			for(int k=0;k<min(s[j].size(),str.size());k++){ 
			 tmp++;
			 if(s[j][k]!=str[k]){f=0;break;}
			}
			if(f){tmp++;if(s[j].size()==str.size())break;}
		}
		cout<<tmp<<endl;
	}
	return 0;
}
