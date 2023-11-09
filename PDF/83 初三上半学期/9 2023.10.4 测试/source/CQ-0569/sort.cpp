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
inline void work(int k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
/*
感觉有很多性质 
在n进入s1时,所有数都应当在s2
算合法的情况
递减后一直递增,或者一直递减是合法的
或者说最后有一个后缀是1~i,几个合法序列拼起来也是可以的 
*/
int t,n,p,vis[5000005],a[5000005],flag[5000005];
ll ans;
stack<int> q,p1;
void dfs(int now){
	if(now>n){
		for(int i=1;i<=n;i++){
			flag[i]=0;
		}
		for(int i=1;i<=n;i++){
			if(a[i]!=i)
				break;
			flag[i]=1;
		}
		int f=0,now1=n;
		for(int i=n;i;i--){
			if(f==1){
				if(!p1.empty()&&a[i]<p1.top()){
					ans++;
					ans%=p;
					return ;
				}
				if(a[i]!=now1)
					p1.emplace(a[i]);
				else
					now1--;
				while(!p1.empty()&&p1.top()==now1){
					now1--;
					p1.pop();
				}
			}
			else if(q.empty()||a[i]<q.top())
				q.emplace(a[i]);
			else{
				while(!q.empty()){
					p1.emplace(q.top());
					q.pop();
				}
				if(a[i]<p1.top()&&!flag[i]){
					ans++;
					ans%=p;
					return ;
				}
				else if(flag[i])
					return ;
				else
					f=1;
				if(a[i]==now1){
					now1--;
					while(!p1.empty()&&p1.top()==now1){
						now1--;
						p1.pop();
					}
				}
				else
					p1.emplace(a[i]);
			}
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[now]=i;
			dfs(now+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		p=read();
		ans=0;
		dfs(1);
		work(ans);
		putchar('\n');
	}
	return 0;
}
