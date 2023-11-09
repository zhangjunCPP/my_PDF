#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
inline void work(ll k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
ll n,a[200005],ans,vis[200005],sum;
bool f,f1;
stack<int> q;
vector<int> g,h;
void dfs(int k,ll val){
	if(k>n){
		if(ans<val){
			ans=val;
			g=h;
		}
		return ;
	}
	stack<int> p=q;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			ll sum=val;
			while(!q.empty()&&q.top()>i){
				sum+=a[i];
				q.pop();
			}
			vis[i]=1;
			h.emplace_back(i);
			q.emplace(i);
			dfs(k+1,sum);
			h.pop_back();
			vis[i]=0;
			q=p;
		}
	}
}
int main(){
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]!=i)
			f=1;
		if(a[i]!=n-i+1)
			f1=1;
	}
	if(!f){
		work(n*(n-1)/2);
		putchar('\n');
		for(int i=n;i;i--){
			work(i);
			putchar(' ');
		}
		return 0;
	}
	if(!f1){
		work(n*(n-1));
		putchar('\n');
		for(int i=2;i<=n;i++){
			work(i);
			putchar(' '); 
		}
		work(1);
		return 0;
	}
	if(n<=10){
		dfs(1,0);
		work(ans);
		putchar('\n');
		for(auto i:g){
			work(i);
			putchar(' ');
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans+=sum;
		sum=max(sum,a[i]);
	}
	work(ans);
	return 0;
}
