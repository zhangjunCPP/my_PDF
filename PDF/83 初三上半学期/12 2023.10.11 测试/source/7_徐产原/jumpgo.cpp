#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int p=1000000007;
int n,ans;
char s[505];
bool vis[1<<25];
int value(){
	int ans=0;
	for(int i=1;i<=n;i++)ans=ans*2+s[i]-'0';
	return ans;
}
void dfs2(){
	int x=value();
	if(vis[x])return;
	vis[x]=1;
	for(int i=1;i<=n;i++)if(s[i]=='1'){
		if(i+2<=n&&s[i+1]=='1'&&s[i+2]=='0'){
			swap(s[i],s[i+2]);
			dfs2();
			swap(s[i],s[i+2]);
		}
		if(i-2>=1&&s[i-1]=='1'&&s[i-2]=='0'){
			swap(s[i],s[i-2]);
			dfs2();
			swap(s[i],s[i-2]);
		}
	}
}
void dfs(int x){
	if(x==n+1){
		dfs2();
		for(int i=0;i<(1<<n);i++)ans+=vis[i],vis[i]=0;
		return;
	}
	if(s[x]!='?')return dfs(x+1);
	else{
		s[x]='1';dfs(x+1);
		s[x]='0';dfs(x+1);	
		s[x]='?';
	}
}

ll dp[505][505][2];

void Freopen(){
	freopen("jumpgo.in","r",stdin);
	freopen("jumpgo.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d%s",&n,s+1);
	if(n<=20){	
		dfs(1);
		printf("%d\n",ans);
	}
	else{
		int num=0;
		for(int i=1;i<=n;i++)num+=(s[i]=='1');
		dp[1][0][0]=dp[2][0][0]=dp[2][1][1]=1;
		for(int i=3;i<=n;i++){
			for(int j=0;j<=i/2;j++){
				dp[i][j][0]=(dp[i-1][j][1]+dp[i-2][j][1]+dp[i-2][j][0])%p;
				if(j)dp[i][j][1]=dp[i-2][j-1][0];
			}
		}
		for(int i=0;i<=n;i+=2)
			ans=(ans+dp[n-(num-i)-1][i/2][1]+dp[n-(num-i)-1][i/2][0])%p;
		printf("%d\n",ans);
	}
}
/*
20
11111111110000000000
*/
