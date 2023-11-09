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
int n,k,ans[255],dp[45][2],a[45];
void dfs(int now){
	if(now>n){
		
		return ;
	}
	a[now]=1;
	dfs(now+1);
	a[now]=0;
	dfs(now+1);
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();
	k=read();
	for(int i=1;i<=k;i++){
		if(rand()&1)
			work(rand()%(n+1));
		else 
			work(0);
		putchar(' ');
	}
	return 0;
}
