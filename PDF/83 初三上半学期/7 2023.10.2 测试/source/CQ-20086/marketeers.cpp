#include<bits/stdc++.h>
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
int n,k[500005],ans,val[500005];
vector<int> s[500005],b;
void dfs(int now){
	if(now>n){
		vector<int> g;
		for(int i=1;i<=n;i++){
			int sum=0;
			for(int j=i+1;j<=n;j++){
				sum+=(val[j]<val[i]);
			}
			g.emplace_back(sum);
		}
		if(g>b){
			b=g;
			ans=1;
		}
		else if(g==b)
			ans++;
		return ;
	}
	for(int i=1;i<=k[now];i++){
		val[now]=s[now][i-1];
		dfs(now+1);
	}
}
int main(){
	freopen("marketeers.in","r",stdin);
	freopen("marketeers.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		b.emplace_back(0);
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			s[i].emplace_back(read());
		}
		sort(s[i].begin(),s[i].end());
	}
	dfs(1);
	work(ans);
	return 0;
}
