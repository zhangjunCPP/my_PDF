#include<bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=2010;
int n,a[N],now[N],ans;
int get(int pos){
	if(now[pos+1]==now[pos]+1){
		int x=pos+1;
		while(now[x]==now[x-1]+1&&x<=n)++x;
		--x;return x;
	}else if(now[pos+1]==now[pos]-1){
		int x=pos+1;
		while(now[x]==now[x-1]-1&&x<=n)++x;
		--x;return x;
	}else return pos;
}
void dfs(int t,int s){
	if(t>n){
		if(s!=((1<<n)-1))return;
		for(int i=1;i<=n;++i){
			int j=get(i);
			for(int k=i;k<=j;++k)
				if(j-i+1!=a[k])return;
			i=j;
		}
		++ans;
	}
	for(int i=0;i<n;++i){
		if((s>>i)&1)continue;
		now[t]=i+1,dfs(t+1,(s|(1<<i)));
	}
}
int main(){
	freopen("gap.in","r",stdin);
	freopen("gap.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}
