#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
const int mod=1e9+7;
int n; 
char s[maxn];
int ans=0;
int vis[1<<20];
queue<int> q;
inline void solve(){
	for(int i=0;i<(1<<n);i++) vis[i]=0; 
	int val=0;
	for(int i=1;i<=n;i++){
		val|=((s[i]-'0')<<(i-1));
	}
	q.push(val);
	vis[val]=1;
	ans++; 
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<n-1;i++){
			if((x>>i)&1 && (x>>(i+1))&1){
				if(i-1>=0 && !((x>>(i-1))&1) ){
					int y=x^(1<<(i+1))^(1<<(i-1));
					if(!vis[y]){
						q.push(y);
						vis[y]=1;
						ans++;
					}
				}
				if(i+2<=n-1&& !((x>>(i+2))&1)){
					int y=x^(1<<i)^(1<<(i+2));
					if(!vis[y]){
						q.push(y);
						vis[y]=1;
						ans++;
					}
				}
			}
		}
	}
}
inline void dfs(int now){
	if(now==n+1){
		solve();	
		return ;
	}
	if(s[now]=='0' || s[now]=='1'){
		dfs(now+1);
		return ;
	}
	s[now]='0';
	dfs(now+1);
	s[now]='1';
	dfs(now+1);
	s[now]='?';
}
int main(){
	freopen("jumpgo.in","r",stdin);
	freopen("jumpgo.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",s+1);
	bool f=1;
	for(int i=1;i<=n;i++){
		if(s[i]!='?') f=0;
	}
	if(n<=20){
		dfs(1);
		cout<<ans;
		return 0;
	} 
	return 0;
}
/*
010111
011101
110101
感觉无脑做不了。
必须靠点组合数技巧。
n<=20
枚举出初始状态。
直接跳？
2^5 2^20 感觉不是很大状压一下什么的就能过。 
*/
