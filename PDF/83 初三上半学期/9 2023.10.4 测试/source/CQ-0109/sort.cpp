#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
const int N=2e5+10;
const ll INF=2e18;
void File(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
}
int n,mod;
int check(stack<int>q){
	
	stack<int>A,B;
	
	int u=1;
	while(q.size()){

		if(A.empty()){
			A.push(q.top());
			q.pop();
		}
		else if(A.top()>q.top()){
			A.push(q.top());
			q.pop();	
		}
		else if(B.size()&&B.top()==u){
			u++;
			B.pop();
		}
		else if(B.empty()){
			B.push(A.top());
			A.pop();
		}
		else if(A.top()<B.top()){
			B.push(A.top());
			A.pop();
		}
		else return 0;
	}
	return 1;
}
int vis[1001],ans=0;
void dfs(int x,stack<int>a){
	stack<int>co=a;
	
	if(x==n){
		int vv[100]={0};
		
		if(check(a)==0){
			while(a.size()){
//				cout<<a.top()<<' ';
				a.pop();
			}
//			cout<<endl;
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		a.push(i);
		vis[i]=1;
		dfs(x+1,a);
		vis[i]=0;
		a=co;
	}
}
int dp[N]={0};
int main(){
	File();
	int  t;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n>>mod;
		stack<int>a;
		dfs(0,a);
		cout<<ans<<endl;
	}
} 
