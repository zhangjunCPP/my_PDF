#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 +5 ;
int n,q;
string s[N];
int main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	cin>>q;
	for(int i=1;i<=q;i++){
		string s1;
		cin>>s1;
		int ans=0,p=n;
		for(int j=1;j<=n;j++)
		if(s[j]==s1)p=j;
		ans+=p;
		for(int j=1;j<=p;j++){
			for(int k=0;k<s[j].size();k++){
				if(s[j][k]!=s1[k])break;
				else ans++;
			}
		}
		cout<<ans<<endl; 
	}
	return 0;
}
/*
ÎÒÊÇsb
×ÖµäÊ÷¶¼²»»á 
×ÖµäÊ÷ÔõÃ´´ò
°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡
°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡
°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡
*/
