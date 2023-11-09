#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
const int INF=0x3f3f3f3f;
int n,q;
char s[35];
map<int,string>mp;
map<int,int>all;
void solve1(){
	int i,j,len,v,id,x;
	long long ans;
	for(i=1;i<=n;i++){
		cin>>s+1;
		len=strlen(s+1);
		v=0;
		for(j=1;j<=len;j++){
			v=v*131+s[j]-'a'+1;
			mp[v].push_back(i);
		}
		if(!all[v])all[v]=i;
	}
	cin>>q;
	for(i=1;i<=q;i++){
		cin>>s+1;
		len=strlen(s+1);
		v=0;ans=0;
		for(j=1;j<=len;j++)v=v*131+(s[j]-'a'+1);
		if(all[v]){
			ans=all[v];id=all[v];
			v=0;
			for(j=1;j<=len;j++){
				v=v*131+(s[j]-'a'+1);
				if(mp[v][mp[v].size()-1]<=id)ans=ans+mp[v].size();
				else{
					x=upper_bound(mp[v].begin(),mp[v].end(),id)-mp[v].begin()-1;
					ans=ans+x+1;
				}
			}
		}
		else{
			ans=n;v=0;
			for(j=1;j<=len;j++){
				v=v*131+(s[j]-'a'+1);
				ans+=mp[v].size();
			}
		}
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	solve1(); 
	return 0;
}

