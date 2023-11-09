#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
const int INF=0x3f3f3f3f;
int k,len,q,Hash1[maxn],pw[maxn],pos[maxn];
char s[maxn],t[maxn];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	std:ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>k;
	cin>>s+1;
	len=strlen(s+1);
	for(int i=1;i<=len;i++)Hash1[i]=Hash1[i-1]*131+s[i]-'a'+1;
	pw[0]=1;
	for(int i=1;i<=len;i++)pw[i]=pw[i-1]*131;
	cin>>q;
	for(int i=1;i<=q;i++){
		int n;
		int ans=0;
		cin>>t+1;
		n=strlen(t+1);
		for(int i=1;i<=n;i++)pos[i]=pos[i-1]*131+t[i]-'a'+1;
		for(int i=1;i<=len-n+1;i++){
			int l=1,r=n,L=-1,R=-1;
			while(l<=r){
				int mid=(l+r)/2;
				int v1=pos[mid];
				int v2=Hash1[i+mid-1]-Hash1[i-1]*pw[mid];
				if(v1==v2)l=mid+1;
				else r=mid-1,L=mid;
			}
			
			l=1,r=n;
			while(l<=r){
				int mid=(l+r)/2;
				int v1=pos[n]-pos[n-mid]*pw[mid];
				int ps=i+n-1;
				int v2=Hash1[ps]-Hash1[ps-mid]*pw[mid];
				if(v1==v2)l=mid+1;
				else r=mid-1,R=n-mid+1;
			}
			if(R==-1||(R-L)<k)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

