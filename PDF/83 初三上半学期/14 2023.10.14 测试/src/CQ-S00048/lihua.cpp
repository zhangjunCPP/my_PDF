#include <bits/stdc++.h>
using namespace std;
const int MOD=99999989;
long long nhash[35],hhash[100005][35];
int cnt[100005];
char s[35];
int find(int len,int c){
	int l=0,r=min(cnt[c],len),ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(nhash[mid]==hhash[c][mid]) ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	int n,q;
	cin>>n;
	for(int i=1;i<=n;i++){
		memset(s,0,sizeof(s));
		cin>>s+1;
		cnt[i]=strlen(s+1);
		for(int j=1;j<=cnt[i];j++)
			hhash[i][j]=(hhash[i][j-1]*26+s[j]-'a')%MOD;
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		memset(s,0,sizeof(s));
		cin>>s+1;
		int len=strlen(s+1),ans=0;
		for(int j=1;j<=len;j++)
			nhash[j]=(nhash[j-1]*26+s[j]-'a')%MOD;
		for(int j=1;j<=n;j++){
			int u=find(len,j);
			ans+=u+1;
			if(u==len&&len==cnt[j]) break;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
