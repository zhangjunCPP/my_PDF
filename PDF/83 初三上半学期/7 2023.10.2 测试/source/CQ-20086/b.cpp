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
int n,a[1000005],b[1000005],ans;
void dfs(int now,ll sum,int p){
	if(now>n){
		int num=0;
		for(int i=1;i<=p;i++){
			if(b[i]>sum/p)
				num++;
		}
		ans=max(ans,num);
		return ;
	}
	b[p+1]=a[now];
	dfs(now+1,sum+a[now],p+1);
	dfs(now+1,sum,p);
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	dfs(1,0,0);
	work(ans);
	return 0;
}
