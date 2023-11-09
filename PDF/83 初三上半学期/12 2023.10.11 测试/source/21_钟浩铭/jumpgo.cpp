#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=505;
const int mod=1e9+7;
inline void Freopen(){
	freopen("jumpgo.in","r",stdin);
	freopen("jumpgo.out","w",stdout);
} 
int n;
char s[MAXN],tmp[MAXN];
int ans;
map<string,bool> mp;
void dfs(int x){
	string t="";
//	cout<<"tmp: ";
	for(int i=1;i<=n;i++) t+=tmp[i];//,cout<<tmp[i];
//	printf("\n");
//	printf("x:%d\n",x);
	if(mp[t]) return ;
	ans++; ans%=mod; mp[t]=true;
	if(tmp[x]=='?'){
		tmp[x]='0'; dfs(x); tmp[x]='?';
		tmp[x]='1'; dfs(x); tmp[x]='?';
	}
	if(tmp[x-1]=='?'){
		tmp[x-1]='0'; dfs(x); tmp[x-1]='?';
		tmp[x-1]='1'; dfs(x); tmp[x-1]='?';
	}
	if(tmp[x+1]=='?'){
		tmp[x+1]='0'; dfs(x); tmp[x+1]='?';
		tmp[x+1]='1'; dfs(x); tmp[x+1]='?';
	}
	for(int i=x;i>=1;i--){
		if(tmp[i]!='1') break;
		if(tmp[i]=='1' && tmp[i-1]=='1' && tmp[i-2]=='0'){
			swap(tmp[i],tmp[i-2]); 
			dfs(i-1); 
			swap(tmp[i],tmp[i-2]);
		}
	}
//	if(tmp[x-1]=='1' && tmp[x-2]=='0'){
//		swap(tmp[x],tmp[x-2]); 
//		dfs(x-1); 
//		swap(tmp[x],tmp[x-2]);
//	}
	for(int i=x;i<=n;i++){
		if(tmp[i]!='1') break;
		if(tmp[i]=='1' && tmp[i+1]=='1' && tmp[i+2]=='0'){
			swap(tmp[i],tmp[i+2]);
			dfs(i+1);
			swap(tmp[i],tmp[i+2]); 
		}
	}
//	if(tmp[x+1]=='1' && tmp[x+2]=='0'){
//		swap(tmp[x],tmp[x+2]);
//		dfs(x+1); 
//		swap(tmp[x],tmp[x+2]);
//	}
	if(x<=1 || x>=n) return ;
	if(tmp[x-1]=='0') return ;
	if(tmp[x+1]=='0') return ;
	if(tmp[x-1]=='1' && tmp[x-2]=='1') return ;
	if(tmp[x+1]=='1' && tmp[x+2]=='1') return ;
}
signed main(){
	Freopen();
	scanf("%lld%s",&n,s+1);
//	dfs(4,4);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) tmp[j]=s[j];
		if(s[i]=='1' || s[i]=='?') mp.clear(),dfs(i);
	}
	printf("%lld",ans%mod);
	return 0;
}
/*
5
?0110

7
?100?10

7
0011100
*/
