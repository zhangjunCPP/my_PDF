#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
int n,cnt;
int s[12],vis[12];
int t[12];
int ok;
stack<int>s1,s2;
void dfs1(int nowr,int x){
//	cout<<nowr<<x<<endl;
//	for(int i=1;i<=n;i++)cout<<s[i]<<' ';/e()<<' '<<s2.size()<<endl;
	if(ok)return;
	if(nowr==0){
		ok=1;
		return;
	}
	if(s2.size()&&s2.top()==nowr){
		int q=s2.top();
		s2.pop();
		dfs1(nowr-1,x);
		s2.push(q);
		return;
	}
	if(x!=n+1){
		if(s1.empty()||s[x]<s1.top()){
			s1.push(s[x]);
			dfs1(nowr,x+1);
			if(ok)return;
			s1.pop();
		}
	}
	if(s1.size()){
		s2.push(s1.top());
		int q=s1.top();
		s1.pop();
		dfs1(nowr,x);
		if(ok)return;
		s2.pop();
		s1.push(q);
	}
}
void dfs(int x){
	if(x==n+1){
//		stack<int> s1,s2;
//		int nowr=n;
//		for(int i=1;i<=n;i++){
		/*	if(s1.empty()||s[i]<s1.top()){
				s1.push(s[i]);
				while(s1.size()&&s1.top()==nowr)s1.pop(),nowr--;
				while(s2.size()&&s2.top()==nowr)nowr--,s2.pop();
				while(s1.size()&&s1.top()==nowr)s1.pop(),nowr--;
				while(s2.size()&&s2.top()==nowr)nowr--,s2.pop();
			}
			else{
				while(s1.size()){
					s2.push(s1.top());
//					if(s1.top()==nowr)nowr--,s2.pop();
					while(s2.size()&&s2.top()==nowr)nowr--,s2.pop();
					s1.pop();
				}s1.push(s[i]);
				while(s1.size()&&s1.top()==nowr)s1.pop(),nowr--;
				while(s2.size()&&s2.top()==nowr)nowr--,s2.pop();
				while(s1.size()&&s1.top()==nowr)s1.pop(),nowr--;
				while(s2.size()&&s2.top()==nowr)nowr--,s2.pop();
			}
		}
		while(s1.size()&&s1.top()==nowr)s1.pop(),nowr--;
		while(s2.size()&&s2.top()==nowr)nowr--,s2.pop();
		while(s1.size()&&s1.top()==nowr)s1.pp(),nowr--;
		while(s2.size()&&s2.top()==nowr)nowr--,-s2.pop();
		if(nowr==0){
			for(int i=1;i<=n;i++)cout<<s[i]<<' ';cout<<endl;
		}*/
		while(s1.size())s1.pop();
		while(s2.size())s2.pop();
		ok=0;dfs1(n,1);
		cnt+=ok;
		t[s[1]]+=ok;
//		if(ok){
//			for(int i=1;i<=n;i++)cout<<s[i]<<' ';
//			cout<<endl;
//		}
	}for(int i=1;i<=n;i++)if(!vis[i]){
		s[x]=i;vis[i]=1;
		dfs(x+1);
		vis[i]=0;
	}
}
const int N=5005;
using ll=long long;
ll f[N][N],jc[N],sum[N];
int main(){
//	freopen("sort.in","r",stdin);
//	freopen("sort.out","w",stdout);
	jc[0]=1;
	for(int i=4;i<=10;i++){
		n=i;for(int j=1;j<=i;j++)t[j]=0;
		dfs(1);
		for(int j=1;j<=n;j++)f[i][j]=t[j],sum[i]+=t[j];
	}
//	f[4]=2,f[5]=30,f[6]=326,f[7]=3234,f[8]=31762;
	int t=rd();
	while(t--){
		n=rd();
		ll mod=rd();
		for(int i=1;i<=n;i++)jc[i]=jc[i-1]*i%mod;
//		ll sum=0;
		for(int i=9;i<=n;i++){
			f[i][1]=f[i][n]=f[i][n-1]=sum[i-1];
			for(int j=2;j<=(i-1)/2;j++)f[i][j]=sum[i-j]*(jc[j]-sum[j])%mod;
			for(int j=(i-1)/2+1;j<i-1;j++)f[i][j]=f[i][n-j];
		}printf("%lld\n",sum[n]);
	}
//	cin>>n;
//	dfs(1);
//	cout<<cnt<<endl;
//	for(int i=1;i<=n;i++)cout<<t[i]<<' ';
	return 0;
}
/*
4     5     6     7     8     9      10
2     30    326   3234  31762 321294 3422702
22    90    394   1806  8558  41586  206098
*/
