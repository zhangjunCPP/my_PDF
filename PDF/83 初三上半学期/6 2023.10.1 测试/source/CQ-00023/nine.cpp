#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=20;
int k,x,y,ans=1e6,vis[N][N];
stack<PII> stk,res;
bool check(int x,int y){
	if(x<0||x>20||y<0||y>20||vis[x][y])return false;
	return true;
}
void dfs(int x,int y,int step){
	if(abs(x-10)+abs(y-10)==k){stk.push({0,0}),dfs(10,10,step+1);return;}
	if(step>=ans)return;
	vis[x][y]=1;
	if(x==10&&y==10){
		ans=min(ans,step),res=stk;return;
	}
	for(int i=0;i<=k;++i){
		if(check(x+i,y+k-i))stk.push({x+i-10,y+k-i-10}),dfs(x+i,y+k-i,step+1),stk.pop();
		if(check(x+i,y-k+i))stk.push({x+i-10,y-k+i-10}),dfs(x+i,y-k+i,step+1),stk.pop();
		if(check(x-i,y+k-i))stk.push({x-i-10,y+k-i-10}),dfs(x-i,y+k-i,step+1),stk.pop();
		if(check(x-i,y-k+i))stk.push({x-i-10,y-k+i-10}),dfs(x-i,y-k+i,step+1),stk.pop();
	}
}
int main(){
	freopen("nine.in","r",stdin);
	freopen("nine.out","w",stdout);
	k=read(),x=read(),y=read();
	dfs(x+10,y+10,0);
	printf("%d\n",ans);
	while(stk.size()){
		printf("%d %d\n",stk.top().first,stk.top().second);
		stk.pop();
	}
	return 0;
}
